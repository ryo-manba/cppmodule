NAME    := a.out
CXX     := clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS    := main.cpp
OBJS    := $(SRCS:.cpp=.o)

all     : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY  : all clean fclean re test

test: $(NAME)
	./a.out

debug: CXXFLAGS += -g -fsanitize=address
debug: re

.PHONY  : test debug
