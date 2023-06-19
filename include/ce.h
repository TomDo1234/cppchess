#include <tuple>
#include <array>
#include <optional>
#include <string>
#include "enums.h"
#include "piece.h"

std::tuple<std::array<std::optional<Piece>,64>,int> parse_fen(std::string fen);