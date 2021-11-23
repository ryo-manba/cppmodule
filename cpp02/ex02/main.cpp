// #include "Fixed.hpp"
// #include <iostream>

// int main( void ) {

//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;

//     return 0;
// }

#include "Fixed.hpp"
#include <iostream>
using namespace std;

int main( void ) {

    Fixed a(10);
    Fixed b(2.5f);
    Fixed c(0);

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    return 0;
}
