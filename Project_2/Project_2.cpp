#include "Project_2.h"
#include <iostream>
#include <vector>


using namespace std;

Animal::~Animal()
{
	cout << "Animal 소멸" << endl;
}

void Dog::makeSound()
{
	cout << "왈왈" << endl;
}

void Cat::makeSound()
{
	cout << "냐옹" << endl;
}

void Cow::makeSound()
{
	cout << "음머" << endl;
}


void Zoo::addAnimal(Animal* animal)
{
	if (animalCount % animalCapacityStandard == 0)
	{
		Animal** newArray = new Animal * [animalCapacityStandard * (1 + animalCount / animalCapacityStandard)];
		for (int i = 0; i < animalCapacityStandard * (animalCount / animalCapacityStandard); i++)
			newArray[i] = animals[i];

		delete[] animals;

		animals = newArray;
	}

	animals[animalCount] = animal;
	animalCount++;
}

void Zoo::performActions()
{
	for (int i = 0; i < animalCount; i++)
		animals[i]->makeSound();
}

Zoo::Zoo()
{
	animals = new Animal * [10];
	animalCount = 0;
}

Zoo::~Zoo()
{
	cout << "Zoo 소멸 시작" << endl;

	for (int i = 0; i < animalCount; i++)
		delete animals[i];

	delete[] animals;

	cout << "Zoo 소멸" << endl;
}

Animal* Main::createRandomAnimal()
{

	int random = rand() % 3;
	Animal* result = nullptr;
	switch (random)
	{
	case 0:
		result = new Dog();
		break;

	case 1:
		result = new Cat();
		break;

	case 2:
		result = new Cow();
		break;
	}

	return result;
}

int main()
{
	Animal* animals[3]{ new Dog(), new Cat(), new Cow() };
	for (int i = 0; i < 3; i++)
		animals[i]->makeSound();

	cout << endl;

	Zoo* zoo = new Zoo();
	Main m;

	cout << "동물 갯수 : ";

	int animalCount;
	cin >> animalCount;

	srand(time(NULL));
	for (int i = 0; i < animalCount; i++)
		zoo->addAnimal(m.createRandomAnimal());

	zoo->performActions();
	cout << endl;

	delete zoo;

	return 0;
}