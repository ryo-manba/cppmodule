#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string str;
    size_t len;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            str = argv[i];
            len = str.length();
            for (size_t j = 0; j < len; j++)
            {
                str[j] = std::toupper(str[j]);
            }
            std::cout << str;
        }
        std::cout << std::endl;
    }
    return 0;
}