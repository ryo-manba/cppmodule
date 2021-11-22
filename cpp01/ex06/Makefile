NAME    := karenFilter
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS    := Karen.cpp main.cpp
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
	./$(NAME) "WARNING"
	./$(NAME) "I am not sure how tired I am today..."

.PHONY: debug
debug: CXXFLAGS += -std=c++98 -pedantic -g -fsanitize=address
debug: re
