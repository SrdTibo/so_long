NAME = so_long.out
CFLAGS = -Wall -Wextra -Werror
SRC	= 	main.c graphical/display_images.c verif_map/check_end.c verif_map/verif_basic.c verif_map/verif_wall.c\
utils/map_to_tab.c utils/info_map.c graphical/display_map.c graphical/inputs.c graphical/verif_move.c\
gnl/get_next_line_utils.c gnl/get_next_line.c\
libft/ft_calloc.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_strtrim.c libft/ft_strdup.c libft/ft_strlen.c\
libft/ft_isalnum.c libft/ft_isprint.c \
libft/ft_memmove.c libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c libft/ft_isalpha.c\
libft/ft_memchr.c libft/ft_memset.c \
libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c libft/ft_isascii.c libft/ft_memcmp.c\
libft/ft_strchr.c libft/ft_strlcpy.c \
libft/ft_strrchr.c libft/ft_toupper.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c\
libft/ft_putchar_fd.c libft/ft_putstr_fd.c\
libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_strcat.c\
ft_printf/ft_extra_function.c ft_printf/ft_print_c.c ft_printf/ft_print_d.c ft_printf/ft_printf.c\
ft_printf/ft_print_i.c ft_printf/ft_print_modulo.c ft_printf/ft_print_p.c ft_printf/ft_print_s.c\
ft_printf/ft_print_u.c ft_printf/ft_print_x.c ft_printf/ft_print_xbis.c\

OBJ	= $(SRC:.c=.o)

all : 		$(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(OBJ) MLX42-C/libmlx42.a -I include -lglfw -L "/Users/tserdet/.brew/opt/glfw/lib/" -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean :	clean
	rm -f $(NAME) so_long.out

re :		fclean all

.PHONY :	all clean fclean re

# git clone https://github.com/SrdTibo/MLX42-C
# curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
# brew update
# brew install glfw
