# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 16:18:12 by mvisca-g          #+#    #+#              #
#    Updated: 2023/05/23 19:56:33 by mvisca-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Include
HEADER = ft_printf.h

# Paths
LIBFT_DIR = ft_libft/
AUX_DIR = ft_auxfncs/
OBJS_DIR = ft_objects/

# Create directory if it doesn't exist
$(shell mkdir -p $(OBJS_DIR) $(OBJS_DIR)$(AUX_DIR))

# Souce Files
SRCS_AUX = 		ft_addchar.c		ft_addcharva.c \
				ft_addstring.c 		ft_addhex.c \
				ft_del.c		ft_printf.c

# Objects
OBJS_AUX = $(addprefix $(OBJS_DIR), $(SRCS_AUX:.c=.o))
# OBJS_MAIN = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS = $(OBJS_AUX) #$(OBJS_MAIN)

# Target file
NAME = libftprintf.a

# Includes
INC = -I. -I./ft_libft

# Directives
all: $(NAME)

$(NAME): $(OBJS) $(HEADER) | $(LIBFT_DIR)libft.a
	cp $(LIBFT_DIR)libft.a $@
	ar rcs $@ $(OBJS)

$(OBJS_DIR)%.o: $(AUX_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT_DIR)libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(HEADER).gch

fclean: clean
	rm -f $(NAME) $(LIBFT_DIR)libft.a 	

view:
	@echo $(OBJS)

re: fclean all

.PHONY: view clean fclean re
