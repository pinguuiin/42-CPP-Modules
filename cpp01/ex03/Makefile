NAME = attackmachine
FLAGS = -Wall -Wextra -Werror -std=c++20

HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)

.SECONDARY: $(OBJS)

all: $(NAME)

%.o: %.cpp $(HEADERS)
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(FLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
