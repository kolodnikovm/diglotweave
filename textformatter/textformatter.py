""" Module Docs """


import re
import csv
import os.path
import pymorphy2 as pm2
from WordInflect.inflectwords import InflectWords

SCRIPT_PATH = os.path.dirname(__file__)
print(SCRIPT_PATH)
FILE_NAME = os.path.join(SCRIPT_PATH, 'Assets//text.txt')
VOCAB = {
    "see": "видеть",
    "it": "это",
    "think": "думать"
}

class TextFormatter:
    """ TextFormatter documentation """

    def __init__(self, text, vocab):
        """ Init Docs """

        self.text_file = open(text, "r", encoding='utf-8')
        self.vocab = vocab
        self.morph = pm2.MorphAnalyzer()
        self.inflector = InflectWords()

    def get_text_words(self):
        """ Возвращает первое слово из текстового файла класса в lower case"""

        for line in self.text_file:
            for word in re.findall(r'\w+', line):
                yield word.lower()
        self.text_file.close()

    def get_eng_word(self, normal_word):
        """ Возвращает английское слово из словаря, соовтетствующее данному переводу """

        return list(self.vocab.keys())[list(self.vocab.values()).index(normal_word)]

    def find_words_by_translate(self):
        """ Находит все слова, перевод которых содержится в словаре """

        result = {}
        vocab_translates = list(map(str.lower, list(self.vocab.values())))

        for word_from_text in self.get_text_words():

            text_word_normal_form = self.morph.parse(word_from_text)[0].normal_form
            text_word_tag = self.morph.parse(word_from_text)[0].tag

            if text_word_normal_form in vocab_translates:
                eng_word = self.get_eng_word(text_word_normal_form)
                if eng_word in result.keys() and not word_from_text in result[eng_word]:
                    result[eng_word].append(word_from_text)
                else:
                    result.update({eng_word:[word_from_text]})

        return result

    def save_to_csv(self):
        """ Сохраняет результат работы функции  find_words_by_translate() в csv"""
        with open(SCRIPT_PATH + '//Assets///words_to_swap.csv', 'w+', newline='', encoding='utf-8') \
                                                                            as result_dict:
            print(result_dict.name) #Залогировать!
            writer = csv.writer(result_dict)
            words_to_swap = self.find_words_by_translate()
            for eng_word in words_to_swap:
                for word in words_to_swap[eng_word]:
                    writer.writerow([word, eng_word])

TF = TextFormatter(FILE_NAME, VOCAB)
TF.save_to_csv()
