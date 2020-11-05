#include "cstring"
#include "MyISBN.h"

// constructors 
MyISBN::MyISBN () {
    isbn[0] = '\0'; 
}
MyISBN::MyISBN(char isbn_number[]) {
    strcpy_s(isbn, isbn_number); 
}

// utility functions
bool MyISBN::isCorrectNumber() const {
    if (isSyntaxValid() && isCheckSumValid()) 
        return true; 
    else 
        return false; 
}
// private functions 
bool MyISBN::isSyntaxValid() const {
    int c1=0, c2=0, c3=0;
    int counter = 0;
    for (int i = 0; i < strlen(isbn); i++) {
        if (!(isbn[i] >= '0' && isbn[i] <= '9') || isbn[i] != '-' || (isbn[i] == 'X' && isbn[i-1] != '-')) {
            return false;
            break;
        }
    }
    for (int i = 0; i < strlen(isbn); i++) {
        if (isbn[i] == '-') {
            counter += 1;
            switch (counter)
            {
            case 1:
                c1 = i;
            case 2:
                c2 = i;
            case 3:
                c3 = i;
            case 4:
                break;
            }
        }
        if (c1 != 0 && c2 != 0 && c3 != 0) {
            if (c1 > 5 || c1<1) {
                return false;
            }
            if (c2 - c1 > 7 || c2-c1 < 1) {
                return false;
            }
            if (c3 - c2 > 6 || c3 - c2 < 1) {
                return false;
            }
        }
        if (counter > 3) {
            return false;
        }
    }
    return true;
}
bool MyISBN::isCheckSumValid() const {
    int k= 0;
    int counter = 0;
    for (int i = 0; i < strlen(isbn); i++) {
        if (isbn[i] == '-') {
            counter += 1;
            k += i;
        }
    }
}

/*
checksum
한자리 숫자
모든 수에 수를 곱해서 다 더한다음 그 수보다 크면서 가장 작은 11의 배수를 찾아서
그 수를 뺀다.
checksum = 10이면 X

적어도 한자리 이상 숫자
5-7-6-1
*/