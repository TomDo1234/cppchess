#include "ce.h"
#include "piece.h"
#include <cctype>

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
            const char c = fen_rank[index];

            if (c >= '1' && c <= '8') {
                int int_c = c - '0'; // - '0' just converts it to an int lol
                for (int i = 0; i < int_c; i++) { 
                    board[rank * 8 + offset + index + i].reset();
                }
                offset += int_c - 1;
            }

            std::optional<Piece> piece;

            Piece king;

            switch (std::toupper(c))
            {
                case 'P':
                    piece = std::isupper(c) ? WHITE_PAWN : BLACK_PAWN;
                    break;
                case 'R':
                    piece = std::isupper(c) ? WHITE_ROOK : BLACK_ROOK;
                    break;
                case 'N':
                    piece = std::isupper(c) ? WHITE_KNIGHT : BLACK_KNIGHT;
                    break;
                case 'B':
                    piece = std::isupper(c) ? WHITE_BISHOP : BLACK_BISHOP;
                    break;
                case 'Q':
                    piece = std::isupper(c) ? WHITE_QUEEN : BLACK_QUEEN;
                    break;
                case 'K': 
                    king = std::isupper(c) ? WHITE_KING : BLACK_KING;
                    if (!((rank * 8 + offset + index) % 8 == 4)) {
                        king.has_moved = true;
                    }
                    piece = king;
                    break;  
                default:
                    break;
            }

            board[rank * 8 + offset + index] = piece;
        }
        offset = 0;
    }

    return std::make_tuple(board,fen_whos_move);
}