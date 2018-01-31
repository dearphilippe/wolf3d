# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passef <passef@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/23 22:58:59 by passef            #+#    #+#              #
#    Updated: 2018/01/30 20:27:06 by passef           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		libft.a
EXEC =		wolf3d
LIBFT =		lib/libft/libft.a
SDLIB =		lib/sdl2/lib/libSDL2.a

SRC =		srcs/wolf3d.c \
			lib/libft/ft_putstr.c \
			lib/libft/ft_putchar.c \

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
LFT = -C libft/
GREEN = \033[92m
PURPLE = \033[095m
NORM = \033[0m
ERASE = \033[K
CURSORUP = \033[1A

all: $(NAME)
$(NAME): $(OBJ)
	@echo "$(ERASE)$(PURPLE)[Wolf] :$(NORM) $(GREEN)Creating Library$(NORM) $(CURSORUP)";
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@$(CC) $(FLAGS) srcs/wolf3d.c $(NAME) $(SDLIB) -o $(EXEC)
	@echo "$(ERASE)$(PURPLE)[Wolf] :$(NORM) $(GREEN)Wolf Compiled!$(NORM)";
%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(ERASE)$(PURPLE)[Wolf] :$(NORM) $(GREEN)Compiling $<$(NORM) $(CURSORUP)";
clean:
	@$(RM) $(OBJ)
	@cd libft && make clean
	@echo "$(ERASE)$(PURPLE)[Wolf] :$(NORM) $(GREEN)Cleaning Object files $(NORM)";
fclean: clean
	@$(RM) $(NAME)
	@echo "$(ERASE)$(PURPLE)[Wolf] :$(NORM) $(GREEN)Cleaning Wolf $(NORM)";
re: fclean all