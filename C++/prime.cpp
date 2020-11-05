/* problem : ¼Ò¼ö*/
/* 20161290 ±Ç¼ø¹Î*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main() {
	ifstream readFile;
	readFile.open("input.txt");
	int numTestcase;
	int input;
	readFile >> numTestcase;
	for (int k = 0; k < numTestcase; k++) {
		int prime = 1;
		readFile >> input;
		for (int i = 2; i < input; i++) {
			if ((input % i) == 0) {
				prime = 0;
				break;
			}
		}
		cout << prime << endl;
	}
}