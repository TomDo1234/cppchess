#include "enums.h"
#include <vector>
#include <optional>
#include <tuple>
#include <array>

#ifndef PIECE_H
#define PIECE_H

class Piece {
    public:
        Color color;
        PieceType piece_type;
        Piece(Color color,PieceType piece_type,unsigned int value,bool has_moved);
        std::vector<int> get_moves(std::optional<Piece> board[64]);
        std::tuple<int,unsigned int,std::array<std::optional<Piece>,64>> do_move(std::array<std::optional<Piece>,64> board,int movement);
    private:
        unsigned value; 
        bool has_moved;
};

const Piece WHITE_PAWN = Piece(Color::White,PieceType::Pawn,1U,false);
const Piece WHITE_KNIGHT = Piece(Color::White,PieceType::Knight,3U,false);
const Piece WHITE_BISHOP = Piece(Color::White,PieceType::Bishop,3U,false);
const Piece WHITE_ROOK = Piece(Color::White,PieceType::Rook,5U,false);
const Piece WHITE_QUEEN = Piece(Color::White,PieceType::Queen,9U,false);
const Piece WHITE_KING = Piece(Color::White,PieceType::King,205U,false);
const Piece BLACK_PAWN = Piece(Color::White,PieceType::Pawn,1U,false);
const Piece BLACK_KNIGHT = Piece(Color::Black,PieceType::Knight,3U,false);
const Piece BLACK_BISHOP = Piece(Color::Black,PieceType::Bishop,3U,false);
const Piece BLACK_ROOK = Piece(Color::Black,PieceType::Rook,5U,false);
const Piece BLACK_QUEEN = Piece(Color::Black,PieceType::Queen,9U,false);
const Piece BLACK_KING = Piece(Color::Black,PieceType::King,205U,false);

#endif