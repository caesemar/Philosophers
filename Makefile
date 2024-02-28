# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 03:06:52 by caesemar          #+#    #+#              #
#    Updated: 2024/02/28 19:50:00 by jocasado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -pthread -Wall -Wextra -Werror #-fsanitize=thread
NAME = philo
RM = rm -rf
HDRS = -I ./header/
################################################################################
##								MANDATORY									  ##
################################################################################
CFILES = \
		source/Philosophers.c\
		source/utils.c\
		source/utils2.c\
		source/utils3.c\
		source/ft_itoa.c\
		source/parse.c\
		source/actions.c\
		source/init.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
OBJS = $(CFILES:.c=.o)
################################################################################
.PHONY: all re fclean clean tests
################################################################################

all:        $(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW)compiling ..."
			@$(CC) $(OBJS) -o $(NAME)
			@echo "$(GREEN)compiled:$(NAME) build ✅"
.c.o:
			@${CC} ${CFLAGS} $^ -o $@ ${HDRS}

re:     	fclean all

fclean:     clean
			@$(RM) $(NAME)
			@echo "$(YELLOW)deleting...\n$(RED)$(NAME) deleted"

clean:
			@$(RM) $(OBJS)
			@echo "$(YELLOW)deleting...\n$(RED)$(OBJS) deleted"

test1: all
	./philo 1 800 200 200 # mueren

test2: all
	./philo 5 800 200 200 # viven

test3: all
	./philo 5 800 200 200 7 #viven y cada uno come 7 veces

test4: all
	./philo 4 410 200 200 #viven

test5: all
	./philo 4 310 200 100 #mueren
##COLOURS##
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
DEFAULT = \033[0m
