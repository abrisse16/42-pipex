# VARIABLES
NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall \
		  -Wextra \
		  -Werror

SRCS_PATH	= srcs/
SRCS		= ASCII_functions/ft_isalpha.c				\
			  ASCII_functions/ft_isdigit.c				\
			  ASCII_functions/ft_isalnum.c				\
			  ASCII_functions/ft_isascii.c				\
			  ASCII_functions/ft_isprint.c				\
			  ASCII_functions/ft_toupper.c				\
			  ASCII_functions/ft_tolower.c				\
			  string_functions/ft_strlen.c				\
			  string_functions/ft_strlcpy.c				\
			  string_functions/ft_strlcat.c				\
			  string_functions/ft_strchr.c				\
			  string_functions/ft_strrchr.c				\
			  string_functions/ft_strncmp.c				\
			  string_functions/ft_strnstr.c				\
			  string_functions/ft_strdup.c				\
			  string_functions/ft_appendchr.c			\
			  string_functions/ft_strndup.c				\
			  string_functions/ft_uitoa_base.c			\
			  memory_functions/ft_memset.c				\
			  memory_functions/ft_bzero.c				\
			  memory_functions/ft_memcpy.c				\
			  memory_functions/ft_memmove.c				\
			  memory_functions/ft_memchr.c				\
			  memory_functions/ft_memcmp.c				\
			  string_functions/ft_atoi.c				\
			  allocation_functions/ft_calloc.c			\
			  string_functions/ft_substr.c				\
			  string_functions/ft_strjoin.c				\
			  string_functions/ft_strjoin_free.c		\
			  string_functions/ft_strtrim.c				\
			  string_functions/ft_strmapi.c				\
			  string_functions/ft_striteri.c			\
			  string_functions/ft_split.c				\
			  string_functions/ft_itoa.c				\
			  string_functions/ft_itoa_base.c			\
			  output_functions/ft_putchar_fd.c			\
			  output_functions/ft_putstr_fd.c			\
			  output_functions/ft_putendl_fd.c			\
			  output_functions/ft_putnbr_fd.c			\
			  linked_list_functions/ft_lstnew.c			\
			  linked_list_functions/ft_lstadd_front.c	\
			  linked_list_functions/ft_lstsize.c		\
			  linked_list_functions/ft_lstlast.c		\
			  linked_list_functions/ft_lstadd_back.c	\
			  linked_list_functions/ft_lstdelone.c		\
			  linked_list_functions/ft_lstclear.c		\
			  linked_list_functions/ft_lstiter.c		\
			  linked_list_functions/ft_lstmap.c			\
			  get_next_line/get_next_line.c				\
			  get_next_line/get_next_line_utils.c		\
			  ft_printf/ft_printf.c						\
			  ft_printf/get_conversion.c				\
			  ft_printf/get_info.c						\
			  ft_printf/printf_base.c					\
			  ft_printf/printf_char.c					\
			  ft_printf/printf_int.c					\
			  ft_printf/printf_pct.c					\
			  ft_printf/printf_ptr.c					\
			  ft_printf/printf_str.c					\
			  ft_printf/utils.c

OBJS_PATH	= objs/
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))
vpath %.c $(SRCS_PATH)

INCLUDE	= -I./includes/

# COMPILATION
$(NAME)	: $(OBJS)
	@ar cr $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Libft Done !"

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)ASCII_functions
	@mkdir -p $(OBJS_PATH)allocation_functions
	@mkdir -p $(OBJS_PATH)linked_list_functions
	@mkdir -p $(OBJS_PATH)memory_functions
	@mkdir -p $(OBJS_PATH)output_functions
	@mkdir -p $(OBJS_PATH)string_functions
	@mkdir -p $(OBJS_PATH)get_next_line
	@mkdir -p $(OBJS_PATH)ft_printf
	@echo "Compiling : $<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# RULES
all		: $(NAME)

clean	:
	@rm -rf $(OBJS_PATH)
	@echo "Remove .o"

fclean	: clean
	@rm -f $(NAME)
	@echo "Remove $(NAME)"

re		: fclean all

.PHONY	: all clean fclean re
