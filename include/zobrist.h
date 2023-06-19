#include "piece.h"

const unsigned int BOARD_SIZE = 64;
const Piece PIECES[12] = {BLACK_KING,BLACK_QUEEN,BLACK_BISHOP,BLACK_ROOK,BLACK_KNIGHT,BLACK_PAWN,WHITE_KING,WHITE_BISHOP,WHITE_KNIGHT,WHITE_PAWN,WHITE_QUEEN,WHITE_ROOK};


class ZobristHash {
    public:
        unsigned int zobrist_table[BOARD_SIZE][12];
        unsigned int other_data_table[9];
        ZobristHash();
        unsigned int hash(std::array<std::optional<Piece>,64> board,unsigned int current_recursion);
};