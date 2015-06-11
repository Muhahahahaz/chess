CC = gcc
OPT = -O3

RM = rm -f

NAME = chess
OBJS = $(NAME)
CFLAGS = $(OPT) -o $(NAME)



default: main

main:
  $(CC) $(CFLAGS) main.c

clean: 
  $(RM) $(OBJS)
