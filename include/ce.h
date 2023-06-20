#include <string>
#include "piece.h"

std::vector<std::string> split(std::string s, std::string delimiter);
std::tuple<std::array<std::optional<Piece>,64>,int> parse_fen(std::string fen);

// std::tuple<size_t,int,float,std::optional<std::vector<std::tuple<size_t,int,float>>>> process_move(board: &[Option<Piece> ; 64],whos_move: Color,recursion_level: u8,current_recursion: u8,sign: f32,movement: i8,alpha: &mut f32, beta: &mut f32, 
//     calculated_ordered_move_list: &mut Vec<(usize,i8,f32)>,mut transposition_table: &mut HashMap<u64, f32>,best_score: &mut f32, best_move: &mut i8
//     ,best_piece_position: &mut usize, value: f32, zobrist_hasher: &ZobristHash, piece: &Piece) -> Option<(usize,i8,f32,Option<Vec<(usize,i8,f32)>>)>