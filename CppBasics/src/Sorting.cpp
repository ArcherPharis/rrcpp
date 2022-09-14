#include "Sorting.h"
#include <iostream>
#include <chrono>

//the size of the vector is N, then we are doing it N * N MAX = N^2. Quadratic time complicity.

//O(N^S) Big O Notation.
//a quadratic algorithm is slow.
void bubbleSort(std::vector<int>& data)
{

	for (int i = 0; i < data.size(); ++i)
	{
		for (int j = i; j < data.size(); ++j)
		{
			if (data[j] < data[i])
			{
				std::swap(data[j], data[i]); //an operation takes 1 time unit
			}
		}
	}
}
//O(N^2) Time complicity
void insertionSort(std::vector<int>& data)
{
	for (int i = 1; i < data.size(); ++i)
	{
		int temp = std::move(data[i]);
		int j = i;
		for (; j > 0 && temp < data[j - 1]; --j)
		{
			std::swap(data[j], data[j - 1]);
		}


		//insert everything bigger one unit forward, and move temp in.
		std::swap(data[j], temp);
	}


}


//O(N^2) Times, Big O Time Complicity
void shellSort(std::vector<int>& data)
{
	int gap = data.size() / 2;

	while (gap >= 1)
	{

		for (int i = gap; i < data.size(); i += gap)
		{
			int temp = data[i];
			int j;
			for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
			{
				std::swap(data[j], data[j - gap]);
			}
			data[j] = temp;
		}
		
		gap /= 2;

	}


}

void mergeSort(std::vector<int>& data)
{

	std::vector<int> temp(data.size());
	mergeSortInternal(data, temp,0, data.size() - 1);
}

void mergeSortInternal(std::vector<int>& data, std::vector<int>& temp, int left, int right)
{

	if (left == right)
	{
		return;
	}

	int center = (right + left) / 2;

	//recursive call, it's a divide and conquer method
	mergeSortInternal(data, temp, left, center);
	//recursive call, it's a divide and conquer method
	mergeSortInternal(data, temp, center + 1, right);

	int actr = left;
	int bctr = center + 1;
	int tctr = left;

	while (actr <= center && bctr <= right)
	{
		if (data[actr] < data[bctr])
		{
			temp[tctr++] = std::move(data[actr++]);
		}
		else
		{
			temp[tctr++] = std::move(data[bctr++]);
		}
	}

	//move leftovers in A
	while (actr <= center)
	{
		temp[tctr++] = std::move(data[actr++]);
	}

	while (bctr <= right)
	{
		temp[tctr++] = std::move(data[bctr++]);
	}

	for (int i = left; i <= right; ++i)
	{
		data[i] = std::move(temp[i]);
	}
}

void quickSort(std::vector<int>& data)
{
	quickSortInternal(data, 0, data.size() - 1);

}

void quickSortInternal(std::vector<int>& data, int left, int right)
{

	if (right - left > 10)
	{
		int pivot = median3(data, left, right);
		int lctr = left;
		int rctr = right - 1;


		for (;;)
		{
			while (data[++lctr] < pivot) {}
			while (data[--rctr] > pivot) {}

			if (lctr < rctr)
			{
				std::swap(data[lctr], data[rctr]);
			}
			else
				break;
		}

		//data[lctr] = std::move(pivot);
		std::swap(data[lctr], data[right - 1]);

		quickSortInternal(data, left, lctr - 1); //recursive calls
		quickSortInternal(data, lctr + 1, right); 


	}
	else
	{
		//do insertion sort, it's faster if there's less than 10 stuff.

		for (int i = left; i <= right; ++i)
		{
			int temp = std::move(data[i]);
			int j = i;
			for (; j > 0 && temp < data[j - 1]; --j)
			{
				std::swap(data[j], data[j - 1]);
			}


			//insert everything bigger one unit forward, and move temp in.
			std::swap(data[j], temp);
		}
	}

}

int median3(std::vector<int>& data, int left, int right)
{

	int middle = (right + left) / 2;
	if (data[left] > data[right])
	{
		std::swap(data[right], data[left]);
	}

	if (data[left] > data[middle])
	{
		std::swap(data[left], data[middle]);
	}

	if (data[middle] > data[right])
	{
		std::swap(data[middle], data[right]);
	}

	std::swap(data[middle], data[right - 1]);

	return data[right - 1];

	
}

void printVec(const std::vector<int>& data)
{

	if (data.size() == 0)
	{
		return;
	}
	std::cout << "[";
	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << ",";
	}

	std::cout << data[data.size() - 1] << "]\n";
}

void evaluateAlgoritm(std::vector<int> data, std::function<void(std::vector<int>&)> alogorithm, const std::string& nsg, bool printResult)
{
	auto startTime = std::chrono::high_resolution_clock::now();
	alogorithm(data);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - startTime);
	std::cout << nsg << " took " <<  duration.count() << " ms " << std::endl;

	if (printResult)
	{
		printVec(data);
	}

}
