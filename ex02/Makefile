CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = PmergeMe
SRC =	main.cpp\
		src/PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all : $(NAME)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
