NAME = Bureaucrat
FLAGS = -Wall -Wextra -Werror -std=c++20

HEADERS = Bureaucrat.hpp \
		  AForm.hpp \
		  ShrubberyCreationForm.hpp \
		  RobotomyRequestForm.hpp \
		  PresidentialPardonForm.hpp \
		  Intern.hpp

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp \
	   Intern.cpp

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
