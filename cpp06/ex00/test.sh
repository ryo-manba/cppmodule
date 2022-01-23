#!/bin/bash
CYAN="\033[36m"
YELLOW="\033[1;33m"
RESET="\033[0m"

print_color()
{
	echo -en $1
	echo $2
	echo -en $RESET
}

func()
{
	print_color $CYAN "./convert $@"
	./convert "$@"
	echo
}

# make
make

print_color $YELLOW "-----INVALID ARGS-----"
func 1 1
func +-1
func helloworld
func .f
func -.1
func +.1
func 0..1
func 1..f

print_color $YELLOW "-----NAN INF TEST-----"
func nan
func +inf
func -inf
func nanf
func +inff
func -inff

print_color $YELLOW "-----CHAR TEST-----"
func a
func z
func %
func !
func " "
func \t

print_color $YELLOW "-----INT TEST-----"
func 42
func -42
func 2147483647
func 2147483648
func -2147483648

print_color $YELLOW "-----FLOAT TEST-----"
func 42.0f
func -42.0f
func 2147483647.0f
func 2147483648.0f
func -2147483648.0f

func 42f
func -42f
func 2147483647f
func 2147483648f
func -2147483648f

print_color $YELLOW "-----DOUBLE TEST-----"
func 42.0
func -42.0
func 2147483647.0
func 2147483648.0
func -2147483648.0
