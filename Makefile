CC = g++
OPT = -O3
STD = -std=c++11

RM = rm -f

NAME = chess
OBJS = $(NAME)
CFLAGS = $(OPT) $(STD)



default: all

all: main.o bitboard.o
	$(CC) $(CFLAGS) -o $(NAME) main.o bitboard.o

main.o: main.cpp bitboard.h
	$(CC) $(CFLAGS) -c main.cpp

bitboard.o: bitboard.cpp bitboard.h
	$(CC) $(CFLAGS) -c bitboard.cpp

clean: 
	$(RM) $(OBJS) *.o
