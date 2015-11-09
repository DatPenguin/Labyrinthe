NAME = labyrinthe
CC = gcc
CFLAGS = -W -Wall -Wextra -Iinclude
LDFLAGS = -L.
SRC = $(shell find -type f -name "*.c")
OBJ = $(SRC:.c=.o)
RM = rm -rf

all: hello $(NAME)

$(NAME): $(OBJ)
	@printf "\033[1;1;34m"
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
	@printf "\033[0m"

clean:
	@printf "\033[5;1;31m"
	$(RM) $(OBJ)
	@printf "\033[0m"

fclean:	clean
	@printf "\033[5;1;31m"
	$(RM) $(NAME)
	@printf "\033[0m"

re: fclean all

hello:
	@printf "Compilation du $(NAME) en cours...\n"
	@sleep 1

.PHONY: all re clean fclean
