#include "ce.h"
#include "piece.h"

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

std::tuple<std::array<std::optional<Piece>,64>,int> parse_fen(std::string fen) {
    std::array<std::optional<Piece>,64> board;
    int offset = 0;

    //Split based on ' ' delimiter
    std::vector<std::string> fen_parts = split(fen," ");

    std::string fen_board_part = fen_parts[0];
    Color fen_whos_move = fen_parts[1] == "b" ?  Color::Black : Color::White;

    //Split based on '/' delimiter
    std::vector<std::string> fen_board_rows = split(fen_board_part,"/");

    for (size_t rank = 0; rank < fen_board_rows.size(); rank++) {
        const std::string fen_rank = fen_board_rows[rank];
        for (size_t index = 0; index < fen_rank.size(); index++) {
            for (size_t i = 0; i < fen_rank.size(); i++) {
                const char c = fen_rank[i];

                if (c >= '1' && c <= '8') {
                    int int_c = c - '0'; // - '0' just converts it to an int lol
                    for (int i = 0; i < int_c; i++) { 
                        board[rank * 8 + offset + index + i].reset();
                    }
                    offset += int_c - 1;
                }
                    // _ => {
                    //     let piece: Option<Piece> = if c.is_uppercase() { 
                    //         match c.to_ascii_lowercase() {
                    //             'p' => Some(WHITE_PAWN),
                    //             'r' => Some(WHITE_ROOK),
                    //             'n' => Some(WHITE_KNIGHT),
                    //             'b' => Some(WHITE_BISHOP),
                    //             'q' => Some(WHITE_QUEEN),
                    //             'k' => {
                    //                 let mut king = WHITE_KING.clone();
                    //                 if (rank * 8 + offset + index) % 8 == 4 {
                    //                     Some(king)
                    //                 }
                    //                 else {
                    //                     king.has_moved = true;
                    //                     Some(king)
                    //                 }
                    //             },
                    //             _ => panic!("Invalid character in FEN string {c}"),
                    //         }
                    //     }
                    //     else { 
                    //         match c.to_ascii_lowercase() {
                    //             'p' => Some(BLACK_PAWN),
                    //             'r' => Some(BLACK_ROOK),
                    //             'n' => Some(BLACK_KNIGHT),
                    //             'b' => Some(BLACK_BISHOP),
                    //             'q' => Some(BLACK_QUEEN),
                    //             'k' => {
                    //                 let mut king = BLACK_KING.clone();
                    //                 if rank * 8 + offset + index == 4 {
                    //                     Some(king)
                    //                 }
                    //                 else {
                    //                     king.has_moved = true;
                    //                     Some(king)
                    //                 }
                    //             },
                    //             _ => panic!("Invalid character in FEN string {c}"),
                    //         }
                    //     };
                        
                    //     board[rank * 8 + offset + index] = piece;
                    // } 
            }
        }
        offset = 0;
    }

    return std::make_tuple(board,fen_whos_move);
}