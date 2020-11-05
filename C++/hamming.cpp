/* problem : 해밍수*/
/* 20161290 권순민*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int numofCase, location;
	int max = 398580750;
	ifstream readFile;
	readFile.open("input.txt");
	readFile >> numofCase;
	for (int a = 0; a < numofCase; a++) {
	vector<int> hamming;
	readFile >> location;
		for (int i = 1; i <= max; i *= 2) {								
			for (int j = i; j <= max; j *= 3) {							
				for (int k = j; k <= max; k *= 5) {						// 1 * (2^i+1)*(3^j+1)*(5^k+1)
					hamming.push_back(k);
					if (k > max / 5) {
						break;
					}
				}
				if (j > max / 3) {
					break;
				}
			}
			if (i > max / 2) {
				break;
			}
		}
		sort(hamming.begin(), hamming.end());
		cout << hamming[location - 1] << endl;
	}
}
