CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = btc
SRC =	main.cpp\
		src/BitcoinExchange.cpp

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
