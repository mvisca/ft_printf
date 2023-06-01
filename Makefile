# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:14:27 by mvisca            #+#    #+#              #
#    Updated: 2023/06/01 15:48:06 by mvisca-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= libftprintf.a

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

# Dirs
LIBS		:= ft
LIBS_TARGET	:= libft/libft.a
LIBS_DIR	:= $(dir $(LIBS_TARGET))
BUILD_DIR	:= .build/
SRCS_DIR	:= src/
INCS		:= include/				\
	libft/include/

# Source
SRCS		:=						\
	ft_printf.c						\
	ft_putbasedec.c					\
	ft_putbasehex.c 				\
	ft_putchar.c					\
	ft_putstr.c
SRCS		:= $(SRCS:%=$(SRCS_DIR)%)

# Objects
OBJS		:= $(SRCS:$(SRCS_DIR)%.c=$(BUILD_DIR)%.o)
OBJS_LIB	:= $(dir $(LIBS_TARGET)$(SRCS_DIR))

# Dependencies
DEPS		:= $(OBJS:.o=.d)

#---------------------------------------#
#	UTENSILS							#
#---------------------------------------#

# Compiler
CC 			:= cc

# Compilation flags
CFLAGS 		:= -Wall -Wextra -Werror

# PreProcessor flags
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP

# Libraries path flag 
LDFLAGS		:= $(addprefix -L,$(dir $(LIBS_TARGET)))

# Libraries name flag
LDLIBS		:= $(addprefix -l,$(LIBS))

# Archiver 
AR			:= ar -r -c -s

# Remover
RM			:= rm -f -r

# Directories builder
DIR_DUP		= mkdir -p $(@D)

# Defaulte behaviours update
MAKEFLAGS	+= --no-print-directory --silent

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

all: $(NAME) callforlib

$(NAME): $(OBJS) $(LIBS_TARGET)
	@cp $(LIBS_TARGET) $(NAME)
	@$(AR) $@ $(OBJS)
	@echo "$(YELLOW)Packing $(RED)$(NAME) $(YELLOW)ready!$(NC)"
-include $(DEPS)

$(LIBS_TARGET):
	@echo "$(BLUE)Call to create $(YELLOW)$(notdir $@)$(NC)"
	@$(MAKE) -C $(@D)
-include $(DEPS)

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c
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

callforlib:
	@$(MAKE) -C $(LIBS_DIR)
	@$(MAKE) -C . $(NAME)

#---------------------------------------#
#	SPEC								#
#---------------------------------------#

.PHONY: clean fclean re all
.SILENT:
