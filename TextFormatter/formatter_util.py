from os.path import exists
import argparse
from manager import Manager

parser = argparse.ArgumentParser()
parser.add_argument('--in_dictionary', help='The input dictionary path',
                    default='vocab.csv')
parser.add_argument('--in_text', help='The input text path',
                    default='text.txt')
parser.add_argument('--out_dictionary', help='The output dictionary path',
                    default='vocab_out.csv')
args = parser.parse_args()

if __name__ == "__main__":
    if exists(args.in_dictionary) and exists(args.in_text):
        manager = Manager(args.in_text, args.in_dictionary)
        formatter = manager.create_formatter()
        formatter.save_to_csv(args.out_dictionary)
