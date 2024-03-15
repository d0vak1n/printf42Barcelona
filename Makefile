# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 11:31:29 by ramoreno          #+#    #+#              #
#    Updated: 2024/02/29 11:37:02 by ramoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Names
NAME=libprintf.a
LIBFT=libft.a

## Compile command
CC=gcc
CFLAGS=-Wall -Wextra -Werror

FILES=ft_printf.c ft_putchar_pf.c
LIBFTPATH=./libft

OBJS=$(patsubst %.c, %.o, $(FILES))

$(NAME): $(OBJS) Makefile libprintf.h makelibft
	@echo "\n📝 Creating library... $(NAME) 📝\n"
	ar -rvs $@ $<
	@echo "\n📖 $(NAME) created succesfully 📖\n"

all: $(NAME)

makelibft:
	@make -C $(LIBFTPATH)
	@cp $(LIBFTPATH)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

test: $(OBJS) test.c $(NAME)
	@echo "\n ❗️❗️ Compiling all the files... ❗️❗️ \n"
	$(CC) $(CFLAGS) $@.c $(OBJS) $(NAME) -o $@
	@make clean
	@echo "\n 🐁 Executing test... 🐁 \n"
	@./$@

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTPATH) && make clean
	@echo "\n 🗑 All .o deleted 🗑\n"

fclean: clean
	@rm -rf $(NAME)
	@cd $(LIBFTPATH) && make fclean
	@echo "\n 🗑 All .a deleted 🗑\n"

re: fclean all
	@echo "\n🔁 Relinked 🔁\n"

.PHONY: all clean fclean re

## @ left, $^ right