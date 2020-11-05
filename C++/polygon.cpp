/* problem : 다각형의 면적*/
/* 20161290 권순민*/
#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int numOfCase;
	int numOfInput;
	int ispositive;
	int x[200];
	int y[200];
	cin >> numOfCase;
	for (int k = 0; k < numOfCase; k++) {
		cin >> numOfInput;
		int sum = 0;
		for (int j = 0; j < numOfInput; j++) {
			cin >> x[j];
			cin >> y[j];
		}
		for (int i = 1; i < numOfInput; i++) {
			sum += (x[i]+x[i-1]) * (y[i] - y[i-1]);
		}
		sum += (x[numOfInput - 1] + x[0]) * (y[0] -y[numOfInput - 1] );
		if (sum < 0) {
			ispositive = -1;
		}
		else {
			ispositive = 1;
		}
		cout << abs(sum) << " " << ispositive << endl;
	}
}
