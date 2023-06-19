#include "zobrist.h"
#include <random>


ZobristHash::ZobristHash() {
    std::random_device rng;
    std::mt19937_64 engine(rng()); // Mersenne Twister engine with 64-bit output
    std::uniform_int_distribution<uint64_t> dist; // Range of 64-bit unsigned integers
    
    unsigned int zobrist_table[BOARD_SIZE][12];

    // for i in 0..PIECES.len() {
    //     for j in 0..BOARD_SIZE {
    //         zobrist_table[i][j] = rng.gen::<u64>();
    //     }
    // }

    // let mut other_data_table = [0; 9];
    // for i in 0..9 {
    //     other_data_table[i] = rng.gen::<u64>();
    // }

    // Self {
    //     zobrist_table,
    //     other_data_table
    // }
}