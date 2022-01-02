# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 14:08:26 by oabdelfa          #+#    #+#              #
#    Updated: 2022/01/03 00:26:22 by rodrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FNAMES	:=	main reading bitwise1 bitwise2 checking printing solve_utils \
			solving debug

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
	@make -sC libft

clean:
	@rm -rf $(OBJS_DIR)
	@make -sC libft clean

fclean: clean
	@rm -f $(NAME)
	@make -sC libft fclean

re: fclean all

.PHONY:	all clean fclean re
