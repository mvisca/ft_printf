# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca <mvisca@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:14:27 by mvisca            #+#    #+#              #
#    Updated: 2023/05/31 18:15:39 by mvisca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= libftprintf.a

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

LIBS		:= ft
LIBS_TARGET	:= ft_libft/libft.a

INCS		:= include				\
	ft_libft/include

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
	@$(AR) $@ $<
	@echo "$(YELLOW)Building $(RED)$(NAME) $(YELLOW)ready!$(NC)"

$(LIBS_TARGET):
	@echo "$(BLUE)Call to create $(YELLOW)$@$(NC)"
	@$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo "$(GREEN)Library... $(NC)$($< $(RED) -> $(NC)$@)"
-include $(DEPS)

clean:
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	@$(RM) $(OBJS) $(DEPS) $(BUILD_DIR)
	@echo "$(BLUE)Deleting... $(NC)$(notdir $(OBJS)) $(YELLOW)$(BUILD_DIR) $(RED) >> 🗑️$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	@echo "$(GREEN)Deleting... $(NC)$(NAME) $(RED) >> 🗑️$(NC)"

re: 
	$(MAKE) fclean 
	$(MAKE) all

#---------------------------------------#
#	SPEC								#
#---------------------------------------#

.PHONY: view clean fclean re
