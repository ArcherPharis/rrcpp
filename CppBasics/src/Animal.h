#pragma once
#include <string>
class Animal
{
public:

	//default constructor
	Animal();

	//custom constructur, whenever there is a way to call the function with 1 argument, add explicit.
	explicit Animal(const std::string& name, float energy);


	//THE BIG 5 / Rule of 5.
	//deconstructor
	virtual ~Animal();

	//copy/creation constructur
	Animal(const Animal& rhs);


	//move constructor
	Animal(Animal&& rhs) noexcept;


	//copy assignment operator, allows you to assign explicit constructurs.
	Animal& operator=(const Animal& rhs);

	//move assignement operator
	Animal& operator=(Animal&& rhs) noexcept;



	//setter, mutator
	void setName(const std::string& newName)
	{
		name = newName;
	}

	//accessor, getter
	std::string getName() const 
	{ return name; }

	static int getCount()
	{
		return count;
	}

	 void makeSound();
private:
	std::string name;
	float energy;
	static int count;

	//virtual almost always means a child class is expected, or this class is meant to be based on.
	virtual void makeSoundImpl();

protected:




};

class Dog : public Animal
{
public:
	Dog(const std::string& ownerName, float energy);
	virtual ~Dog() override;
private:
	std::string owner;
	virtual void makeSoundImpl() override;
};

