
# Compilation variables
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Include
HEADER = libftprintf.h

# Paths
LIBFT = ft_libft/
AUX = ft_auxfncs/

# Souce Files
SRCS_AUX = ft_addchar.c ft_del.c
SRCS = ft_printf.c $(addprefix $(AUX), $(SRCS_AUX))

# Objects
OBJS = $(SRCS:.c=.o)

# Target file
NAME = libftprintf.a

# Includes
INC = -I. -I./ft_libft

# Directives
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(HADER) $(LIBFT)libft.a
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT)libft.a:
	cd $(LIBFT)
	make
	cd ..
