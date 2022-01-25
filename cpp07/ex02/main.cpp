#include <iostream>

#include "Array.hpp"
#include "Array_test.hpp"

int main(void)
{
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

    return 0;
}
