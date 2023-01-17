# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 03:35:01 by nicolas           #+#    #+#              #
#    Updated: 2023/01/17 12:10:10 by nplieger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=		get_next_line.a

#------------------------------------------------#
#   PATHS                                        #
#------------------------------------------------#

SRC_DIR				:=		srcs
OBJ_DIR				:=		objs
INC_DIR				:=		includes

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRCS				:=		get_next_line \
							get_next_line_utils \

SRCS_BONUS			:=		get_next_line_bonus \
							get_next_line_utils_bonus \
						
SRCS_C				:=		$(addsuffix .c, $(SRCS))
SRCS_BONUS_C		:=		$(addsuffix .c, $(SRCS_BONUS))
CC_SRCS_C			:=		$(addsuffix $(SRC_DIR)/, $(SRCS_C))
CC_SRCS_BONUS_C		:=		$(addsuffix $(SRC_DIR)/, $(SRCS_BONUS_C))

OBJS				:=		$(SRCS_C:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS			:=		$(SRCS_BONUS_C:%.c=$(OBJ_DIR)/%.o)

#------------------------------------------------#
#   COMMANDS                                     #
#------------------------------------------------#

CC					:=		gcc
AR					:=		ar -rcs
DIRS				:=		-I $(INC_DIR)
CFLAGS				:=		-Wall -Wextra -Werror -g
RM					:=		rm -f

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all:				$(NAME)

$(NAME):			$(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS):			$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DIRS) -c $< -o $@

$(OBJS_BONUS):			$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DIRS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean:				clean
	$(RM) $(NAME)

re:					fclean all

bonus:				$(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus

