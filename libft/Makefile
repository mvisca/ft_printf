# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvisca-g <mvisca-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 14:07:34 by mvisca-g          #+#    #+#              #
#    Updated: 2023/06/01 16:01:46 by mvisca-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------#
#	LIBRARY								#
#---------------------------------------#

NAME 		:= libft.a

#---------------------------------------#
#	INGREDIENTS							#
#---------------------------------------#

SRCS_DIR	:= src
BUILD_DIR	:= .build
INC_DIR		:= include

# Import souces list from external file and parses the list to add the path
include sources.mk
SRCS		:= $(SRCS_LIB:%=$(SRCS_DIR)/%)
OBJS 		:= $(SRCS:$(SRCS_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

#---------------------------------------#
#	UTENSILS							#
#---------------------------------------#

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I$(INC_DIR)
AR			:= ar
ARFLAGS		:= -r -c -s
RM			:= rm -r -f 
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

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking...\n$(NC)$(notdir $^)"
	@$(AR) $(ARFLAGS) $@ $^
	@echo "$(YELLOW)Library $(RED)$(NAME) $(YELLOW)ready!$(NC)"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "$(GREEN)Building $(NC)$(notdir $<)$(RED) -> $(NC)$(notdir $@)"
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
-include $(DEPS)

clean:
	@echo "$(RED)Deleting $(NC)libft *.o *.d$(RED)>> 🗑️$(NC)"
	@$(RM) $(BUILD_DIR)

fclean: clean
	@echo "$(RED)Deleting $(NC)$(NAME) $(RED)>> 🗑️$(NC)"
	@$(RM) $(NAME)

fcleancall:
	@echo "\r$(RED)Deleting $(NC)$(NAME) $(RED)>> 🗑️$(NC)"
	@$(RM) $(NAME)
	
re: fclean all

#---------------------------------------#
#	SPECIAL RULES						#
#---------------------------------------#

.PHONY: clean fclean fcleancall re