#include "zobrist.h"
#include <random>


ZobristHash::ZobristHash() {
    std::random_device rng;
    std::mt19937_64 engine(rng()); // Mersenne Twister engine with 64-bit output
    std::uniform_int_distribution<uint64_t> dist; // Range of 64-bit unsigned integers

    unsigned int zobrist_table[BOARD_SIZE][12];

    for (int i = 0; i < 12 ; i++) {
        for (int j = 0; j < BOARD_SIZE ; j++) {
            this->zobrist_table[i][j] = dist(engine);
        }
    }

    int other_data_table[9] = {0}; //9 0s in this array
    for (int i = 0; i < 9 ; i++) {
        this->other_data_table[i] = dist(engine);
    }
}

unsigned int ZobristHash::hash(std::array<std::optional<Piece>,64> board,unsigned int current_recursion) {
    int h = 0;

    for (int i = 0; i < 12 ; i++) {
        Piece checked_piece = PIECES[i];
        for (int j = 0; j < BOARD_SIZE ; j++) {
            std::optional<Piece> square = board[j];

            if (square.has_value()) {
                continue;
            }

            Piece piece = *square;
            if (piece.color == checked_piece.color && piece.piece_type == checked_piece.piece_type) {
                h ^= this->zobrist_table[i][j];
            }
        }
    }
    
    h ^= this->other_data_table[current_recursion - 1];
    
    return h;
}