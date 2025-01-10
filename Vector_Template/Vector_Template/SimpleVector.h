#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
class SimpleVector
{
private:
	T* data;
	T* newData;
	int currentSize;
	int currentCapacity;

	void resize(int newCapacity);

public:
	SimpleVector();
	SimpleVector(int capacity);
	~SimpleVector();

	SimpleVector(SimpleVector& other);

	void push_back(const T& value);
	void pop_back();
	int size();
	int capacity();
	void sortData();
	void printData();
};

#include "SimpleVector.cpp"
