#include "zobrist.h"
#include <random>


ZobristHash::ZobristHash() {
    std::random_device rng;
    std::mt19937_64 engine(rng()); // Mersenne Twister engine with 64-bit output
    std::uniform_int_distribution<uint64_t> dist; // Range of 64-bit unsigned integers

    unsigned int zobrist_table[BOARD_SIZE][12];

    for (int i = 0; i < 12 ; i++) {
        for (int j = 0; j < BOARD_SIZE ; j++) {
            zobrist_table[i][j] = dist(engine);
        }
    }

    int other_data_table[9] = {0}; //9 0s in this array
    for (int i = 0; i < 9 ; i++) {
        other_data_table[i] = dist(engine);
    }

    this->zobrist_table = zobrist_table;
    this->other_data_table = other_data_table;
}