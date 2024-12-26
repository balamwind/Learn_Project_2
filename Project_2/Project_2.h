#pragma once


class Animal
{
public:
	void virtual makeSound() = 0;
	~Animal();
};

class Dog : public Animal
{
public:
	void makeSound() override;
};

class Cat : public Animal
{
public:
	void makeSound() override;
};

class Cow : public Animal
{
public:
	void makeSound() override;
};

class Zoo
{
private:
	Animal** animals;	//동적 배열
	int animalCount;

	const int animalCapacityStandard = 10;

public:
	Zoo();
	~Zoo();

	void addAnimal(Animal* animal);
	void performActions();
};

class Main
{
private:
	//불완전한 타입은 생성이 막혀있기에 제일 가벼운 1바이트 변수를 넣어 해결
	char _;

public:
	Animal* createRandomAnimal();
};