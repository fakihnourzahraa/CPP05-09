NAME = easyfind

SRC =  main.cpp
OBJ = $(SRC:.cpp=.o)

CC  = c++ -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^
	@echo "🏂 done making"

%.o: %.cpp
	@$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "💄 done cleaning"

fclean: clean
	@rm -f $(NAME)
	@echo "👺 done fcleaning"

re: fclean all

ex: all clean

.PHONY: all clean fclean re