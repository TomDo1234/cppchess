#include <iostream>
#include "piece.h"
#include "ce.h"
#include <optional>

int main() {
  std::string fen = "rnb1kbnr/pppppppp/5q2/8/4N3/8/PPPPPPPP/R1BQKBNR";

  // std::cout << "Type a FEN:" << std::endl;
  // std::cin >> fen;

  auto [board,turn] = parse_fen(fen);

  std::cout << turn << std::endl << std::endl;

  for (size_t i = 0; i < board.size(); i++) {    
    std::optional<Piece> square = board[i];
    std::cout << (square.has_value() ? (*square).char_representation() : '_');
    if ((i + 1) % 8 == 0) {
      std::cout << std::endl;
    }
  }

  std::cout << std::endl;
  
  return 0;
}
