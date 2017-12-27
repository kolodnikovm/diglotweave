""" Module Docs """

import re
import csv
import pymorphy2 as pm2
from .Wordinflector.inflector import Inflector


class TextFormatter:
    """ TextFormatter documentation """

    def __init__(self, text, vocab):
        self.text_file = open(text, "r", encoding='utf-8')
        self.vocab = vocab
        self.morph = pm2.MorphAnalyzer()
        self.inflector = Inflector()

    def get_text_words(self):
        """ Возвращает первое слово из текстового файла класса в lower case"""

        for line in self.text_file:
            for word in re.findall(r'\w+', line):
                yield word.lower()
        self.text_file.close()

    def get_eng_word(self, normal_word):
        """ Возвращает английское слово из словаря, соовтетствующее данному переводу """

        return list(self.vocab.keys())[list(self.vocab.values()).index(normal_word)]

    def generate_words_to_swap(self):
        """ Находит все слова, перевод которых содержится в словаре """

        result = {}

        # получает список всех переводолв слов
        vocab_translates = list(map(str.lower, list(self.vocab.values())))

        # проходит по каждому слову из текста
        for word_from_text in self.get_text_words():

            # получает номальную форму слова из текста и лексичеескую инфу о нем
            parsed_word = self.morph.parse(word_from_text)[0]
            text_word_normform = parsed_word.normal_form
            tags = parsed_word.tag

            # если нормальная форма слова есть перевод английского слова
                # то находит такое английское слово в словаре
                # смотрит, есть ли оно в рез. словаре и нет ли за ним слова из текста
                    # если да, то записывает за англ. словом новое слово из текста
                    # если нет, то в рез. словаре появляется новое англ. слово
            if text_word_normform in vocab_translates:

                # склоняет англ. слово согласно как в оригинальном тексте на русском
                eng_word = self.inflector.inflect_word(self.get_eng_word(text_word_normform), tags)

                if eng_word in result.keys() and not word_from_text in result[eng_word]:
                    result[eng_word].append(word_from_text)
                else:
                    result.update({eng_word:[word_from_text]})
        return result

    def save_to_csv(self, path_name):
        """ Вызывает generate_words_to_swap() и сохраняет результат работы функции в csv """

        with open(path_name, 'w+', newline='', encoding='utf-8') as result_dict:
            writer = csv.writer(result_dict)
            words_to_swap = self.generate_words_to_swap()
            print(words_to_swap)
            for eng_word in words_to_swap:
                for word in words_to_swap[eng_word]:
                    writer.writerow([word, eng_word])
