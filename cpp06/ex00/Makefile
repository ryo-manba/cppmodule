NAME    := convert
CXX     := clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS    := Convert.cpp main.cpp
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
	./$(NAME)

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=address
debug: re
