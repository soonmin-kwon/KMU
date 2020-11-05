/* problem : 패리티 비트*/
/* 20161290 권순민*/
#include <iostream>
#include <fstream>
using namespace std;

void binary(int a) {
	int b[32] = { 0, };
	int count = 0;
	unsigned parity = a;
	for (int i = 0; a > 0; i++) {
		b[i] = a % 2;
		a = a / 2;
		if (b[i] == 1) {
			count++;
		}
	}
	if ((count % 2) == 1) {
		parity += 2147483648;
		cout << parity << endl;
	}
	else {
		cout << parity << endl;
	}

}
int main() {
	ifstream readFile;
	readFile.open("input.txt");
	int numTestcase;
	int paritybit;
	readFile >> numTestcase;
	for (int i = 0; i < numTestcase; i++) {
		readFile >> paritybit;
		binary(paritybit);
	}
}

