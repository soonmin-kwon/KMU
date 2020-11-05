#include <iostream>
using namespace std;

int** makeArray2D(int a, int b) {
	int n1 = a, n2 = b;
	int** arr = new int* [n1];
	for (int i = 0; i < n1; i++) {
		arr[i] = new int[n2];
	}
	return arr;
}
int main() {
	int numofCase, row, row2, column;
	int element;
	int sum = 0;
	cin >> numofCase;
	
	for (int a = 0; a < numofCase; a++) {
		cin >> row;
		cin >> row2;
		cin >> column;
		int** matrixA = NULL;
		matrixA = makeArray2D(row, row2);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < row2; j++) {
				cin >> element;
				matrixA[i][j] = element;
			}
		}
		int** matrixB = NULL;
		matrixB = makeArray2D(row2, column);
		for (int i = 0; i < row2; i++) {
			for (int j = 0; j < column; j++) {
				cin >> element;
				matrixB[i][j] = element;
			}
		}
		int** matrixC = NULL;
		matrixC = makeArray2D(row, column);
		for (int k = 0; k < column; k++) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < row2; j++) {
					sum += matrixA[i][j] * matrixB[j][k];
				}
				matrixC[i][k] = sum;
				sum = 0;
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				cout << matrixC[i][j] << " ";
			}
			cout << endl;
		}
	}
}
