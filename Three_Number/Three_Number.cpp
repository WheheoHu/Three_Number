// Three_Number.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

const int SIZEOFARRAY=3;


template <typename T>
void quick_sort_recursive(T arr[], int start, int end);

template <typename T> 
void quick_sort(T arr[], int len);

template<typename T>
void ThreeNumber(T num[]);

int main()
{
	int num[SIZEOFARRAY];
	for (int i = 0; i < SIZEOFARRAY;i++)
	{
		std::cin >> num[i];
	}
	std::cout << std::endl;
	ThreeNumber(num);
	system("pause");
    return 0;
}

template<typename T>
void ThreeNumber(T num[]) {
	quick_sort(num, SIZEOFARRAY);
	//std::sort(num, num + SIZEOFARRAY);
	for (int i = 0; i < SIZEOFARRAY; i++)
	{
		std::cout << num[i] << std::endl;
	}
}

//Quick_Sort
template <typename T>
void quick_sort(T arr[], int len) {
	quick_sort_recursive(arr, 0, len - 1);
}
template <typename T>
void quick_sort_recursive(T arr[], int start, int end) {
	if (start >= end)
		return;
	T mid = arr[end];
	int left = start, right = end - 1;
	while (left < right) {
		while (arr[left] < mid && left < right)
			left++;
		while (arr[right] >= mid && left < right)
			right--;
		std::swap(arr[left], arr[right]);
	}
	if (arr[left] >= arr[end])
		std::swap(arr[left], arr[end]);
	else
		left++;
	quick_sort_recursive(arr, start, left - 1);
	quick_sort_recursive(arr, left + 1, end);
}
