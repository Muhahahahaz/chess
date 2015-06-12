#include "board.h"

using std::cout;
using std::endl;
using std::map;



Piece::StringMap Piece::whiteStrings = {
  {KING, "K"},
  {QUEEN, "Q"},
  {ROOK, "R"},
  {BISHOP, "B"},
  {KNIGHT, "N"},
  {PAWN, "P"},
  {NIL_TYPE, " "}
};

Piece::StringMap Piece::blackStrings = {
  {KING, "k"},
  {QUEEN, "q"},
  {ROOK, "r"},
  {BISHOP, "b"},
  {KNIGHT, "n"},
  {PAWN, "p"},
  {NIL_TYPE, " "}
};

void Piece::print() {
  switch(color) {
    case WHITE:
      cout << whiteStrings[type];
      break;
    case BLACK:
      cout << blackStrings[type];
      break;
    case NIL_COLOR:
      cout << ".";
      break;
    default:
      cout << "?";
  }
}



Board::Board() {
  bits[WHITE][ROOK] = UINT64_C(0x81);
  bits[WHITE][KNIGHT] = UINT64_C(0x42);
  bits[WHITE][BISHOP] = UINT64_C(0x24);
  bits[WHITE][QUEEN] = UINT64_C(0x08);
  bits[WHITE][KING] = UINT64_C(0x10);
  bits[WHITE][PAWN] = UINT64_C(0xFF00);

  bits[BLACK][ROOK] = bits[WHITE][ROOK] << 56;
  bits[BLACK][KNIGHT] = bits[WHITE][KNIGHT] << 56;
  bits[BLACK][BISHOP] = bits[WHITE][BISHOP] << 56;
  bits[BLACK][QUEEN] = bits[WHITE][QUEEN] << 56;
  bits[BLACK][KING] = bits[WHITE][KING] << 56;
  bits[BLACK][PAWN] = bits[WHITE][PAWN] << 40;

  for(int i = 0; i < NUM_ROWS; i++) {
    for(int j = 0; j < NUM_COLS; j++) {
      mailbox[i][j] = pieceAt(i, j);
    }
  }
}

void Board::print() {
  for(int i = NUM_ROWS-1; i >= 0; i--) {
    for(int j = 0; j < NUM_COLS; j++) {
      mailbox[i][j].print();
      cout << " ";
    }
    cout << endl;
  }
}

int Board::flatIndex(int row, int col) {
  return row*NUM_COLS + col;
}

Board::Bitboard Board::maskBoard(int row, int col) {
  return UINT64_C(0x1) << flatIndex(row, col);
}

Piece Board::pieceAt(int row, int col) {
  PieceColor c;
  PieceType t;

  for(int color = 0; color < NUM_PIECE_COLORS; color++) {
    for(int type = 0; type < NUM_PIECE_TYPES; type++) {
      if(bits[color][type] & maskBoard(row, col)) {
        c = (PieceColor) color;
        t = (PieceType) type;
        return Piece(c, t);
      }
    }
  }

  return Piece(NIL_COLOR, NIL_TYPE);
}
