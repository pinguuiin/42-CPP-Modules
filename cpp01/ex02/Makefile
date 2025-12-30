NAME = isbrain
FLAGS = -Wall -Werror -Wextra -std=c++20

SRCS = main.cpp
OBJS = main.o

.SECONDARY: $(OBJS)

all: $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(FLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
