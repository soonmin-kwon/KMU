/*problem : 수직 수평 성분의 교차*/
/*20161290 권순민*/

#include <iostream>
using namespace std;

int main() {
	int numOfCase;
	cin >> numOfCase;
	for (int i = 0; i < numOfCase; i++) {
		int x1, x2, y1, y2;						
		int a1, a2, b1, b2;						
		cin >> x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;
		cin >> a1;
		cin >> b1;
		cin >> a2;
		cin >> b2;
		if (x1 == x2) {
			int by, sy;
			int bx, sx;
			if (y1 > y2) {
				by = y1;					
				sy = y2;					
			}
			else {
				by = y2;
				sy = y1;
			}
			if (a1 > a2) {
				bx = a1;
				sx = a2;
			}
			else {
				bx = a2;					
				sx = a1;					
			}
			if (sx < x1 && bx > x1) {
				if (b1 > sy && b1 < by) {
					cout << 1 << endl;
				}
				else if (b1 <sy || b1 > by) {
					cout << 0 << endl;
				}
				else if (b1 == sy || b1 == by) {
					cout << 2 << endl;
				}
			}
			else if (sx == x1 || bx == x1) {
				if (b1 >= sy && b1 <= by) {
					cout << 2 << endl;
				}
				else if (b1 <sy || b1 > by) {
					cout << 0 << endl;
				}
			}
			else if (sx > x1 || bx < x1 || b1 < sy || b1 > by) {
				cout << 0 << endl;
			}
		}
		if (y1 == y2) {
			int by, sy;
			int bx, sx;
			if (x1 > x2) {
				bx = x1;
				sx = x2;
			}
			else {
				bx = x2;
				sx = x1;
			}
			if (b1 > b2) {
				by = b1;
				sy = b2;
			}
			else {
				by = b2;
				sy = b1;
			}
			if (a1 > sx && a1 < bx) {
				if (sy < y1 && by > y1) {
					cout << 1 << endl;
				}
				else if (y1 <sy || y1 > by) {
					cout << 0 << endl;
				}
				else if (y1 == sy || y1 == by) {
					cout << 2 << endl;
				}
			}
			else if (sx == a1 || bx == a1) {
				if (y1 >= sy && y1 <= by) {
					cout << 2 << endl;
				}
				else if (y1 <sy || y1 > by) {
					cout << 0 << endl;
				}
			}
			else if (sx > a1 || bx < a1 || y1 < sy || y1 > by) {
				cout << 0 << endl;
			}
		}
	}
}
