#include "piece.h"

// Constructor implementation/definition
Piece::Piece(Color color, PieceType piece_type, unsigned int value, bool has_moved) {
    this->color = color;
    this->piece_type = piece_type;
    this->value = value;
    this->has_moved = has_moved;
}

//Default constructor
Piece::Piece() {
}

std::vector<int> Piece::get_moves(std::optional<Piece> board[64]) {
    int position = -1; //remains -1 if piece is not found;

    // Find the index of the object by comparing memory addresses
    for (size_t i = 0; i < 64; ++i) {
        if (board[i].has_value() && &*board[i] == this) {
            position = i;
            break;
        }
    }


    PieceType type = this->piece_type;
    std::vector<int> moves = {};

    if (type == PieceType::Pawn) {
        int direction = this->color == Color::White ? -1 : 1;
        int new_position_forward_one = position + 8 * direction;
        int new_position_forward_two = position + 16 * direction;

        if (new_position_forward_one >= 0 && new_position_forward_one <= 63 && &board[new_position_forward_one] == nullptr) {
            moves.push_back(8 * direction);
            if (!this->has_moved && new_position_forward_two >= 0 && new_position_forward_two <= 63 && &board[new_position_forward_two] == nullptr) {
                moves.push_back(16 * direction);
            }
        }
        int new_position = position + 9 * direction;
        if (std::abs((new_position / 8) - (position / 8)) == 1) {
            if ((*board[new_position]).color != this->color) {
                moves.push_back(9 * direction);
            }
        }
        new_position = position + 7 * direction;
        if (std::abs((new_position / 8) - (position / 8)) == 1) {
            if ((*board[new_position]).color != this->color) {
                moves.push_back(7 * direction);
            }
        }
        return moves;
    }
    else if (type == PieceType::Knight) {
        moves = {-17, -15, -10, -6, 6, 10, 15, 17};
        std::vector<int> available_moves = {};
        for (int movement: moves) {
            int new_position = position + movement;
            if (new_position < 0 || new_position > 63) {
                continue;
            }
            else if ((movement == 10 || movement == 6 || movement == -10 || movement == -6) && std::abs(new_position % 8 - position % 8) != 2) {
                continue;
            }
            else if ((movement == 17 || movement == 15 || movement == -15 || movement == -17) && std::abs(new_position % 8 - position % 8) != 1) {
                continue;
            }
            if ((*board[new_position]).color == this->color) {
                continue;
            }
            available_moves.push_back(movement);
        }
        return available_moves;
    }
    else if (type == PieceType::Bishop) {
        std::vector<int> available_moves = {};
        int directions[4] = {-9,9,7,-7};
        for (int direction: directions) {
            for (int i = 0; i < 8; i++) {
                int movement = direction * i;
                int new_position = position + movement;
                if (new_position > 63 || new_position < 0) {
                    break;
                }
                if (std::abs(((position + movement) / 8) - (position / 8)) != i) {
                    break;
                }
                if (!board[new_position].has_value()) {
                    if ((*board[new_position]).color != this->color) {
                        available_moves.push_back(movement);
                    }
                    break;
                }
                available_moves.push_back(movement);
            }
        }
        return available_moves;
    }
    else if (type == PieceType::Rook) {
        std::vector<int> available_moves = {};
        int directions[4] = {-1,1,8,-8};
        for (int direction: directions) {
            for (int i = 0; i < 8; i++) {
                int movement = direction * i;
                int new_position = position + movement;
                if (new_position > 63 || new_position < 0) {
                    break;
                }
                if (std::abs(direction) == 1 && (new_position / 8) != (position / 8)) {
                    break;
                }
                if (!board[new_position].has_value()) {
                    if ((*board[new_position]).color != this->color) {
                        available_moves.push_back(movement);
                    }
                    break;
                }
                available_moves.push_back(movement);
            }
        }
        return available_moves;
    }
    else if (PieceType::Queen == type) {
        std::vector<int> available_moves = {};
        int directions[8] = {-1,1,8,-8,-9,9,7,-7};
        for (int direction: directions) {
            for (int i = 0; i < 8; i++) {
                int movement = direction * i;
                int new_position = position + movement;
                if (new_position > 63 || new_position < 0) {
                    break;
                }
                if (std::abs(direction) == 1 && (new_position / 8) != (position / 8)) {
                    break;
                }
                else if (std::abs(direction) != 1  && std::abs((new_position / 8) - (position / 8)) != i) {
                    break;
                }
                if (!board[new_position].has_value()) {
                    if ((*board[new_position]).color != this->color) {
                        available_moves.push_back(movement);
                    }
                    break;
                }
                available_moves.push_back(movement);
            }
        }
        return available_moves;
    }
    else if (PieceType::King == type) {
        std::vector<int> available_moves = {};
        int directions[8] = {-1,1,8,-8,-9,9,7,-7};

        //Normal move logic
        for (int movement: directions) {
            int new_position = position + movement;
            if (new_position > 63 || new_position < 0) {
                continue;
            }
            if (std::abs(movement) == 1 && (new_position / 8) != (position / 8)) {
                continue;
            }
            else if (std::abs(movement) != 1  && std::abs((new_position / 8) - (position / 8)) != 1) {
                continue;
            }
            if (!board[new_position].has_value()) {
                if ((*board[new_position]).color != this->color) {
                    available_moves.push_back(movement);
                }
                continue;
            }
            available_moves.push_back(movement);
        }

        //Castling logic
        if (!this->has_moved) {
            if (!board[position + 1].has_value() && !board[position + 2].has_value()) {
                available_moves.push_back(2);
            }
            if (!board[position - 1].has_value() && !board[position - 2].has_value() && !board[position - 3].has_value()) {
                available_moves.push_back(-2);
            }
        }

        return available_moves;
    }

    return moves;
}

std::tuple<int,unsigned int,std::array<std::optional<Piece>,64>> Piece::do_move(std::array<std::optional<Piece>,64> board,int movement) {
    int position = -1; //remains -1 if piece is not found;

    // Find the index of the object by comparing memory addresses
    for (size_t i = 0; i < 64; ++i) {
        if (board[i].has_value() && &*board[i] == this) {
            position = i;
            break;
        }
    }

    int new_position = position + movement;

    std::optional<Piece> new_position_data = board[new_position];

    unsigned int piece_there_value = new_position_data.has_value() ? (*new_position_data).value : 0;

    std::array<std::optional<Piece>,64> new_board = board;
    new_board[position].reset();

    Piece moved_piece = *this;

    if (moved_piece.piece_type == PieceType::Pawn || moved_piece.piece_type == PieceType::King || moved_piece.piece_type == PieceType::Rook) {
        moved_piece.has_moved = true;
    }

    new_board[new_position] = moved_piece;

    //Castling Logic
    if (this->piece_type == PieceType::King) {
        if (movement == 2) {
            new_board[position + 1] = new_board[position + 3];
            new_board[position + 3].reset();
        }
        else if (movement == -2) {
            new_board[position - 1] = new_board[position - 4];
            new_board[position - 4].reset();
        }
    }
    else if (this->piece_type == PieceType::Pawn && (new_position / 8 == 0 || new_position / 8 == 7)) {
        piece_there_value += 8;
        new_board[new_position] = this->color == Color::White ? WHITE_QUEEN : BLACK_QUEEN;
    }

    return std::make_tuple(position,piece_there_value,new_board);
}