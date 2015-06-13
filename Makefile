CC = g++
OPT = -O3
STD = -std=c++11

RM = rm -f

NAME = chess
OBJS = $(NAME)
CFLAGS = $(OPT) $(STD)



default: all

all: main.o position.o board.o
	$(CC) $(CFLAGS) -o $(NAME) main.o position.o board.o

main.o: main.cpp position.h
	$(CC) $(CFLAGS) -c main.cpp

position.o: position.cpp position.h board.h
	$(CC) $(CFLAGS) -c position.cpp

board.o: board.cpp board.h
	$(CC) $(CFLAGS) -c board.cpp

clean: 
	$(RM) $(OBJS) *.o
