NAME = banklog
FLAGS = -Wall -Wextra -Werror

HEADERS = Account.hpp

SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)

.SECONDARY: $(OBJS)

all: $(NAME)

tests.o: tests.cpp
	c++ $(FLAGS) --std=c++98 -c $< -o $@

Account.o: Account.cpp
	c++ $(FLAGS) --std=c++20 -c $< -o $@


# %.o: %.cpp $(HEADERS)
# 	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(FLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
