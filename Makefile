# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gueberso <gueberso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 12:24:35 by gueberso          #+#    #+#              #
#    Updated: 2024/11/16 16:44:42 by gueberso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a

SRCS	:= \
	ft_printf_convert.c \
	ft_printf_utils.c \
	ft_printf.c \

BUILD_DIR	:= .build
OBJS		:= $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g3
CPPFLAGS	:= -MMD -MP -I .
AR			:= ar
ARFLAGS		:= -r -c -s

RM			:= rm -f
RMDIR		+= -r
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(BUILD_DIR)

.DEFAULT_GOAL	:= all

-include $(DEPS)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)


$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILD_DIR):
	@$(DIR_DUP)

clean:
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@$(RM) $(RMDIR) $(NAME) $(BUILD_DIR)

re: fclean all

.PHONY: all fclean re bonus
