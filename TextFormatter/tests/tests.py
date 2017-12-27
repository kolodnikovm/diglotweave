import unittest

from formatter.formatter import TextFormatter

class FormatterTests(unittest.TestCase):

    def setUp(self):
        VOCAB = {
        "see": "видеть",
        "it": "это",
        "think": "думать",
        "study": "изучать",
        "come": "прийти"
        }
        TEXT_NAME = './Assets/TEST_text.txt'
        self.tf = TextFormatter(TEXT_NAME, VOCAB)

    def test_translate_words_from_text(self):
        expected_result = {
            'thought': ['думал'], 'saw': ['видел'], 'it': ['этом', 'это'],
            'think': ['думаю'], 'thinks': ['думает'], '(will)come': ['приду'],
            'see': ['видеть'], 'study': ['изучать']
            }
        self.assertEqual(self.tf.generate_words_to_swap(), expected_result)

if __name__ == '__main__':
    unittest.main()
