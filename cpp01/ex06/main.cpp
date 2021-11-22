#include "Karen.hpp"

#include <iostream>

int main(int argc, char **argv)
{
    Karen karen;

    if (argc != 2)
    {
        std::cout << "Usage: DEBUG / INFO / WARNING / ERROR" << std::endl;
        return (1);
    }

    karen.complain(argv[1]);
    return (0);
}
