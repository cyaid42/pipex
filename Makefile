SRCS =

OBJS  = ${SRCS: .c= .o}

CC = cc
CCFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

all: ${NAM}
