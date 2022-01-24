#include "Array.hpp"

template<typename T>
void testIndexer(Array<T> arr, long idx)
{
    std::cout << "-----" << __func__ << " -----" << std::endl;
    std::cout << "size: " << arr.size() << std::endl;
    std::cout << "idx : " << idx << std::endl;

    std::cout << "arr[" << idx << "] is ";
    try
    {
        std::cout << arr[idx] << std::endl;
    } catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

template<typename T>
void testSize(Array<T> arr, const std::string& name)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << name << " : ";
    std::cout << arr.size() << std::endl;
}

template<typename T>
void Print(Array<T> arr, const std::string& name)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << name << " : ";

    for (unsigned int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    Array<int> arr1;
    Array<int> arr2(10);
    Array<int> arr3(arr2);
    Array<char> arr4(5);

    testSize(arr1, "arr1");
    testSize(arr2, "arr2");
    testSize(arr3, "arr3");
    testSize(arr4, "arr4");
    arr1 = arr2;
    for (unsigned int i = 0; i < arr1.size(); ++i)
    {
        arr1[i] = i;
    }
    for (unsigned int i = 0; i < arr4.size(); ++i)
    {
        arr4[i] = static_cast<char>('a' + i);
    }

    Print(arr1, "arr1");
    Print(arr2, "arr2");
    Print(arr3, "arr3");
    Print(arr4, "arr4");

    std::cout << "arr2 = arr1" << std::endl;
    arr2 = arr1;
    Print(arr2, "arr2");


    // Out of range
    testIndexer(arr1, -1);
    testIndexer(arr1, 42);

    return 0;
}
