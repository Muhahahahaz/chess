#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>
#include <iostream>
#include <map>



enum PieceColor{
  WHITE,
  BLACK,
  NIL_COLOR
};

enum PieceType {
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN,
  NIL_TYPE
};

typedef uint64_t Bitboard;
typedef std::map<PieceType, const char *> StringMap;



class Piece {
 public:
  Piece() : color(NIL_COLOR), type(NIL_TYPE), location(0) { }
  Piece(PieceColor c, PieceType t, Bitboard loc) { color = c; type = t; location = loc; }

  PieceColor getColor() { return color; }
  void setColor(PieceColor c) { color = c; }

  PieceType getType() { return type; }
  void setType(PieceType t) { type = t; }

  Bitboard getLocation() { return location; }
  void setLocation(Bitboard loc) { location = loc; }

  void print();

 private:
  PieceColor color;
  PieceType type;
  Bitboard location;

  static const StringMap whiteStrings;
  static const StringMap blackStrings;
};



class Board {
 public:
  Board();
  void print();

 private:
  static const int NUM_ROWS = 8;
  static const int NUM_COLS = 8;
  static const int NUM_PIECES = 32;

  Piece board[NUM_ROWS][NUM_COLS];
  Piece pieceList[NUM_PIECES];
};

#endif /* BITBOARD_H */
