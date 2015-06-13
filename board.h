#ifndef BOARD_H
#define BOARD_H

#include <cstdint>
#include <map>



enum PieceColor {
  WHITE = 0,
  BLACK,
  NIL_COLOR
};

enum PieceType {
  KING = 0,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN,
  NIL_TYPE
};

const int NUM_PIECE_COLORS = 2;
const int NUM_PIECE_TYPES = 6;



class Piece {
 public:
  Piece() : color(NIL_COLOR), type(NIL_TYPE) { }
  Piece(PieceColor c, PieceType t) { color = c; type = t; }

  PieceColor getColor() { return color; }
  void setColor(PieceColor c) { color = c; }

  PieceType getType() { return type; }
  void setType(PieceType t) { type = t; }

  bool isEmpty();
  void print();

 private:
  PieceColor color;
  PieceType type;

  typedef std::map<PieceType, const char *> PieceMap;
  static const PieceMap whiteStrings;
  static const PieceMap blackStrings;
};



class Board {
 public:
  Board();
  void print();
  void printFEN();

 private:
  typedef uint64_t Bitboard;

  int flatIndex(int row, int col);
  Bitboard maskBoard(int row, int col);
  Piece pieceAt(int row, int col);

  static const int NUM_ROWS = 8;
  static const int NUM_COLS = 8;

  Piece mailbox[NUM_ROWS][NUM_COLS];
  Bitboard bits[NUM_PIECE_COLORS][NUM_PIECE_TYPES];
};

#endif /* BOARD_H */
