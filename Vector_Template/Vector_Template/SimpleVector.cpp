#pragma once
#include "SimpleVector.h"

using namespace std;


template<typename T>
SimpleVector<T>::SimpleVector() : currentSize(0), currentCapacity(10)
{
	data = new T[currentCapacity];
}

template<typename T>
SimpleVector<T>::SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity)
{
	if (capacity >= 0)
		data = new T[currentCapacity];
}

template<typename T>
SimpleVector<T>::~SimpleVector()
{
	delete[] data;
}

template <typename T>
SimpleVector<T>::SimpleVector(SimpleVector<T>& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity)
{
	data = new T[currentCapacity];
	for (int i = 0; i < currentSize; ++i) {
		data[i] = other.data[i];
	}
}

template <typename T>
void SimpleVector<T>::resize(int newCapacity)
{
	if (newCapacity <= currentCapacity)
	{
		return;
	}

	T* newData = new T[newCapacity];
	for (int i = 0; i < currentSize; ++i)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	currentCapacity = newCapacity;
}

template<typename T>
void SimpleVector<T>::push_back(const T& value)
{
	if (currentSize >= currentCapacity)
	{
		resize(currentCapacity + 5);
	}

	data[currentSize++] = value;
}

template<typename T>
void SimpleVector<T>::pop_back()
{
	if (currentSize > 0)
		--currentSize;
}

template<typename T>
int SimpleVector<T>::size()
{
	return currentSize;
}

template<typename T>
int SimpleVector<T>::capacity()
{
	return currentCapacity;
}

template<typename T>
void SimpleVector<T>::sortData()
{
	sort(data, data + currentSize);
}

template<typename T>
void SimpleVector<T>::printData()
{
	for (int i = 0; i < currentSize; i++)
		cout << data[i] << endl;
}


