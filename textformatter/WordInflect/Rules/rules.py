import csv
import os.path

FILE_PATH = os.path.join(os.path.dirname(__file__), 'irregular_verbs.csv')
IRREGULAR_VERBS = {}
IV_FORMS = {}

with open(FILE_PATH, 'r', newline='') as iv:
    for row in csv.reader(iv):
        IRREGULAR_VERBS.update({row[0]: row})

def inflect_verb(verb, to_form):
    """ to_form должен быть список вида ['tense','number']. Пока tense only.
    verb должен быть начальной формой слова в англ. языке """
    if verb in IRREGULAR_VERBS:
        if to_form[0] == 'past': return IRREGULAR_VERBS[verb][1]
        elif to_form[0] == 'pres': return IRREGULAR_VERBS[verb][0]
        elif to_form[0] == 'futr': return '(will)' + IRREGULAR_VERBS[verb][0]
    else:
        return IRREGULAR_VERBS[verb][0]

if __name__ == '__main__':
    print(inflect_verb('see', ['pres']))