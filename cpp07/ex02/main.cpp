#include <iostream>

#include "Array.hpp"
#include "Array_test.hpp"

#define MAX_VAL 750

int testSubject(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

void testArray(void)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    Array<int> arr1;
    Array<int> arr2(10);
    Array<int> arr3(arr2);

    testSize(arr1, "arr1");
    testSize(arr2, "arr2");
    testSize(arr3, "arr3");
    std::cout << "\n( arr1 = arr2 )" << std::endl;
    arr1 = arr2;

    for (unsigned int i = 0; i < arr1.size(); ++i)
    {
        arr1[i] = i;
    }

    Print(arr1, "arr1");
    Print(arr2, "arr2");
    Print(arr3, "arr3");

    std::cout << "\n( arr2 = arr1 )" << std::endl;
    arr2 = arr1;
    Print(arr2, "arr2");

    std::cout << "\n( constArr(arr1) )" << std::endl;
    const Array<int> constArr(arr1);
    Print(constArr, "constArr");
    // Constants cannot be changed.
    // constArr[0] = 0;

    // Out of range
    testIndexer(arr1, -1);
    testIndexer(arr1, 42);
}

int main(void)
{
    testSubject();
    testArray();
    return 0;
}
