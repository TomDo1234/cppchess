#include <iostream>
#include "piece.h"
#include <optional>

int main() {
  Piece WHITE_PAWN = Piece(Color::White,PieceType::Pawn,1U,false);
  Piece WHITE_KNIGHT = Piece(Color::White,PieceType::Knight,3U,false);
  Piece WHITE_BISHOP = Piece(Color::White,PieceType::Bishop,3U,false);
  Piece WHITE_ROOK = Piece(Color::White,PieceType::Rook,5U,false);
  Piece WHITE_QUEEN = Piece(Color::White,PieceType::Queen,9U,false);
  Piece WHITE_KING = Piece(Color::White,PieceType::King,205U,false);
  Piece BLACK_PAWN = Piece(Color::White,PieceType::Pawn,1U,false);
  Piece BLACK_KNIGHT = Piece(Color::Black,PieceType::Knight,3U,false);
  Piece BLACK_BISHOP = Piece(Color::Black,PieceType::Bishop,3U,false);
  Piece BLACK_ROOK = Piece(Color::Black,PieceType::Rook,5U,false);
  Piece BLACK_QUEEN = Piece(Color::Black,PieceType::Queen,9U,false);
  Piece BLACK_KING = Piece(Color::Black,PieceType::King,205U,false);

  std::cout << BLACK_QUEEN.color << std::endl;
  
  return 0;
}
