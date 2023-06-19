#include <tuple>
#include <array>
#include <optional>
#include <string>
#include "enums.h"
#include "piece.h"

std::vector<std::string> split(std::string s, std::string delimiter);
std::tuple<std::array<std::optional<Piece>,64>,int> parse_fen(std::string fen);