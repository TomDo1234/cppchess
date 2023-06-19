#include <tuple>
#include <array>
#include <optional>
#include <string>
#include <sstream>
#include <vector>
#include "enums.h"
#include "piece.h"

std::tuple<std::array<std::optional<Piece>,64>,int> parse_fen(std::string fen) {
    std::array<std::optional<Piece>,64> board;
    int offset = 0;


    std::vector<std::string> fen_parts;
    std::istringstream iss(fen);
    std::string word;

    while (std::getline(iss, word, ' ')) {
        fen_parts.push_back(word);
    }

    std::string fen_board_part = fen_parts[0];
    Color fen_whos_move = fen_parts[1] == "b" ?  Color::Black : Color::White;

    // for (rank, fen_rank) in fen_board_part.split('/').enumerate() {
    //     for (index,c) in fen_rank.chars().enumerate() {
    //         match c {
    //             '1'..='8' => {
    //                 for i in 0..c.to_digit(10).unwrap() {
    //                     board[rank * 8 + offset + index + i as usize] = None;
    //                 }
    //                 offset += c.to_digit(10).unwrap() as usize - 1;
    //             },
    //             _ => {
    //                 let piece: Option<Piece> = if c.is_uppercase() { 
    //                     match c.to_ascii_lowercase() {
    //                         'p' => Some(WHITE_PAWN),
    //                         'r' => Some(WHITE_ROOK),
    //                         'n' => Some(WHITE_KNIGHT),
    //                         'b' => Some(WHITE_BISHOP),
    //                         'q' => Some(WHITE_QUEEN),
    //                         'k' => {
    //                             let mut king = WHITE_KING.clone();
    //                             if (rank * 8 + offset + index) % 8 == 4 {
    //                                 Some(king)
    //                             }
    //                             else {
    //                                 king.has_moved = true;
    //                                 Some(king)
    //                             }
    //                         },
    //                         _ => panic!("Invalid character in FEN string {c}"),
    //                     }
    //                 }
    //                 else { 
    //                     match c.to_ascii_lowercase() {
    //                         'p' => Some(BLACK_PAWN),
    //                         'r' => Some(BLACK_ROOK),
    //                         'n' => Some(BLACK_KNIGHT),
    //                         'b' => Some(BLACK_BISHOP),
    //                         'q' => Some(BLACK_QUEEN),
    //                         'k' => {
    //                             let mut king = BLACK_KING.clone();
    //                             if rank * 8 + offset + index == 4 {
    //                                 Some(king)
    //                             }
    //                             else {
    //                                 king.has_moved = true;
    //                                 Some(king)
    //                             }
    //                         },
    //                         _ => panic!("Invalid character in FEN string {c}"),
    //                     }
    //                 };
                    
    //                 board[rank * 8 + offset + index] = piece;
    //             }
    //         }
    //     }
    //     offset = 0
    // }

    return std::make_tuple(board,fen_whos_move);
}