import csv
import os.path

FILE_PATH = os.path.join(os.path.dirname(__file__), 'irregular_verbs.csv')
IRREGULAR_VERBS = {}
CONSONANTS = [
    'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm',
    'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y'
]
VOWELS = ['a', 'e', 'i', 'o', 'u']

with open(FILE_PATH, 'r', newline='') as iv:
    for row in csv.reader(iv):
        IRREGULAR_VERBS.update({row[0]: row})


def inflect_verb(verb, tense, number):
    """ Переводит глагол в форму, согласно tense и number """

    if verb in IRREGULAR_VERBS:
        if tense == 'past':
            return IRREGULAR_VERBS[verb][1]
        elif tense == 'pres':
            return IRREGULAR_VERBS[verb][0]
        elif tense == 'futr':
            return '(will)' + IRREGULAR_VERBS[verb][0]
        return IRREGULAR_VERBS[verb][0]
    else:
        # TODO уточнить правила постановки в прошедшее
        if tense == 'past':
            if verb[-1] in VOWELS:
                return verb + 'd'
            elif verb[-1] in CONSONANTS:
                return verb + 'ed'
        elif tense == 'futr':
            return '(will) ' + verb
        elif tense == 'pres':
            # TODO перелать форму глагола под лица
            return verb


def inflect_noun(noun, number):
    # TODO уточнить про ножницы, качели и пр. множественные и irregular nouns
    if number == 'plur':
        if noun.endswith(('s', 'x', 'z', 'ch', 'sh')):
            return noun + 'es'
        elif noun.endswith('y'):
            return noun[:-1] + 'ies'
        return noun + 's'
    return noun

if __name__ == '__main__':
    print('test nouns')
    print(inflect_noun('actress', 'plur'))
    print(inflect_noun('boy', 'plur'))
    print('\ntest verbs')
    print(inflect_verb('run', 'past', 'plur'))
    print(inflect_verb('draw', 'past', 'plur'))
    print(inflect_verb('jump', 'pres', 'sing'))