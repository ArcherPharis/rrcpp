#pragma once
#include <vector>
#include <random>
#include <functional>

template<int count>
std::vector<int> getData()
{
	static std::vector<int> data(count);
	std::random_device de;
	std::default_random_engine engine{ de()};
	std::uniform_int_distribution<int> dstr{0, count};

	for (int i = 0; i < count; ++i)
	{
		data[i] = dstr(engine);
	}
	return data;
}

//bubble sort
void bubbleSort(std::vector <int>& data);

//insertion sort
void insertionSort(std::vector<int>& data);

//shell sort
void shellSort(std::vector<int>& data);

//merge sort : O(NLogN)
void mergeSort(std::vector<int>& data);
void mergeSortInternal(std::vector<int>& data, std::vector<int>& temp, int left, int right);

//quick sort
void quickSort(std::vector<int>& data);
void quickSortInternal(std::vector<int>& data, int left, int right);
int median3(std::vector<int>& data, int left, int right);

void printVec(const std::vector<int>& data);

void evaluateAlgoritm(std::vector<int> data, std::function<void(std::vector<int>&)> alogorithm, const std::string& nsg, bool printResult);
