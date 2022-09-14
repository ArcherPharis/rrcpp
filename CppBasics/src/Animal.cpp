#include "Animal.h"
#include <iostream>

// : var{} is called the initilization list
 Animal::Animal()
	: name{"no name"}, energy{0}
{
	 ++count;
}

 Animal::Animal(const std::string& name, float weight)
	 : name{name}, energy{weight}
 {
	 ++count;
 }

 Animal::~Animal()
 {
	 std::cout << "Animal was destroyed" << '\n';
 }
 Animal::Animal(const Animal& rhs)
	 :name{rhs.name}, energy{rhs.energy}
 {
	 std::cout << "copy con called, I get called on creation" << '\n';
 }
 Animal::Animal(Animal&& rhs) noexcept
	 : name{ std::move(rhs.name) }, energy {std::move(rhs.energy)}
 {
	 std::cout << "Mover con is called, I move values without destroying the original \n";
	 rhs.name = "";
	 rhs.energy = 0;
 }
 Animal& Animal::operator=(const Animal& rhs)
 {//we call for these because the object is already constructed.
	 name = rhs.name;
	 energy = rhs.energy;
	 std::cout << "operator called" << '\n';
	 return *this;
 }
 Animal& Animal::operator=(Animal&& rhs) noexcept
 { //we call for these because the object is already constructed.
	 name = std::move(rhs.name);
	 energy = std::move(rhs.energy);
	 return *this;
 }
 void Animal::makeSound()
 {
	 if (energy > 1)
	 {
		 std::cout << "animal sound";
		 makeSoundImpl();
	 }
 }
 void Animal::makeSoundImpl()
 {
	 std::cout << "animals makes a sound" << '\n';
 }
 int Animal::count = 0;

 Dog::Dog(const std::string& ownerName, float energy)
	 : Animal{"noname", 0}, owner{ownerName}
 {
	
 }

 Dog::~Dog()
 {
	 std::cout << "Dog destroyed" << '\m';
 }


 void Dog::makeSoundImpl()
 {
	 Animal::makeSound();
	 std::cout << "bork";
 }
