#include <iostream>

#include "Convert.hpp"

#define USAGE "Usage: ./convert <value>"

void printUsage(void)
{
    std::cout << USAGE << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printUsage();
        return 1;
    }
    Convert cv(argv[1]);
    return 0;
}
