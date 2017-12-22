import os.path
from Formatter.formatter import TextFormatter


SCRIPT_PATH = os.path.dirname(__file__)
TEXT_NAME = os.path.join(SCRIPT_PATH, 'Assets//text.txt')
RESULT_VOCAB = os.path.join(SCRIPT_PATH, 'Assets//words_to_swap.csv')
VOCAB = {
    "see": "видеть",
    "it": "это",
    "think": "думать"
}

FORMATTER = TextFormatter(TEXT_NAME, VOCAB)

FORMATTER.save_to_csv(RESULT_VOCAB)
