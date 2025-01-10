#include "SimpleVector.h"
#include <iostream>


int main()
{
	SimpleVector<int> vec;

	for (int i = 0; i < 15; i++)
	{
		vec.push_back(i);
	}

	cout << "push_back size : " << vec.size() << endl;
	cout << "push_back capacity : " << vec.capacity() << endl;
	cout << "-------------------------------------------------------------" << endl;
	
	vec.pop_back();

	cout << "pop_back size : " << vec.size() << endl;
	cout << "pop_back capacity : " << vec.capacity() << endl;
	cout << "-------------------------------------------------------------" << endl;

	vec.push_back(100);
	vec.push_back(50);

	cout << "push_back2 size : " << vec.size() << endl;
	cout << "push_back2 capacity : " << vec.capacity() << endl;
	cout << "-------------------------------------------------------------" << endl;

	vec.sortData();

	cout << "[ 정렬된 데이터들 ]" << endl;
	vec.printData();
}
