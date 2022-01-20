#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t row)
{
    return reinterpret_cast<Data*>(row);
}

// Data : name, value
// std::hex, std::dec is c++03
int main(void)
{
    Data d("data", 42);
    d.Print();

    std::cout << "------serialize------" << std::endl;
    uintptr_t uptr = serialize(&d);

//    std::cout << "address : 0x" << std::hex << uptr << std::dec << std::endl;
    std::cout << "-----deserialize-----" << std::endl;
    Data* dp = deserialize(uptr);
    dp->Print();

    std::cout << "------serialize------" << std::endl;
    Data* p = NULL;
    std::cout << "address : " << p << std::endl;
    uptr = serialize(NULL);
//    std::cout << "address : 0x" << std::hex << uptr << std::dec << std::endl;
    p = deserialize(uptr);
    std::cout << "-----deserialize-----" << std::endl;
    std::cout << "address : " << p << std::endl;

    return 0;
}

