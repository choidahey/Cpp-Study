// Task 1번
// 1. 5개의 정수 입력받아서 배열에 저장
// 2. 합계, 평균 출력(합계와 평균은 각 함수로 구현)
// 3. 입력받은 숫자 배열 정렬(sort 사용 x)
// (숫자 1 입력받으면 오름차순 정렬, 2 입력받으면 내림차순 정렬)

#include <iostream>

using namespace std;

int Sum(int arr[], int size)
{
	if (size == 0)
		return 0;

	int result = 0;

	for (int i = 0; i < size; i++)
	{
		result += arr[i];
	}

	return result;
}

int Avg(int arr[], int size)
{
	if (size == 0)
		return 0;

	int result = 0;

	for (int i = 0; i < size; i++)
	{
		result += arr[i];
	}
	result = result / size;

	return result;
}

void Sort_Array(int arr[], int size, bool ascending)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			bool condition = ascending ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]);
			if (condition)
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr_count = 0;
	int sort_mode = 0;

	cout << "몇 번의 숫자를 입력하실건가요?" << endl;
	cin >> arr_count;

	if (arr_count <= 0)
	{
		cout << "유효한 숫자가 아닙니다. 프로그램을 종료합니다 ^^" << endl;
		return 0;
	}

	int* arr_num = new int[arr_count];
	cout << arr_count << "개의 숫자를 입력하세요: " << endl;

	for (int i = 0; i < arr_count; i++)
	{
		cin >> arr_num[i];
	}

	int sum = Sum(arr_num, arr_count);
	int avg = Avg(arr_num, arr_count);

	cout << "합계 : " << sum << endl;
	cout << "평균 : " << avg << endl;


	cout << "정렬 방식을 선택하세요 (1: 오름차순, 2: 내림차순)" << endl;
	cin >> sort_mode;

	bool ascending = true;

	if (sort_mode == 1)
	{
		ascending = true;
		Sort_Array(arr_num, arr_count, ascending);
		cout << "오름차순으로 정렬되었습니다." << endl;
	}
	else if (sort_mode == 2)
	{
		ascending = false;
		Sort_Array(arr_num, arr_count, ascending);
		cout << "내림차순으로 정렬되었습니다." << endl;
	}
	else
	{
		cout << "잘못된 정렬 선택입니다." << endl;
		delete[] arr_num;
		return 0;
	}

	for (int i = 0; i < arr_count; i++)
	{
		cout << "정렬된 원소 : " << arr_num[i] << endl;
	}

	delete[] arr_num;

	return 0;
}