#include "bitboard.h"

using std::cout;
using std::endl;
using std::map;

/*const Bitboard WROOKS = UINT64_C(0x81);
const Bitboard WKNIGHTS = UINT64_C(0x42);
const Bitboard WBISHOPS = UINT64_C(0x24);
const Bitboard WQUEEN = UINT64_C(0x08);
const Bitboard WKING = UINT64_C(0x10);
const Bitboard WPAWNS = UINT64_C(0xFF00);

const Bitboard BROOKS = UINT64_C(WROOKS << 56);
const Bitboard BKNIGHTS = UINT64_C(WKNIGHTS << 56);
const Bitboard BBISHOPS = UINT64_C(WBISHOPS << 56);
const Bitboard BQUEEN = UINT64_C(WQUEEN << 56);
const Bitboard BKING = UINT64_C(WKING << 56);
const Bitboard BPAWNS = UINT64_C(WPAWNS << 40);*/



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
      cout << " ";
      break;
    default:
      cout << "?";
  }
}



Board::Board() {
    //board[0][0] = new Piece(WHITE, ROOK, 0);
}

void Board::print() {
  for(int i = 0; i < NUM_ROWS; i++) {
    for(int j = 0; j < NUM_COLS; j++) {
      board[i][j].print();
      cout << " ";
    }
    cout << endl;
  }
}
