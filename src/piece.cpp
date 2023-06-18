#include "enums.h"
#include "piece.h"
#include <vector>
#include <cstdlib>

// Constructor implementation/definition
Piece::Piece(Color color, PieceType piece_type, unsigned int value, bool has_moved) {
    this->color = color;
    this->piece_type = piece_type;
    this->value = value;
    this->has_moved = has_moved;
}

std::vector<int> Piece::get_moves(Piece board[64]) {
    int position = -1; //remains -1 if piece is not found;

    // Find the index of the object by comparing memory addresses
    for (size_t i = 0; i < 64; ++i) {
        if (&board[i] == this) {
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
            if (board[new_position].color != this->color) {
                moves.push_back(9 * direction);
            }
        }
        new_position = position + 7 * direction;
        if (std::abs((new_position / 8) - (position / 8)) == 1) {
            if (board[new_position].color != this->color) {
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
            if (board[new_position].color == this->color) {
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
                if (&board[new_position] != nullptr) {
                    if (board[new_position].color != this->color) {
                        available_moves.push_back(movement);
                    }
                    break;
                }
                available_moves.push_back(movement);
            }
        }
        return available_moves;
    }
    //     PieceType::Rook => {
    //         let mut available_moves: Vec<i8> = vec![];
    //         let directions: [i8;4] = [-1,1,8,-8];
    //         for direction in directions {
    //             for i in 1..8 {
    //                 let movement: i8 = direction * i;
    //                 let new_position = position as i8 + movement;
    //                 if new_position > 63 || new_position < 0 {
    //                     break;
    //                 }
    //                 if direction.abs() == 1 && (new_position / 8) != (position / 8) as i8 {
    //                     break;
    //                 }
    //                 if let Some(piece) = &board[new_position as usize] {
    //                     if piece.color != self.color {
    //                         available_moves.push(movement);
    //                     }
    //                     break;
    //                 }
    //                 available_moves.push(movement);
    //             }
    //         }
    //         available_moves
    //     },
    //     PieceType::Queen => {
    //         let mut available_moves: Vec<i8> = vec![];
    //         let directions: [i8;8] = [-1,1,8,-8,-9,9,7,-7];
    //         for direction in directions {
    //             for i in 1..8 {
    //                 let movement: i8 = direction * i;
    //                 let new_position = position as i8 + movement;
    //                 if new_position > 63 || new_position < 0 {
    //                     break;
    //                 }
    //                 if direction.abs() == 1 && (new_position / 8) != (position / 8) as i8 {
    //                     break;
    //                 }
    //                 else if direction.abs() != 1  && ((new_position / 8) - (position / 8) as i8).abs() != i {
    //                     break;
    //                 }
    //                 if let Some(piece) = &board[new_position as usize] {
    //                     if piece.color != self.color {
    //                         available_moves.push(movement);
    //                     }
    //                     break;
    //                 }
    //                 available_moves.push(movement);
    //             }
    //         }
    //         available_moves
    //     },
    //     PieceType::King => {
    //         let mut available_moves: Vec<i8> = vec![];
    //         let directions: [i8;8] = [-1,1,8,-8,-9,9,7,-7];

    //         //Normal move logic
    //         for movement in directions {
    //             let new_position = position as i8 + movement;
    //             if new_position > 63 || new_position < 0 {
    //                 continue;
    //             }
    //             if movement.abs() == 1 && (new_position / 8) != (position / 8) as i8 {
    //                 continue;
    //             }
    //             else if movement.abs() != 1  && ((new_position / 8) - (position / 8) as i8).abs() != 1 {
    //                 continue;
    //             }
    //             if let Some(piece) = &board[new_position as usize] {
    //                 if piece.color != self.color {
    //                     available_moves.push(movement);
    //                 }
    //                 continue;
    //             }
    //             available_moves.push(movement);
    //         }

    //         //Castling logic
    //         if !self.has_moved {
    //             if board[position + 1].is_none() && board[position + 2].is_none() {
    //                 available_moves.push(2);
    //             }
    //             if board[position - 1].is_none() && board[position - 2].is_none() && board[position - 3].is_none() {
    //                 available_moves.push(-2);
    //             }
    //         }

    //         available_moves
    //     }
    // };
    // return moves;
}