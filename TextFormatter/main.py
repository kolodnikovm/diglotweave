import csv
import logging
import os.path
import argparse
from formatter.formatter import TextFormatter


SCRIPT_PATH = os.path.dirname(__file__)
TEXT_NAME = os.path.join(SCRIPT_PATH, 'Assets/text.txt')
VOCAB_NAME = os.path.join(SCRIPT_PATH, 'Assets/vocab.csv')
RESULT_VOCAB = os.path.join(SCRIPT_PATH, 'Assets/words_to_swap.csv')

try:
    with open(VOCAB_NAME, 'r', newline='', encoding='utf-8') as vocab:
        VOCAB = {}
        for row in csv.reader(vocab):
            VOCAB.update({row[0]:row[1]})
except FileNotFoundError:
    logging.error('File Not Found')
except Exception as e:
    logging.error('Error occured during opening vocab.csv' + '\n' + e)

VOCAB = {
    "see": "видеть",
    "it": "это",
    "think": "думать",
    "study": "изучать",
    "come": "прийти"
}

parser = argparse.ArgumentParser()
parser.add_argument('--test', help='Run Unit Tests', action='store_true')
args = parser.parse_args()

def run_tests():
    import unittest
    tests = unittest.TestLoader().discover('tests')
    unittest.TextTestRunner(verbosity=2).run(tests)


if __name__ == '__main__':
    if args.test:
        run_tests()
    else:
        FORMATTER = TextFormatter(TEXT_NAME, VOCAB)
        FORMATTER.save_to_csv(RESULT_VOCAB)
