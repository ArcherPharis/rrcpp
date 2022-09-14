#pragma once
#include <memory>
#include <initializer_list>

//a dynamic array to store data

template<typename T>
class DArray
{
	//new stores something on the heap memory, which is slightly slower.
	//delete removes that memory.

public:
	explicit DArray(unsigned int size = 0)
		: _size{size}, _capacity{size + SPARE_CAPACITY}, _array{new T[_capacity]}{}


	//initializer list
	DArray(std::initializer_list<T> list)
		:_size{ 0 }, _capacity{ SPARE_CAPACITY }, _array{ new T[_capacity] }
	{
		for (auto item : list)
		{
			add(item);
		}
	}

	~DArray()
	{
		delete[] _array;
	}

	//copy con (deep copy)
	DArray(const DArray& rhs)
		: _size{rhs.size}, _capacity{rhs._capacity}, _array{ new T[_capacity]}
	{
		for (int i = 0; i < _size; ++i)
		{
			_array[i] = rhs._array[i];
		}
	}
	//move con (shallow copy)
	DArray(DArray&& rhs)
		: _size{rhs.size}, _capacity{rhs._capacity}, _array{rhs._array}
	{
		rhs._array = nullptr;
		rhs._capacity = 0;
		rhs._size = 0;
	}

	//move assignment operator
	DArray& operator=(DArray&& rhs)
	{
		_size = std::move(rhs._size);
		_capacity = std::move(rhs._capacity); 
		_array = std::move(rhs._array);
		return *this;
	}
	//copy assignment operator, requires move assignment operator
	DArray& operator=(const DArray& rhs)
	{
		//copy 
		DArray Temp = rhs;
		//and swap
		std::swap(*this, Temp);
		return *this;
	}
	T& operator[](int index)
	{
		return _array[index];
	}

	int size() const
	{
		return _size;
	}

	void add(const T& item)
	{
		if (_size == _capacity)
		{
			reserve(_size * 2 + 1);
		}

		_array[_size] = item;
		_size++;
	}

	void reserve(unsigned int newCapacity)
	{
		if (newCapacity <= _capacity)
			return;

		T* newArray = new T[newCapacity];
		for (int i = 0; i < _size; ++i)
		{
			newArray[i] = std::move(_array[i]);
		}
		std::swap(_array, newArray);
		delete[] newArray;
		_capacity = newCapacity;
	}

	void remove(int removeAt)
	{
		for (int i = removeAt; i < _size; ++i)
		{
			_array[i] = std::move(_array[i + 1]);
		}
		--_size;
	}
private:
	
	unsigned int _size; //only positive numbers
	unsigned int _capacity;
	T* _array;
	const static unsigned int SPARE_CAPACITY = 10;
};

