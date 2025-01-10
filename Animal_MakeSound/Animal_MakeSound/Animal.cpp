#include <string>
#include <iostream>

using namespace std;


class Zoo
{
public:
	Animal* animals[10]{nullptr};
	// 동물 추가 함수, Animal 객체 포인터를 받아 포인터 배열에 저장, 같은 동물 여러 번 가능
	void addAnimal(Animal* animal) {};
	// 행동 수행, 순차적으로 실행
	void performActions() {};
	~Zoo() {};

private:
	Animal* animals[10];
};

class Animal
{
public:
	Animal() {};  // 생성자
	virtual void makeSound() {};  // 가상 함수
};

class Dog : public Animal
{
public:
	Dog(string word) : m_word(word) {};
	void makeSound() override { cout << "Dog : " << m_word << endl; };

private:
	string m_word;  // 멤버 변수
};

class Cat : public Animal
{
public:
	Cat(string word) : m_word(word) {};
	void makeSound() override { cout << "Cat : " << m_word << endl; };

private:
	string m_word;
};

class Cow : public Animal
{
public:
	Cow(string word) : m_word(word) {};
	void makeSound() override { cout << "Cow : " << m_word << endl; };

private:
	string m_word;
};

void print(Animal* animal)
{
	animal->makeSound();
}

int main()
{
	Dog dog("mong mong");
	Cat cat("myaaaaong");
	Cow cow("mmmmmoooo");

	Animal* animals[] = { &dog, &cat, &cow };
	int animals_count = sizeof(animals) / sizeof(animals[0]);

	for (int i = 0; i < animals_count; i++)
	{
		print(animals[i]);
	}

	return 0;
}