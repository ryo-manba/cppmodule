NAME    := replace
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
	@./$(NAME) test.txt "hello" "HELLO"
	@echo "[CASE1] test.txt "hello" "HELLO"" > diff.txt
	@diff test.txt test.txt.replace >> diff.txt ; [ $$? -eq 1 ]
	@echo >> diff.txt
	@./$(NAME) test.txt "42" "24"
	@echo "[CASE2] test.txt "42" "24"" >> diff.txt
	@diff test.txt test.txt.replace >> diff.txt ; [ $$? -eq 1 ]
	@echo >> diff.txt
	@./$(NAME) test.txt "helloworld" "xxxx"
	@echo "[CASE3] test.txt  "helloworld" "xxxx"" >> diff.txt
	@diff test.txt test.txt.replace >> diff.txt ; [ $$? -eq 1 ]
	@cat diff.txt

.PHONY: debug
debug: CXXFLAGS += -std=c++98 -pedantic -g -fsanitize=address
debug: re
