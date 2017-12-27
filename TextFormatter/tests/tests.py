import unittest
import os.path
import csv
from manager import Manager

class FormatterTests(unittest.TestCase):

    def setUp(self):
        VOCAB = {}

        SCRIPT_PATH = os.path.dirname(__file__)
        TEXT_PATH = os.path.join(SCRIPT_PATH, 'Assets/TEST_text.txt')
        VOCAB_PATH = os.path.join(SCRIPT_PATH, 'Assets/TEST_vocab.csv')

        self.tf = Manager(TEXT_PATH, VOCAB_PATH).create_formatter()

    def test_translate_words_from_text(self):
        expected_result = {
            'thought': ['думал'], 'saw': ['видел'], 'it': ['этом', 'это'],
            'think': ['думаю'], 'thinks': ['думает'], '(will)come': ['приду'],
            'see': ['видеть'], 'study': ['изучать']
            }
        self.assertEqual(self.tf.generate_words_to_swap(), expected_result)

    def test_bad_row_input(self):
        word_to_skip = 'jump'
        self.assertFalse(word_to_skip in self.tf.generate_words_to_swap())

    def test_word_inflection(self):
        expected = 'studied'
        tag = self.tf.morph.parse('изучала')[0].tag
        self.assertEqual(self.tf.inflector.inflect_verb('study', tag), expected)

    def tearDown(self):
        self.tf.text_file.close()

if __name__ == '__main__':
    unittest.main()