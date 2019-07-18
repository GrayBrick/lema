# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmurch <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 16:44:35 by kmurch            #+#    #+#              #
#    Updated: 2018/12/09 15:06:22 by kmurch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS	= -Wall -Werror -Wextra -Iincludes -c
FILES		= *.c
OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(FILES)
	@gcc $(CFLAGS) $(FILES)

clean:	
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all	
