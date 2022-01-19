#!/bin/bash

f(){
	echo "---------------------"
	echo -e "arg    :$@\n"
	./convert "$@"
}

make

echo "-----INVALID ARGS-----"
f 1 1
f +-1
f helloworld
f .f
f -.1
f +.1
f 0..1
f 1..f

echo "-----NAN INF TEST-----"
f nan
f +inf
f -inf
f nanf
f +inff
f -inff

echo "-----CHAR TEST-----"
f a
f z
f %
f !

echo "-----INT TEST-----"
f 42
f -42
f 2147483647
f 2147483648
f -2147483648

echo "-----FLOAT TEST-----"
f 42.0f
f -42.0f
f 2147483647.0f
f 2147483648.0f
f -2147483648.0f

f 42f
f -42f
f 2147483647f
f 2147483648f
f -2147483648f

echo "-----DOUBLE TEST-----"
f 42.0
f -42.0
f 2147483647.0
f 2147483648.0
f -2147483648.0
