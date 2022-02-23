NAME = minishell

CFLAGS = -Wall -Wextra -Werror 

SRC = main.c\
		trim.c\
		expand.c\
		subsplit.c\
		remove_quotes.c\
		parser.c\
		executor.c\
		exeve.c\
		readline.c
SRCSFD = srcs/
OBJSFD = objs/
OBJS = $(addprefix $(OBJSFD),$(SRC:.c=.o))

HDR = minishell.h
HDRSFD = includes/
HDRS = $(addprefix $(HDRSFD),$(HDR))

HDR_INC = -I./includes

LIBFT_HDR = -I./libft/inc
LIB_BINARY = -L./libft -lft
LIBFT= libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

all: check_libft $(NAME) $(HDRS)
	@echo "Compilation successful"

$(NAME): project $(OBJSFD) $(OBJS) $(LIBFT) $(HDRS)
	@gcc $(CFLAGS) $(OBJS) -lreadline $(LIB_BINARY) -o $@
	@echo "\t[ \033[0;32m✔\033[0m ] $(NAME) executable"

check_libft:
	@echo "Checking libft..."
	@make -C libft

project:
	@echo "Checking project..."

$(OBJSFD):
	@mkdir $@
	@echo "\t[ $(GREEN)✔$(NONE) ] objs/ directory"

$(OBJSFD)%.o: $(SRCSFD)%.c $(HDRS)
	@gcc $(CFLAGS) $(HDR_INC) $(LIBFT_HDR) -c $< -o $@
	@echo "\t[ $(GREEN)✔$(NONE) ] $@ object"

clean:
	@rm -rf $(OBJSFD)
	@echo "\t[ $(RED)✗$(NONE) ] $(OBJSFD) directory"
	@make -C ./libft clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\t[ $(RED)✗$(NONE) ] $(NAME) executable"
	@make -C ./libft fclean

re: fclean all

.PHONY: all check_libft project clean fclean re