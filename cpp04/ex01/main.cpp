#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Color.hpp"
#include "Dog.hpp"

#define SIZE 4
#define INDEX 0

static void colorStart(const char *color) { std::cout << color; }

static void colorEnd() { std::cout << END; }

static void animalClear(Animal *animal[SIZE])
{
    for (int i = INDEX; i < SIZE; i++)
    {
        delete animal[i];
    }
}

static void animalInit(Animal *animal[SIZE])
{
    for (int i = INDEX; i < SIZE / 2; i++)
    {
        animal[i] = new Dog();
    }
    for (int j = SIZE / 2; j < SIZE; j++)
    {
        animal[j] = new Cat();
    }
}

static void brainTestCat()
{
    Cat cat1, cat2;
    std::string str = "hello";
    cat1.setIdeas(INDEX, str);
    cat2 = cat1;
    colorStart(YELLOW);
    std::cout << "cat1 ideas[" << INDEX << "] = " << cat1.getIdeas(INDEX) << std::endl;
    std::cout << "cat2 ideas[" << INDEX << "] = " << cat2.getIdeas(INDEX) << std::endl;
    colorEnd();
    str = "world";
    cat2.setIdeas(INDEX, str);
    colorStart(CYAN);
    std::cout << "-----DeepCopy-----" << std::endl;
    std::cout << "ideas[" << INDEX << "] :" << std::endl;
    std::cout << "cat1 ideas = " << cat1.getIdeas(INDEX) << std::endl;
    std::cout << "cat2 ideas = " << cat2.getIdeas(INDEX) << std::endl;
    colorEnd();
}

static void brainTestDog()
{
    Dog dog1, dog2;
    std::string str = "hello";
    dog1.setIdeas(INDEX, str);
    dog2 = dog1;
    colorStart(YELLOW);
    std::cout << "dog1 ideas[" << INDEX << "] = " << dog1.getIdeas(INDEX) << std::endl;
    std::cout << "dog2 ideas[" << INDEX << "] = " << dog2.getIdeas(INDEX) << std::endl;
    colorEnd();
    str = "world";
    dog2.setIdeas(INDEX, str);
    colorStart(CYAN);
    std::cout << "-----DeepCopy-----" << std::endl;
    std::cout << "ideas[" << INDEX << "] :" << std::endl;
    std::cout << "dog1 ideas = " << dog1.getIdeas(INDEX) << std::endl;
    std::cout << "dog2 ideas = " << dog2.getIdeas(INDEX) << std::endl;
    colorEnd();
}

int main()
{
    Animal *animal[SIZE];

    animalInit(animal);
    animalClear(animal);

    std::cout << "\n-----Cat Brain test-----\n" << std::endl;
    brainTestCat();
    std::cout << "\n-----Dog Brain test-----\n" << std::endl;
    brainTestDog();
    return 0;
}
