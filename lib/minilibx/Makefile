# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passef <passef@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 10:33:48 by passef            #+#    #+#              #
#    Updated: 2018/01/29 10:34:58 by passef           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2
GREEN = \033[92m
PURPLE = \033[095m
NORM = \033[0m
ERASE = \033[K
CURSORUP = \033[1A

all: $(NOM)

$(NOM):	$(OBJ)
	@echo "$(ERASE)$(PURPLE)[Wolf] :$(NORM) $(GREEN)Creating MLX Library$(NORM) $(CURSORUP)";
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
