#include "enums.h"
#include "piece.h"

// Constructor implementation/definition
Piece::Piece(Color color, PieceType piece_type, unsigned int value, bool has_moved) {
    this->color = color;
    this->piece_type = piece_type;
    this->value = value;
    this->has_moved = has_moved;
}