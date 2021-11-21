NAME    := a.out
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS    := main.cpp
OBJS    := $(SRCS:.cpp=.o)

.PHONY  : all
all     : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	$(RM) $(OBJS)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test: $(NAME)
	./a.out

.PHONY: debug
debug: CXXFLAGS += -std=c++98 -pedantic -g -fsanitize=address
debug: re
