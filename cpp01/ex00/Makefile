NAME    := zombie
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS    := Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
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

.PHONY: debug
debug: CXXFLAGS += -g -fsanitize=address
debug: re
