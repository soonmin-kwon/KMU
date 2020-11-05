#ifndef _MY_ISBN_H_
#define _MY_ISBN_H_

const int max_length = 256;

class MyISBN {
public:
	// consturctors
	MyISBN();
	MyISBN(char isbn_number[]);

	// utility functions
	bool isCorrectNumber() const;
private:
	char isbn[max_length + 11];
	bool isSyntaxValid() const;
	bool isCheckSumValid() const;
};
#endif // _MY_ISBN_H_