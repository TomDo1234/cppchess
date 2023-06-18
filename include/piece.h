#include "enums.h"

#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
        Color color;
        PieceType piece_type;
        Piece(Color color,PieceType piece_type,unsigned int value,bool has_moved);
    private:
        unsigned value; 
        bool has_moved;
};

#endif