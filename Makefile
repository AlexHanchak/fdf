# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohanchak <ohanchak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:56:26 by ohanchak          #+#    #+#              #
#    Updated: 2023/12/11 19:03:58 by ohanchak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= fdf

LIBFT 		= libft/libft.a
LIB_PATH 	= libft
HEADERS		= -I ./include -I $(LIBMLX)/include
SRCS		= ./src/main.c ./src/ft_read.c ./src/ft_draw.c ./src/utils.c
OBJS		= $(SRCS:.c=.o)

CC			= gcc
INCLUDES	= -Imlx
FLAGS		= -g -Wall -Wextra -Werror

RM			= rm -rf

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
	@$(MAKE) -C ./mlx
	@$(MAKE) -C ./libft
	@$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o $(NAME) 

$(LIBFT):
	git submodule update --init --recursive
	$(MAKE) -C $(LIBFT_PATH)

$(LIBFT):
	make -C $(@D) all

clean:
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJS)

fclean:		clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean

re:	fclean all

norm:
	@norminette $(SRCS) includes/

.PHONY: all .c.o clean fclean re norm
