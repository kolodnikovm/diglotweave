import csv
import logging
import os.path
import argparse
from formatter.formatter import TextFormatter

class Manager:
    def __init__(self, text_path, vocab_path):
        self.text_path = text_path
        self.vocab_path = vocab_path

        self.VOCAB = {}

        try:
            with open(self.vocab_path, 'r', newline='', encoding='utf-8-sig') as vocab:
                for row in csv.reader(vocab):
                    try:
                        self.VOCAB.update({row[0]:row[1]})
                    except:
                        logging.warning('Bad row - {}'.format(row))
                        continue
        except FileNotFoundError:
            logging.error('File Not Found')
        except Exception as e:
            logging.error('Error occured during opening vocab.csv' + '\n' + e)

    def create_formatter(self):
        return TextFormatter(self.text_path, self.VOCAB)