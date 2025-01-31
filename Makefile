##
## EPITECH PROJECT, 2025
## PDGRUSH3
## File description:
## Makefile
##

NAME=UwU
SRC=$(wildcard ./*.cpp ./src/*.cpp ./src/Display/*.cpp ./src/Module/*.cpp)
CFLAGS=-Wall -Wextra -Werror -Iinclude -Isrc -Isrc/Display -Isrc/Module -I.
CC=/usr/bin/g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) *.gch src/*.gch src/Display/*.gch src/Module/*.gch

fclean: clean
	rm -f $(NAME)

re: fclean all