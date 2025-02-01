##
## EPITECH PROJECT, 2025
## PDGRUSH3
## File description:
## Makefile
##

NAME	=	MyGKrellm
SRC	=	$(wildcard ./*.cpp ./src/*.cpp ./src/Display/*.cpp ./src/Module/*.cpp ./src/Data/*.cpp)
CFLAGS	=	-Wall -Wextra -Werror -Iinclude -Isrc -Isrc/Display -Isrc/Module -I. -Isrc/Data
LDFLAGS	=	-lncurses -lsfml-graphics -lsfml-window -lsfml-system
CC	=	/usr/bin/g++

all:	$(NAME)

$(NAME):	$(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) *.gch src/*.gch src/Display/*.gch src/Module/*.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re