NAME    := a.out
CXX     := clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS    := Animal.cpp Cat.cpp Dog.cpp main.cpp
OBJS    := $(SRCS:.cpp=.o)

all     : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

test: $(NAME)
	./a.out

.PHONY: debug test
debug: CXXFLAGS += -g -fsanitize=address
debug: re
