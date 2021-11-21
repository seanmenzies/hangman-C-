#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

int main() {
  // intialise word list
	const int MAX_GUESSES = 8;
	vector<string> words;
	words.push_back("DONKEY");
	words.push_back("BUTTERSCOTCH");
	words.push_back("HAPPINESS");
  
  // shuffle vector
	srand(time(0));
	random_shuffle(words.begin(), words.end());
  
  // set game word to word at vector[0]
	const string WORD = words[0];
	int guesses = 0;

  // create string that updates correct guesses from '-'
	string guessed(WORD.size(), '-');

  // keep a running tally of incorrect guesses
	string used_letters = "";

	cout << "Welcome to hangman! May the force be with you!" << endl;

	while ((guesses < MAX_GUESSES) && (guessed != WORD)) {
		cout << "\nYou have \r" << MAX_GUESSES - guesses << " left" << endl;
		cout << "\nThe word so far is:\n" << guessed << endl;
		cout << "\nYou've used the following letters: " << used_letters << endl;

		char guessed_char;
		cout << "\nPlease enter a letter:\r\n" << flush;
		cin >> guessed_char;
		guessed_char = toupper(guessed_char);

    // deal with duplicate guesses
		while (used_letters.find(guessed_char) != string::npos) {
			cout << "\nYou have already used this character. Guess again: ";
			cin >> guessed_char;
			guessed_char = toupper(guessed_char);
		}

    // update '-' string for correct guesses
		if (WORD.find(guessed_char) != string::npos) {
			cout << "\nGood guess!";
			for (int i = 0; i < WORD.size(); i++) {
				if (guessed_char == WORD[i]) {
					guessed[i] = WORD[i];
				}
			}
		}
    // for incorrect guesses, add guess to incorrect guesses and recalculate remaining guesses
		else {
			cout << "\nNo dice, try again!";
			used_letters.push_back(guessed_char);
			guesses += 1;
		}
	}

  // lose condition
	if (guesses == MAX_GUESSES) {
		cout << "\nYou're all out of guesses. The man is hanged!" << endl;
		cout << "\nSee ya!" << endl;
	}

  // win condition
	else {
		cout << "\nGreat job! The word was " << WORD << endl;
		cout << "\nCongratulations!" << endl;
	}

	return 0;
}
