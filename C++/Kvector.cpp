#include <iostream>
#include "Kvector.h"
using namespace std;


template<class T>
Kvector<T>::Kvector(int sz , T value) : len(sz) {
	cout << this << " : Kvector(" << sz << "," << value << ")\n";
	if (!sz) {
		m = NULL;
		return;
	}
	m = new T[sz];
	for (int i = 0; i < sz; i++) {
		m[i] = value;
	}
}
template<class T>
Kvector<T>::Kvector(const Kvector& v) {
	cout << this << " : Kvector(*" << &v << ")\n";
	len = v.len;
	if (!len) {
		m = NULL;
		return;
	}
	m = new T[len];
	for (int i = 0; i < len; i++) {
		m[i] = v.m[i];
	}
}
template<class T>
Kvector<T>::~Kvector() {
	cout << this << " : ~Kvector() \n";
	delete[] m;
}

template<class T>
Kvector<T>& Kvector<T>::operator=(const Kvector& v) {
	cout << "Kvector::operator= " << &v << endl;
	delete[] m;
	len = v.len;
	m = new T[len];
	for (int i = 0; i < len; i++) {
		m[i] = v.m[i];
	}
	return *this;
}
template<class T>
bool Kvector<T> ::operator==(const Kvector& v1) {
	if (v1.len != this->len) {
		return false;
	}
	for (int i = 0; i < v1.size(); i++) {
		if (v1.m[i] != this->m[i]) {
			return false;
		}
	}	
	return true;
}
template<class T>
bool Kvector<T> ::operator!=(const Kvector& v1) {
	if (v1.len != this->len) {
		return true;
	}
	for (int i = 0; i < v1.size(); i++) {
		if (v1.m[i] != this->m[i]) {
			return true;
		}
	}
	return false;

}
template<class T>
ostream& operator <<(ostream& os, const Kvector<T>& v) {
	for (int i = 0; i < v.len; i++) {
		os << v.m[i] << " ";
	}
	return os;
}

