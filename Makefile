# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:14:27 by mvisca            #+#    #+#              #
#    Updated: 2023/05/31 20:21:13 by mvisca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= libftprintf.a

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

LIBS		:= ft
LIBS_TARGET	:= libft/libft.a

INCS		:= include				\
	libft/include

SRCS_DIR	:= src
SRCS		:=						\
	ft_printf.c						\
	ft_putbasedec.c					\
	ft_putbasehex.c 				\
	ft_putchar.c					\
	ft_putstr.c
SRCS		:= $(SRCS:%=$(SRCS_DIR)/%)

LIBS_DIR	:= $(dir $(LIBS_TARGET))
BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

#---------------------------------------#
#	UTENSILS							#
#---------------------------------------#

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l,$(LIBS))
AR			:= ar -r -c -s
RM			:= rm -f -r
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#---------------------------------------#
#	FORMAT								#
#---------------------------------------#

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m

#---------------------------------------#
#	RECIPES								#
#---------------------------------------#

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	@cp $(LIBS_TARGET) $(NAME)
	@$(AR) $@ $(OBJS)
	@echo "$(YELLOW)Packing $(RED)$(NAME) $(YELLOW)ready!$(NC)"
-include $(DEPS)

$(LIBS_TARGET):
	@echo "$(BLUE)Call to create $(YELLOW)$(notdir $@)$(NC)"
	@$(MAKE) -C $(@D)
-include $(DEPS)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo "$(GREEN)Building $(NC)$(notdir $<) $(RED)-> $(NC)$(notdir $@)"

clean:
	@echo "$(RED)Deleting $(NC)$ printf *.o *.d $(RED) >> 🗑️$(NC)"
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	@$(RM) $(BUILD_DIR)

fclean: clean
	@echo "$(RED)Deleting $(NC)$(NAME) $(RED) >> 🗑️$(NC)"
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fcleancall; done
	@$(RM) $(NAME)

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

#---------------------------------------#
#	SPEC								#
#---------------------------------------#

.PHONY: clean fclean re all