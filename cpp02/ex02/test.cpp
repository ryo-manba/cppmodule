#include "Fixed.hpp"
#include <iostream>
using namespace std;

int main( void ) {

    Fixed a(10);
    Fixed b(10);
//    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    cout << a + b << endl;
    return 0;
}
