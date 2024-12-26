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
	Animal** animals;	//���� �迭
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
	//�ҿ����� Ÿ���� ������ �����ֱ⿡ ���� ������ 1����Ʈ ������ �־� �ذ�
	char _;

public:
	Animal* createRandomAnimal();
};