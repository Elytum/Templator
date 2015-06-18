# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC = clang++
CFLAGS = -Wall -Wextra -Werror
#--------------Name-------------------------#
NAME = templator
BIN_PATH = /nfs/zfs-student-3/users/2014/achazal/.brew/bin/
#--------------Sources----------------------#
SRCS =	templator.cpp	\
		generator.cpp

INC = -I./

OBJS	=	$(SRCS:.cpp=.o)

#--------------Actions----------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)
	cp $(NAME) $(BIN_PATH)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, fclean, clean, re 
