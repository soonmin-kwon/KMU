#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	int numofCase;
	int numofdata1, numofdata2;
	int element;
	int count1, count2, count3;
	ifstream readFile;
	readFile.open("input.txt");
	readFile >> numofCase;

	for (int n = 0; n < numofCase; n++) {
		int setA[132] = { 0, };
		int setB[132] = { 0, };
		int setUni[132] = { 0, };
		int setInter[132] = { 0, };

		readFile >> numofdata1;
		for (int i = 0; i < numofdata1; i++) {
			readFile >> element;
			setA[element - 1] = 1;
		}
		readFile >> numofdata2;
		for (int i = 0; i < numofdata2; i++) {
			readFile >> element;
			setB[element - 1] = 1;
		}
		for (int i = 0; i < 132; i++) {
			if (setA[i] & setB[i]) {
				setInter[i] = 1;
			}
			if (setA[i] | setB[i]) {
				setUni[i] = 1;
			}
			if (setA[i] == setB[i]) {
				setA[i] = 0;
			}
		}
		count1 = count(setInter, setInter + 132, 1);
		count2 = count(setUni, setUni + 132, 1);
		count3 = count(setA, setA + 132, 1);
		cout << count1 << " ";
		for (int i = 0; i < 132; i++) {
			if (setInter[i] == 1) {
				cout << i + 1 << " ";
			}
		}
		cout << endl;
		cout << count2 << " ";
		for (int i = 0; i < 132; i++) {
			if (setUni[i] == 1) {
				cout << i + 1 << " ";
			}
		}
		cout << endl;
		cout << count3 << " ";
		for (int i = 0; i < 132; i++) {
			if (setA[i] == 1) {
				cout << i + 1 << " ";
			}
		}
		cout << endl;
	}
}