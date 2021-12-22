# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatias <tmatias@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 12:26:37 by tmatias           #+#    #+#              #
#    Updated: 2021/09/29 16:32:34 by tmatias          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
INC = -I./inc
SRC_NAMES = ft_abs.c\
				ft_char_count.c\
				ft_lstdelone.c\
				ft_putstr_fd.c\
				ft_atoi.c\
				ft_lstiter.c\
				ft_split.c\
				ft_bzero.c\
				ft_string_is_positive_number.c\
				ft_lstlast.c\
				ft_strchr.c\
				ft_calloc.c\
				ft_lstmap.c\
				ft_strdup.c\
				ft_gnl.c\
				ft_exit.c\
				ft_lstnew.c\
				ft_strjoin.c\
				ft_isalnum.c\
				ft_lstsize.c\
				ft_strlcat.c\
				ft_isalpha.c\
				ft_memccpy.c\
				ft_strlcpy.c\
				ft_isascii.c\
				ft_memchr.c\
				ft_strlen.c\
				ft_isdigit.c\
				ft_freecharmatrix.c\
				ft_memcmp.c\
				ft_strmapi.c\
				ft_isprint.c\
				ft_memcpy.c\
				ft_strncmp.c\
				ft_itoa.c\
				ft_memdel.c\
				ft_strnstr.c\
				ft_itoa_base.c\
				ft_memmove.c\
				ft_strrchr.c\
				ft_itoa_base_unsigned.c\
				ft_memset.c\
				ft_strtrim.c\
				ft_lstadd_back.c\
				ft_putchar_fd.c\
				ft_substr.c\
				ft_lstadd_front.c\
				ft_putendl_fd.c\
				ft_tolower.c\
				ft_lstclear.c\
				ft_putnbr_fd.c\
				ft_toupper.c

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))

OBJ_DIR = obj
OBJ_NAMES = $(SRC_NAMES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

.PHONY: all, clean, fclean, re

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\t[ $(GREEN)✔$(NONE) ] libft/$(NAME) library"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@echo "\t[ $(GREEN)✔$(NONE) ] libft/$(OBJ_DIR) directory"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) $(INC) -c $< -o $@

clean:
	@rm -Rf $(OBJ_DIR)
	@echo "\t[ $(RED)✗$(NONE) ] libft/$(OBJ_DIR) directory"

fclean: clean
	@rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] libft/$(NAME) library"

re: fclean all