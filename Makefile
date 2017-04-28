#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/18 18:16:40 by lbenamer          #+#    #+#              #
#    Updated: 2016/12/06 05:07:31 by lbenamer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC      =   gcc
RM      =   rm -f
CFLAGS  =  -Wall -Werror -Wextra
LIB		=	-L./libft -lft
NAME    =   lsd
SRCS    =   src/ft_ls.c \
			src/main.c \
			src/parse.c \
			src/init.c \
			src/get.c \
			src/manlst.c \

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

push:
			@git add .
			@echo "Enter Your Commit :"
			@read var1 ; git commit -m "$$var1"
			@git push

.PHONY:     all clean fclean re push
