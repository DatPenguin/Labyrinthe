
NAME = labyrinthe
CC = gcc
CFLAGS = -W -Wall -Wextra -Iinclude
LDFLAGS = -L.
SRC = $(shell find -type f -name "*.c")
OBJ = $(SRC:.c=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
