# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 18:56:39 by lbenamer          #+#    #+#              #
#    Updated: 2016/11/21 21:02:44 by lbenamer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC		=		ft_atoi.c \
				ft_malloctab.c \
				ft_lstdel.c \
				ft_print_int_tab.c \
				ft_printstab.c \
				ft_realloc.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstadd.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_size_tab.c \
				ft_isprint.c \
				ft_memalloc.c \
				ft_memset.c \
				ft_lstdelone.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
   				ft_putstr.c \
				ft_putstr_fd.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
   				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strlcat.c \
   				ft_strlen.c \
				ft_strjoin.c \
				ft_strncat.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_lstnew.c \
				ft_toupper.c \
				ft_strjoin_f.c \
				ft_swap_c.c \
				ft_strlen_p.c \
				joinstr.c \
				ft_strrev.c \
				ft_utoa_hex.c \
				ft_litoa.c \
				flags.c \
				options.c \
				save.c \
   				save2.c \
   				get_next_line.c \
				fcp.c \
				fixops.c \
				precis.c \
				ft_strsub_f.c \
				ft_strchr.c \
				ft_strupper.c \
				ft_tolower.c \
				unicode.c \
				ft_getwstr.c \
				conv.c \
				conv2.c \
				ft_printf.c 
   				
OBJ		=		$(SRC:.c=.o)

NAME	=		libft.a

CFLAGS		=		-Wextra -Wall -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
			rm -f $(OBJ)

fclean:  	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re		
