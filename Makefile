CC = g++
OPT = -O3
STD = -std=c++11

RM = rm -f

NAME = chess
OBJS = $(NAME)
CFLAGS = $(OPT) $(STD)



default: all

all: main.o board.o
	$(CC) $(CFLAGS) -o $(NAME) main.o board.o

main.o: main.cpp board.h
	$(CC) $(CFLAGS) -c main.cpp

board.o: board.cpp board.h
	$(CC) $(CFLAGS) -c board.cpp

clean: 
	$(RM) $(OBJS) *.o
