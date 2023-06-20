# COLORS
_GREY=	$'\033[1;30m
_RED=	$'\033[1;31m
_GREEN=	$'\033[1;32m
_YELLOW=$'\033[1;33m
_BLUE=	$'\033[1;34m
_PURPLE=$'\033[1;35m
_CYAN=	$'\033[1;36m
_WHITE=	$'\033[1;37m

# VARIABLE
NAME	= pipex

CC		= gcc
CFLAGS	= -Wall		\
		  -Wextra	\
		  -Werror

SRCS_PATH	= srcs/
SRCS		= pipex.c	\
			  process.c	\
			  error.c

OBJS_PATH	= objs/
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
vpath %.c $(SRCS_PATH)

INC	= -I./includes/ -I./libft/includes/

LIBFT = libft/libft.a

# COMPILATION
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(_GREEN)[Pipex: Executable created]$(_White)"

$(LIBFT):
	@make -C libft/

$(OBJS_PATH)%.o : %.c
	@mkdir -p $(OBJS_PATH)
	@echo "$(_GREY)Compiling : $<$(_WHITE)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# RULES
all		: $(NAME)

clean	:
	@make -C libft/ clean
	@rm -rf $(OBJS) $(OBJS_PATH)
	@echo "$(_RED)[Pipex: All objects removed]$(_WHITE)"

fclean	: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(_RED)[Pipex: Executable removed]$(_WHITE)"

re		: fclean all

.PHONY : all clean fclean re
