NAME = identify
FLAGS = -Wall -Wextra -Werror -std=c++20

HEADERS = Base.hpp A.hpp B.hpp C.hpp identify.hpp

SRCS = main.cpp Base.cpp identify.cpp
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
