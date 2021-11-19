NAME    := account
CXX     := clang++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS    := Account.cpp tests.cpp
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

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=address
debug: re
