#pragma once
#include <vector>

template<class T>
class ringBuffer
{
private:
	int pos;
	int m_size = 0;
	T *m_values;

public:
	class iterator;
	ringBuffer(int size) : pos(0), m_size(size), m_values(nullptr) {
		m_values = new T[size];
	}
	~ringBuffer() {
		delete[] m_values;
	}
	int size() {
		return m_size;
	}
	void add(T value) {
		m_values[pos] = value;
		pos++;
		if (pos == m_size)
			pos = 0;
	}
	T &get(int index) {
		if (index >= 0 && index < m_size) 
			return m_values[index];
		
		//return 0;
	}
	iterator begin() {
		return iterator();
	}
	iterator end() {
		return iterator();
	}
};

template<class T>
class ringBuffer<T>::iterator {
public:
	void print();
};
