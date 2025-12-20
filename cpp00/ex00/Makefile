NAME = megaphone
FLAGS = -Wall -Werror -Wextra -std=c++20

SRCS = megaphone.cpp
OBJS = megaphone.o

.SECONDARY: $(OBJS)

all: $(NAME)

%.o: %.cpp
	c++ -c $< $(FLAGS) -o $@

$(NAME): $(OBJS)
	c++ $< $(FLAGS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
