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


def inflect_verb(verb, tag):
    """ Переводит глагол в форму, согласно tense, pers, numb """

    tense, pers, numb = tag.tense, tag.person, tag.number

    if verb in IRREGULAR_VERBS:
        if tense == 'past':
            return IRREGULAR_VERBS[verb][1]
        elif tense == 'pres':
            if pers == '3per' and numb == 'sing':
                if IRREGULAR_VERBS[verb][0].endswith(('s', 'x', 'z', 'ch', 'sh')):
                    return IRREGULAR_VERBS[verb][0] + 'es'
                return IRREGULAR_VERBS[verb][0] + 's'
            return IRREGULAR_VERBS[verb][0]
        elif tense == 'futr':
            return '(will)' + IRREGULAR_VERBS[verb][0]
        return IRREGULAR_VERBS[verb][0]
    else:
        # TODO уточнить правила постановки в прошедшее
        if tense == 'past':
            if verb[-1] in VOWELS or (verb[-1] in CONSONANTS and verb[-1] != 'x'):
                return verb + 'd'
            elif verb[-2] in CONSONANTS and verb[-1] == 'y':
                return verb[:-1] +'ied'
            return verb + 'ed'
        elif tense == 'futr':
            return '(will) ' + verb
        elif tense == 'pres':
            if pers == '3per' and numb == 'sing':
                if verb.endswith(('s', 'x', 'z', 'ch', 'sh')):
                    return verb + 'es'
                return verb + 's'
            return verb
        return verb

def inflect_noun(noun, tag):
    number = tag.number
    # TODO уточнить про ножницы, качели и пр. множественные и irregular nouns
    if number == 'plur':
        if noun.endswith(('s', 'x', 'z', 'ch', 'sh')):
            return noun + 'es'
        elif noun.endswith('y'):
            return noun[:-1] + 'ies'
        return noun + 's'
    return noun
