#include <iostream>
using namespace std;

int main() {
	unsigned int ip, ip1, ip2, ip3, ip4;
	char dot;
	int numofCase;
	unsigned int sumint;
	int select;
	cin >> numofCase;
	for (int i = 0; i < numofCase; i++) {
		cin >> select;
		if (select == 1) {
			cin >> ip1 >> dot >> ip2 >> dot >> ip3 >> dot >> ip4;
			sumint = (ip1 << 24) + (ip2 << 16) + (ip3 << 8) + ip4;
			cout << sumint << endl;
		}
		else {
			cin >> ip;
			cout << ((ip >> 24) & 0xFF)<< '.' <<  ((ip >> 16) & 0xFF) << '.' << ((ip >> 8) & 0xFF) << '.' << (ip & 0xFF) << endl;
		}
	}
}