import os.path
import sys
from formatter.formatter import TextFormatter


SCRIPT_PATH = os.path.dirname(__file__)
TEXT_NAME = os.path.join(SCRIPT_PATH, 'Assets/text.txt')
RESULT_VOCAB = os.path.join(SCRIPT_PATH, 'Assets/words_to_swap.csv')
VOCAB = {
    "see": "видеть",
    "it": "это",
    "think": "думать",
    "study": "изучать",
    "come": "прийти"
}

def run_tests():
    import unittest
    tests = unittest.TestLoader().discover('tests')
    unittest.TextTestRunner(verbosity=2).run(tests)

if __name__ == '__main__':
    if 'test' in sys.argv:
        run_tests()
    else:
        FORMATTER = TextFormatter(TEXT_NAME, VOCAB)
        FORMATTER.save_to_csv(RESULT_VOCAB)
