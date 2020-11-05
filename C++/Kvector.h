#include <iostream>
#include <typeinfo>
#ifndef __KVECTOR__
#define __KVECTOR__
template<class T>
class Kvector {
public:
	T* m;
	int len;
	Kvector(int sz , T value);
	Kvector(const Kvector& v);
	virtual ~Kvector();
	
	virtual void print() const {
		std::cout << "Kvector: ";
		for (int i = 0; i < len; i++) {
			std::cout << m[i] << " ";
		}
		std::cout << std::endl;
		
	}
	void clear() {
		delete[] m;
		m = NULL;
		len = 0;
	}
	int size() const {
		return len;
	}
	
	Kvector& operator=(const Kvector& v);
	bool operator==(const Kvector& v1);
	bool operator!=(const Kvector& v1);
	T& operator[] (int idx) {
		return m[idx];
	}
	
	T sum() const {
		T s;
		for (int i = 0; i < len; i++) {
			s += m[i];
		}
		return s;
	}

	/*
	T& operator+=(const T& v1) {
		
	}
	T 타입의 +=연산자를 재정의 하려고 해봤는데 재정의된 연산자에 접근을 못합니다.
	아예 사용을 안하는 상황이 벌어져서 어떻게 해야될지 도무지 감이 안잡힙니다.
	죄송합니다.
	*/

	
};

#include "Kvector.cpp"
#endif
