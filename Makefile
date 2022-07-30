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
	@echo "Pipex Done !"

$(LIBFT):
	@make -C libft/

$(OBJS_PATH)%.o : %.c
	@mkdir -p $(OBJS_PATH)
	@echo "Compiling : $<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# RULES
all		: $(NAME)

clean	:
	@make -C libft/ clean
	@rm -rf $(OBJS) $(OBJS_PATH)

fclean	: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Pipex : Remove executable"

re		: fclean all

.PHONY : all clean fclean re
