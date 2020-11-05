#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	int numofCase, numofSeq;
	int period, seq, count;
	ifstream readFile;
	readFile.open("input.txt");
	readFile >> numofCase;
	vector<int> sequence;
	vector<int> moving_Average;
	for (int i = 0; i < numofCase; i++) {
		readFile >> numofSeq;
		for (int i = 0; i < numofSeq; i++) {
			readFile >> seq;
			sequence.push_back(seq);
		}
		readFile >> period;
		count = numofSeq - period + 1;
		cout << count << " ";
		for (int i = 0; i < count; i++) {
			int sum = 0;
			for (int j = 0; j < period; j++) {
				sum += sequence[i+j];
			}
			moving_Average.push_back(sum);
			cout <<  moving_Average[i]/period << " ";
		}
		cout << endl;
		sequence.clear();
		moving_Average.clear();
	}
}