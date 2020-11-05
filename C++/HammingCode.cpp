#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void send(unsigned int a) {
	vector<unsigned int> send;
	int p1 = 0, p2 = 0, p4 = 0, p8 = 0, p16 = 0;
	unsigned int sd = 0;
	for (int i = 0; a > 0; i++) {
		send.push_back(a % 2);
		a = a / 2;
	}
	while (send.size() != 26) {
		send.push_back(0);
	}
	send.insert(send.begin(), 0);
	send.insert(send.begin() + 1, 0);
	send.insert(send.begin() + 3, 0);
	send.insert(send.begin() + 7, 0);
	send.insert(send.begin()+15,0);

	for (unsigned int i = 0; i < send.size(); i++) {
		if (i % 2 == 0) {
			if(send[i] == 1)
				p1++;
		}
		if (i % 4 == 1 || i % 4 == 2) {
			if (send[i] == 1)
				p2++;
		}
		if (3 <= i % 8 && i % 8 <= 6) {
			if (send[i] == 1)
				p4++;
		}
		if (7 <= i % 16 && i % 16 <= 14) {
			if (send[i] == 1)
				p8++;
		}
		if (15 <= i % 32 && i % 32 <= 30) {
			if (send[i] == 1)
				p16++;
		}
	}
	if (p1 % 2 == 0) {
		send[0] = 0;
	}
	else {
		send[0] = 1;
	}
	if (p2 % 2 == 0) {
		send[1] = 0;
	}
	else {
		send[1] = 1;
	}
	if (p4 % 2 == 0) {
		send[3] = 0;
	}
	else {
		send[3] = 1;
	}
	if (p8 % 2 == 0) {
		send[7] = 0;
	}
	else {
		send[7] = 1;
	}
	if (p16 % 2 == 0) {
		send[15] = 0;
	}
	else {
		send[15] = 1;
	}
	for (unsigned int i = 0; i < send.size(); i++) {
		sd += send[i] * pow(2, i);
	}
	send.clear();
	cout << sd << endl;
}
void receive(unsigned int a) {
	vector<unsigned int> receive;
	int index = 0;
	int p1 = 0, p2 = 0, p4 = 0, p8 = 0, p16 = 0;
	unsigned int sd = 0;
	for (int i = 0; a > 0; i++) {
		receive.push_back(a % 2);
		a = a / 2;
	}
	while (receive.size() != 31) {
		receive.push_back(0);
	}
	for (unsigned int i = 0; i < receive.size(); i++) {
		if (i % 2 == 0) {
			if (receive[i] == 1)
				p1++;
		}
		if (i % 4 == 1 || i % 4 == 2) {
			if (receive[i] == 1)
				p2++;
		}
		if (3 <= i % 8 && i % 8 <= 6) {
			if (receive[i] == 1)
				p4++;
		}
		if (7 <= i % 16 && i % 16 <= 14) {
			if (receive[i] == 1)
				p8++;
		}
		if (15 <= i % 32 && i % 32 <= 30) {
			if (receive[i] == 1)
				p16++;
		}
	}
	if (p1 % 2 != 0) {
		index += 1;
	}
	if (p2 % 2 != 0) {
		index += 2;
	}
	if (p4 % 2 != 0) {
		index += 4;
	}
	if (p8 % 2 != 0) {
		index += 8;
	}
	if (p16 % 2 != 0) {
		index += 16;
	}
	if (index != 0) {
		if (receive[index - 1] == 1) {
			receive.erase(receive.begin() + 25);
			receive.insert(receive.begin() + 25, 0);
		}
		else {
			receive.erase(receive.begin() + 25);
			receive.insert(receive.begin() + 25, 1);
		}
	}
	receive.erase(receive.begin() + 15);
	receive.erase(receive.begin() + 7);
	receive.erase(receive.begin() + 3);
	receive.erase(receive.begin() + 1);
	receive.erase(receive.begin());

	for (unsigned int i = 0; i < receive.size(); i++) {
		sd += receive[i] * pow(2, i);
	}
	receive.clear();
	cout << sd << endl;
}

int main() {
	int numTestCases;
	unsigned int num1, num2;
	cin >> numTestCases;
	for (int i = 0; i < numTestCases; i++) {
		cin >> num1 >> num2;
		if (num1 == 0) {
			send(num2);
		}
		else if (num1 == 1) {
			receive(num2);
		}
	}
}