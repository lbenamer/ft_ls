#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 18:16:40 by mhaziza           #+#    #+#              #
#    Updated: 2016/12/06 05:07:31 by lbenamer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC      =   gcc
RM      =   rm -f
CFLAGS  =  -Wall -Werror -Wextra
LIB		=	-L./libft -lft
NAME    =   lsd
SRCS    =   src/ft_lst.c \
			src/test.c \
			src/parse.c \

OBJS    =   $(SRCS:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
			Make -C ./libft
			$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
			$(RM) $(OBJS)
			Make -C ./libft fclean

fclean:     clean
			$(RM) $(NAME)

re:         fclean all

.PHONY:     all clean fclean re
