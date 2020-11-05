#include "MyHammingDistance.h"
#include <cstddef>
#include <iostream>
using namespace std;
#define XOR(a,b) (!(a)^!(b))

// constructors 
MyBinaryNumber::MyBinaryNumber () :value(0) {
    
}

MyBinaryNumber::MyBinaryNumber(unsigned int val) :value(val) {
    
}

// accessor functions 
unsigned int MyBinaryNumber::getValue () const {
    return value; 
}
// mutator functions 
void MyBinaryNumber::setValue (unsigned int val) {
    value = val; 
}
// 어떤 정수의 해밍 무게를 계산하는 함수 
int MyBinaryNumber::getHammingWeight() const {
    int v1[32];
    int counter = 0;
    std::fill_n(v1, 32, 0);
    for (int i = 0; getValue()>0; i++) {
        v1[i] = value % 2;
        value / 2;
        if (v1[i] == 1) {
            counter++;
        }
    }
    return counter;
}
// comptue Hamming Distance
int MyBinaryNumber::getHammingDistance(const MyBinaryNumber& bn) const
{ 
    return value;
}
