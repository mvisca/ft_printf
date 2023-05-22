# **************************************************************************** #
# rm	
#      #
#    :::  ::::::::  #
#  Makefile    :+:  :+:  :+:  #
#    +:+ +:+  +:+  #
#  By: mvisca-g <mvisca-g@student.42barcel>  +#+  +:+  +#+  #
#    +#+#+#+#+#+  +#+  #
#  Created: 2023/05/03 19:18:12 by mvisca-g  #+#  #+#  #
#  Updated: 2023/05/09 17:35:18 by mvisca-g  ###  ########.fr  #
#      #
# **************************************************************************** #

# Makefile cookbook

# Format
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m

# Compilation variables
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Include
HEADER = libft.h

# Source Files
SRCS =	ft_atoi.c		ft_bzero.c		ft_calloc.c \
		ft_isalnum.c	ft_isalpha.c	ft_isascii.c \
		ft_isdigit.c	ft_isprint.c	ft_itoa.c \
		ft_memchr.c		ft_memcmp.c		ft_memcpy.c \
		ft_memmove.c	ft_memset.c		ft_putchar_fd.c \
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c \
		ft_split.c		ft_strchr.c		ft_strdup.c \
		ft_striteri.c	ft_strjoin.c 	ft_strlcat.c \
		ft_strlcpy.c	ft_strlen.c		ft_strmapi.c \
		ft_strncmp.c	ft_strnstr.c	ft_strrchr.c \
		ft_strtrim.c	ft_substr.c		ft_tolower.c \
		ft_toupper.c	ft_lstclear.c 	ft_lstadd_back.c \
		ft_lstdelone.c	ft_lstiter.c	ft_lstadd_front.c \
		ft_lstlast.c 	ft_lstmap.c		ft_lstnew.c \
		ft_lstsize.c

# Objects
OBJS = $(SRCS:.c=.o)

# Files and directories
NAME = libft.a

# Includes
INC = -I.

# Targets e instrucciones
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\r$(BLUE)Linking... $(NC)$^"
	@ar rcs $@ $^
	@echo "$(YELLOW)Library libfh.h ready! $(NC)"

%.o: %.c $(HEADER) 
	@echo "$(GREEN)Compiling... $(NC)$< -> $@"
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(RED)Delete *.o >> 🗑️ $(NC)"
	rm -f $(OBJS) 

fclean: clean
	@echo "$(RED)Delete program >> 🗑️$(NC)"
	rm -f $(NAME) $(HEADER).gch

re: fclean all
	@echo -n "Reseting"

#Protección PHONY
.PHONY: all clean fclean re
