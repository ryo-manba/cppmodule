template <typename T>
void testIndexer(Array<T> arr, long idx)
{
    std::cout << "-----" << __func__ << " -----" << std::endl;
    std::cout << "size: " << arr.size() << std::endl;
    std::cout << "idx : " << idx << std::endl;

    std::cout << "arr[" << idx << "] is ";
    try
    {
        std::cout << arr[idx] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

template <typename T>
void testSize(Array<T> arr, const std::string& name)
{
    std::cout << "-----" << __func__ << "-----" << std::endl;
    std::cout << name << " : ";
    std::cout << arr.size() << std::endl;
}

template <typename T>
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
