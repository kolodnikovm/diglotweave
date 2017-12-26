import os.path
import argparse
from manager import Manager

SCRIPT_PATH = os.path.dirname(__file__)
TEXT_NAME = os.path.join(SCRIPT_PATH, 'Assets/text.txt')
VOCAB_NAME = os.path.join(SCRIPT_PATH, 'Assets/vocab.csv')
RESULT_VOCAB = os.path.join(SCRIPT_PATH, 'Assets/words_to_swap.csv')

manager = Manager(TEXT_NAME, VOCAB_NAME)

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
        formatter = manager.create_formatter()
        formatter.save_to_csv(RESULT_VOCAB)
