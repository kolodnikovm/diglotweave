""" Переводит слова на англ. в нужную форму """
from .Rules.rules import inflect_verb

class InflectWords:

    def __init__(self):
        self.inflect_verb = inflect_verb

    def inflect_word(self, word, tag):
        if type == 'VERB':
            self.inflect_verb()