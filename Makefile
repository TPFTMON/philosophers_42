# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaryshe <abaryshe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/03 18:01:16 by abaryshe          #+#    #+#              #
#    Updated: 2025/08/03 18:37:21 by abaryshe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables for names and directiories ---
NAME = philo

INC_DIR = philo_build/includes
SRC_DIR = philo_build/sources
OBJ_DIR = objects

# --- Tools ---
FREM = rm -f
CC = cc
AR = ar rcs
CMPFLAGS = -Wall -Wextra -Werror
DBUG_FLAGS = ${CMPFLAGS} -g
INCLUDES = -I ${INC_DIR}

# --- Source Files ---
SRC_FILES = philo.c

SRCS = $(addprefix ${SRC_DIR}/, ${SRC_FILES})

# --- Object Files ---
OBJS =  $(addprefix ${OBJ_DIR}/, $(notdir ${SRCS:.c=.o}))

# To tell Makefile where to find .c files:
vpath %.c ${SRC_DIR}

# --- Main Rules ---
all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CMPFLAGS} ${INCLUDES} ${OBJS} -o ${NAME}

#OBJS:
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p ${OBJ_DIR}
	${CC} ${CMPFLAGS} ${INCLUDES} -c $< -o $@

clean:
	${FREM} ${OBJS}
	${FREM} -d ${OBJ_DIR}

fclean: clean
	${FREM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
