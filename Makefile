# Compilation variables
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Include
HEADER = ft_printf.h

# Paths
LIBFT_DIR = ft_libft/
SRCS_DIR = src/
OBJS_DIR = bin/

# Souce Files
SRCS =	$(wildcard $(SRCS_DIR)*.c)

# Objects
OBJS = $(patsubst $(SRCS:.c))

# Target file
NAME = libftprintf.a

# Includes
INC = -I. -I./ft_libft

#---------------------------------------#
#	FORMAT								#
#---------------------------------------#

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m

# Create directory if it doesn't exist
$(shell mkdir -p $(OBJS_DIR))

# Directives
all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT_DIR)libft.a
	cp $(LIBFT_DIR)libft.a $@
	ar rcs $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@ -g

$(LIBFT_DIR)libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS_DIR)*.o

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)libft.a 	

re: fclean all

.PHONY: view clean fclean re
