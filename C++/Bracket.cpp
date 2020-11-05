#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int numofCase;
	string brack;
	char prev;
	vector <char> bracket;
	char arr[6] = {'(',')','{','}','[', ']'};
	cin >> numofCase;
	for (int j = 0; j < numofCase; j++) {
		cin >> brack;
		int isCorrect = 1;
		bracket.clear();
		for (int i = 0; i < brack.size(); i++) {
			if (brack[i] == arr[0] || brack[i] == arr[2] || brack[i] == arr[4]) {
				bracket.push_back(brack[i]);
			}
			else if (brack[i] == arr[1] || brack[i] == arr[3] || brack[i] == arr[5]) {
				if (bracket.empty()) {
					isCorrect = -1;
				}
				else {
					prev = bracket.back();
					bracket.pop_back();
					if ((brack[i] == arr[1] && prev != arr[0]) || (brack[i] == arr[3] && prev != arr[2]) || (brack[i] == arr[5] && prev != arr[4])) {
						isCorrect = -1;
					}
				}
			}
		}
		if (!bracket.empty()) {
			cout << 0 << endl;
		}
		else {
			if (isCorrect == 1) {
				cout << isCorrect << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
}