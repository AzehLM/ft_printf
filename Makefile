NAME	:= libftprintf.a

SRCS	:= \
	ft_printf_convert.c \
	ft_printf_utils.c \
	ft_printf.c \

SRCSB	:= \
	ft_printf_bonus.c \
	ft_printf_convert_bonus.c \
	ft_printf_utils_bonus.c \
	ft_printf_utils2_bonus.c \

BUILD_DIR	:= .build
OBJS		:= $(SRCS:%.c=$(BUILD_DIR)/%.o)
OBJSB		:= $(SRCSB:%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)
DEPSB		:= $(OBJSB:.o=.d)

# ********** FLAGS AND COMPILATION FLAGS ************************************* #

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

# ********** RULES *********************************************************** #

-include $(DEPS)
-include $(DEPSB)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@$(RM) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(GREEN_BOLD)✓ $(NAME) is ready$(RESETC)"

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@echo "$(CYAN)[Compiling]$(RESETC) $<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILD_DIR):
	@$(DIR_DUP)

bonus: .bonus

.bonus: $(OBJSB)
	@$(RM) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJSB)
	@echo "$(GREEN_BOLD)✓ $(NAME) made with bonus files$(RESETC)"
	@touch .bonus

.PHONY: clean
clean:
	@$(RM) $(OBJS) $(DEPS) $(OBJSB) $(DEPSB) .bonus
	@echo "$(RED_BOLD)[Cleaning]$(RESETC)"

.PHONY: fclean
fclean: clean
	@$(RM) $(RMDIR) $(NAME) $(BUILD_DIR)
	@echo "$(RED_BOLD)✓ project is fully cleaned!$(RESETC)"

.PHONY: re
re: fclean all

# ********** COLORS AND BACKGROUND COLORS ************************************ #

RESETC				:=	\033[0m

GREEN_BOLD			:=	\033[1;32m
RED_BOLD			:=	\033[1;31m
CYAN				:=	\033[0;36m
