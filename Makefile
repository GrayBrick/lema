# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmurch <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 14:09:46 by kmurch            #+#    #+#              #
#    Updated: 2019/07/18 18:12:01 by kmurch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

SRC		= lemin.c\
		  oper0.c\
		  oper1.c\
		  oper2.c\
		  oper3.c\
		  oper4.c\
		  oper5.c\
		  alg0.c\
		  alg1.c\
		  struct.c\

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC      = gcc
CF      = -Wall -Wextra -Werror

LIBFT   = ./libft/libft.a
LIBINC  = -I./libft
LIBLINK = -L./libft -lft

SRCDIR  = ./src/
INCDIR  = ./inc/
OBJDIR  = ./obj/

all: obj libft $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CF) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJ)
	@$(CC) $(CF) $(LDFLAGS) -o $(NAME) $(OBJ) $(LIBLINK)

clean:
	@rm -rf $(OBJDIR)
	@make -C ./libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean all
