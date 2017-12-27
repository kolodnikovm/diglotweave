""" Переводит слова на англ. языке в нужную форму """

from .Rules.rules import inflect_verb, inflect_noun

class Inflector:

    def __init__(self):
        self.inflect_verb = inflect_verb
        self.inflect_noun = inflect_noun

    def inflect_word(self, word, tag):
        pos = tag.POS

        if pos == 'VERB' or pos == 'INFN':
            return self.inflect_verb(word, tag)
        elif pos == 'NOUN':
            return self.inflect_noun(word, tag)
        
        return word
        