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
	T Ÿ���� +=�����ڸ� ������ �Ϸ��� �غôµ� �����ǵ� �����ڿ� ������ ���մϴ�.
	�ƿ� ����� ���ϴ� ��Ȳ�� �������� ��� �ؾߵ��� ������ ���� �������ϴ�.
	�˼��մϴ�.
	*/

	
};

#include "Kvector.cpp"
#endif
