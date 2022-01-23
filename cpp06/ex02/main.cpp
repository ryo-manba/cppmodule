#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#define PRE_TYPE "Type is "
#define NOTFOUND "not found"

enum type
{
    kTypeA,
    kTypeB,
    kTypeC
};

Base* generate(void)
{
    int randomIdx = rand() % 3;
    Base* basePtr = NULL;

    switch (randomIdx)
    {
        case kTypeA:
            basePtr = new A;
            break;
        case kTypeB:
            basePtr = new B;
            break;
        case kTypeC:
            basePtr = new C;
            break;
        default:
            ;
    }
    return basePtr;
}

void identify(Base* p)
{
    std::string type = NOTFOUND;

    if (dynamic_cast<A*>(p))
    {
        type = "A";
    }
    else if (dynamic_cast<B*>(p))
    {
        type = "B";
    }
    else if (dynamic_cast<C*>(p))
    {
        type = "C";
    }
    std::cout << PRE_TYPE << type << std::endl;
}

void identify(Base& p)
{
    std::string type = NOTFOUND;

    try
    {
        A& dummy = dynamic_cast<A&>(p);
        static_cast<void>(dummy);
        type = "A";
    }
    catch (std::bad_cast& e)
    {
    }
    try
    {
        B& dummy = dynamic_cast<B&>(p);
        static_cast<void>(dummy);
        type = "B";
    }
    catch (std::bad_cast& e)
    {
    }
    try
    {
        C& dummy = dynamic_cast<C&>(p);
        static_cast<void>(dummy);
        type = "C";
    }
    catch (std::bad_cast& e)
    {
    }
    std::cout << PRE_TYPE << type << std::endl;
}

int main(void)
{
    std::srand(static_cast<unsigned>(std::time(NULL)));

    Base* basePtr;
    basePtr = generate();

    identify(basePtr);
    identify(*basePtr);

    Base base;
    identify(&base);
    identify(base);
    delete basePtr;
}
