#include "MyPolynomial.h" 

/********************* add your code here ********************************/
myPolynomial::myPolynomial(int c, unsigned e): coeff(c), degree(e){
    polynom.push_back(myTerm(c, e));
}
myPolynomial::myPolynomial(int nTerms, int mono[]): degree(nTerms - 1) {
    for (int i = 0; i < 2 *nTerms; i+=2) {
       polynom.push_back( myTerm(mono[i], mono[i + 1]));
    }
    polynom.sort();
}

myPolynomial::myPolynomial(const myPolynomial& poly) {
    polynom = poly.polynom;
}
bool myPolynomial::operator == (const myPolynomial& poly) const {
    return (polynom == poly.polynom);
}

bool myPolynomial::operator != (const myPolynomial& poly) const {
    return !(polynom == poly.polynom);
}

myPolynomial& myPolynomial:: operator +=(const myPolynomial& poly) {
    myTerm temp;
    list<myTerm> tempp;
    for (iter = polynom.begin(); iter != polynom.begin(); iter++) {
        temp = *iter;
        if (temp.exp == poly.exp) {
            temp.coeff += poly.coeff;
            tempp.push_back(temp);
        }
    }
    polynom = tempp;
    return *this;
}

myPolynomial& myPolynomial:: operator -=(const myPolynomial& poly) { 
    myTerm temp;
    list<myTerm> tempp;
    for (iter = polynom.begin(); iter != polynom.begin(); iter++) {
        temp = *iter;
        if (temp.exp == poly.exp) {
            temp.coeff -= poly.coeff;
            tempp.push_back(temp);
        }
    }
    polynom = tempp;
    return *this;
}
myPolynomial& myPolynomial:: operator *=(const myPolynomial& poly) {
    return *this;
}
myPolynomial& myPolynomial:: operator *=(int k) { 
    return *this; 
}

myPolynomial myPolynomial:: operator -() const {
    return degree; 
}
myPolynomial myPolynomial:: operator +(const myPolynomial& poly) const {
    return coeff;
}
myPolynomial myPolynomial:: operator -(const myPolynomial& poly) const {
    return degree;
}
myPolynomial myPolynomial:: operator *(const myPolynomial& poly) const {
    return degree;
}
myPolynomial myPolynomial:: operator *(int k) const {
    return k;
}

long myPolynomial::operator() (int x) const{
    return x;
}

int myPolynomial::getDegree() const {
    return degree;
}

unsigned myPolynomial::getNumTerms() const{
    return polynom.size();
}

myPolynomial myPolynomial::ddx() const {
    for (int i = 0; i < degree; i++) {
        
    }
    return degree;
}


myPolynomial operator *(int k, const myPolynomial& poly) {
    return k;
}
// output operator
ostream& operator <<(ostream& outStream, const myPolynomial& poly) {
    if (poly == myPolynomial::ZERO) {
        return outStream << 0;
    }
/********************* add your code here ********************************/
    return outStream; }

const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0 
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1 
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x 
