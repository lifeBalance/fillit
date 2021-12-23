# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 14:08:26 by oabdelfa          #+#    #+#              #
#    Updated: 2021/12/24 00:09:17 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FNAMES	:= main reading bitwise checking printing solving

OBJS_DIR	:=	./objs/

SRCS_DIR	:=	./srcs/

OBJS	:=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(FNAMES)))

LDFLAGS	=	-Llibft

LDLIBS	=	-lft

CFLAGS = -Wall -Wextra -Werror -I includes -I libft/includes

CC	= clang

all: $(NAME)

$(NAME): libft.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

libft.a:
	@make -sC libft && make -sC libft clean

clean:
	@rm -f $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
