#include "enums.h"
#include <vector>
#include <optional>
#include <tuple>

#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
        Color color;
        PieceType piece_type;
        Piece(Color color,PieceType piece_type,unsigned int value,bool has_moved);
        std::vector<int> get_moves(std::optional<Piece> board[64]);
        std::tuple<size_t,unsigned int,std::optional<Piece>[64]> do_move(std::optional<Piece> board[64],int movement);
    private:
        unsigned value; 
        bool has_moved;
};

#endif