

int fakeMain()
{

	/**means variable is a pointer, & means the address of.
		int num = 65;
	int* numPointer = &num;
	so what's the advantage of a pointer?
		asterisk the dereferencer.
		std::cout << "the value at memory address: " << numPointer << "is " << *numPointer << '\n';

	increments the pointer by the size of the type the pointer points to.
		numPointer++;

	casting can covert one type to another, the most raw way to convert is c style cast
		char* numAsChar = (char*)numPointer;
	char asChar = (char)num;

	cout << *numAsChar;
	cout << asChar;

	first variable we have created with new keyword, which is on the heep.
		heep memory is big, but slower than stack.Can only be retrieved with pointers
		int* heepIntPtr = new int{ 10 };
	std::cout << "the value at " << heepIntPtr << "is: " << *heepIntPtr << endl;

	when heep memory is no longer needed, they should be manually deleted by calling delete
		additionally, we can set the pointer to nullptr.Setting it to nullptr does not delete it.
		delete heepIntPtr;
	heepIntPtr = nullptr;

	int* heepIntArray = new int{ 10 };

	for (int i = 0; i < 10; ++i)
	{
		heepIntArray[i] = i;
	}
	delete[] heepIntArray;

	raw memory
		void* rawMem = malloc(4);
	int* rawAsInt = (int*)rawMem;
	*rawAsInt = 12;
	std::cout << rawAsInt;

	casting is dangerous, if you are using casting, try find an alternative.

		4 casting methods :
	char* chaPointer = new char{ 'a' };
	void* rawPointer = malloc(1);

	reinteperet cast, will reinterperate the in a raw style
		int* charAsInt = reinterpret_cast<int*>(rawPointer);

	static_cast, it casts the typeand make sure the types are in the hierachy, makes sure the types are conversable.
		int* charAsIntTwo = static_cast<int*>(rawPointer);

	dynamic_cast will check class hierachy, and if the cast is possible, return the pointer, and if not, return nullptr.
		it is checked in runtime.

		const_cast, cast out the const
		const int constVar = 1;
	int* notConstAnyMore = const_cast<int*>(&constVar);

	64 bit holds more addresses than 32 bit.As well as longer addresses, allowing for more info.*/
	return 0;
}