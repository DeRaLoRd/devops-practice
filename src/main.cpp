#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) 
{
	string input;
	string input_raw;

	if (argc == 1) {
		if (isatty(STDIN_FILENO)) {
			cout << "Please input the string (80 character max):\n";
		}
		getline(cin, input_raw);
	}
	else if (argc == 2) {
		input_raw = argv[1];
	}
	else if (argc > 2) {
		cout << "Error: Too many arguments. Usage: prog <string up to 80 characters>" << endl;
		return 1;
	}

	input = input_raw.substr(0, 80);

	string sentence_separators_start = " .";
	string sentence_separators_end = ".";
	string word_separators = " ,;:";

	vector<string> sentences;
	vector<string> words;
	vector<string> result_sentences;

	// tokenize the sentences
	size_t start_sentence = input.find_first_not_of(sentence_separators_start);
	while (start_sentence != string::npos) {
		size_t end_sentence = input.find_first_of(sentence_separators_end, start_sentence + 1);
		if (end_sentence == string::npos) {
			end_sentence = input.length();
		}

		sentences.push_back(input.substr(start_sentence, end_sentence - start_sentence));
		
		start_sentence = input.find_first_not_of(sentence_separators_start, end_sentence + 1);
	}

	// debug check
	// for (int i = 0; i < sentence_amount; i++) {
	// 	cout << i + 1 << ". " << sentences[i] << "|\n"; 
	// }

	// for each sentence
	size_t sentence_amount = sentences.size();
	for (int i = 0; i < sentence_amount; i++) {
		string sentence = sentences[i];
		words.clear();

		// tokenize the words
		size_t start_word = sentence.find_first_not_of(word_separators);
		while (start_word != string::npos) {
			size_t end_word = sentence.find_first_of(word_separators, start_word + 1);
			if (end_word == string::npos) {
				end_word = sentence.length();
			}

			words.push_back(sentence.substr(start_word, end_word - start_word));
		
			start_word = sentence.find_first_not_of(word_separators, end_word + 1);
		}

		// count average length in current sentence
		size_t word_amount = words.size();
		size_t sum = 0;
		for (int j = 0; j < word_amount; j++) {
			sum += words[j].size();
		}
		double avg_length = (double)sum / word_amount;

		//cout << "SENTENCE " << i + 1 << ":\nAvg lenght: " << avg_length << '\n';

		string result_sentence;

		// cherry-pick long words (with cleanup)
		for (int j = 0; j < word_amount; j++) {
			if (words[j].size() >= avg_length) {
				result_sentence.append(' ' + words[j]);
			}
		}
		result_sentence = result_sentence.substr(1, result_sentence.size());

		//cout << "RESULT: " << result_sentence << '\n';

		result_sentences.push_back(result_sentence);
	}

	string result_text;
	size_t result_sentence_amount = result_sentences.size();
	for (int i = 0; i < result_sentence_amount; i++) {
		result_text.append(result_sentences[i] + ". ");
	}

	cout << result_text << endl;

	return 0;
}
