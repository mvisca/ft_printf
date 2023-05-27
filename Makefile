# Compilation variables
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Include
HEADER = ft_printf.h

# Paths
LIBFT_DIR = ft_libft/
SRCS_DIR = src/
OBJS_DIR = bin/

# Create directory if it doesn't exist
$(shell mkdir -p $(OBJS_DIR))

# Souce Files
# SRCS =	ft_addchar.c ft_addcharva.c ft_addstring.c ft_addptr.c ft_addhexnum.c \
		ft_addint.c ft_addunsint.c ft_del.c ft_printf.c ft_addnode.c
SRCS = ft_printf.c ft_putformat.c

# Objects
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# Target file
NAME = libftprintf.a

# Includes
INC = -I. -I./ft_libft

# Directives
all: $(NAME)

$(NAME): $(OBJS) $(HEADER) | $(LIBFT_DIR)libft.a
	cp $(LIBFT_DIR)libft.a $@
	ar rcs $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_DIR)libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)libft.a 	

re: fclean all

.PHONY: view clean fclean re
