/* problem : »ï°¢ÇüÀÇ Á¾·ù(2)*/
/* 20161290 ±Ç¼ø¹Î*/

#include <iostream>
using namespace std;

int main() {
    int numOfCase;
    int ax, ay, bx, by, cx, cy;
    int d1, d2, d3;
    int min, mid, max;
    cin >> numOfCase;
    for (int i = 0; i < numOfCase; i++) {
        cin >> ax;
        cin >> ay;
        cin >> bx;
        cin >> by;
        cin >> cx;
        cin >> cy;
        d1 = (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
        d2 = (cx - bx) * (cx - bx) + (cy - by) * (cy - by);
        d3 = (cx - ax) * (cx - ax) + (cy - ay) * (cy - ay);
        if (d1 >= d2) {
            if (d1 >= d3) {
                if (d2 >= d3) {
                    max = d1;
                    mid = d2;
                    min = d3;
                }
                else if (d3 >= d2) {
                    max = d1;
                    mid = d3;
                    min = d2;
                }
            }
            else if (d3 >= d1) {
                max = d3;
                mid = d1;
                min = d2;
            }
        }
        else if (d2 >= d1) {
            if (d2 >= d3) {
                if (d1 >= d3) {
                    max = d2;
                    mid = d1;
                    min = d3;
                }
                else if (d3 >= d1) {
                    max = d2;
                    mid = d3;
                    min = d1;
                }
            }
            else if (d3 >= d2) {
                max = d3;
                mid = d2;
                min = d1;
            }
        }
        if (ax == bx && bx == cx) {
            cout << 0 << endl;
        }
        else if (ay == by && by == cy) {
            cout << 0 << endl;
        }
        else {
            double slo = ((double(ay) - double(by)) / (double(ax) - double(bx)));
            double slo2 = ((double(cy) - double(by)) / (double(cx) - double(bx)));
            if (slo == slo2) {
                cout << 0 << endl;
            }
            else {
                if (min + mid == max) {
                    cout << 1 << endl;
                }
                else if (min + mid < max) {
                    cout << 2 << endl;
                }
                else if (min + mid > max) {
                    cout << 3 << endl;
                }
            }


        }
    }
}
