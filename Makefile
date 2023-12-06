
NAME		= fdf

LIBMLX		= ./lib/MLX42
LIBS		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADERS		= -I ./include -I $(LIBMLX)/include
SRCS		= ./src/main.c ./src/ft_read.c ./src/ft_draw.c ./src/utils.c
OBJS		= $(SRCS:.c=.o)

CC			= gcc
INCLUDES	= -Imlx
FLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

GT 			= git clone git@github.com:AlexHanchak/lib.git

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all:		$(NAME)

lib:
	$(GT) $@"ft"

$(NAME):	$(OBJS)
	@$(MAKE) -C ./mlx
	@$(MAKE) -C ./libft
	@$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit ./libft/libft.a -o $(NAME) 

clean:
	@$(MAKE) -C ./libft fclean
	@$(RM) $(OBJS)

fclean:		clean
	@$(RM) $(NAME) 

re:	fclean all

norm:
	@norminette $(SRCS)

.PHONY: all .c.o clean fclean re norm
