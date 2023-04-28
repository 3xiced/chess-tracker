#include "utils.h"

namespace utils {

extern const unsigned short kCellCenterWidth{10};
extern const unsigned short kCellCenterHeight{10};

/// @brief Converts virtual position to real coordinates based on kCellCenterWidth and kCellCenterHeight.
/// [0][0] -> 10, 10
/// [1][0] -> 30, 10
/// [2][0] -> 50, 10
/// [2][1] -> 50, 30
/// @param pos Position represented in virtual coordinates.
/// @return Same position represented in real coordinates.
PositionReal ConvertVirtualToReal(const PositionVirtual& pos) {
    PositionReal new_pos;
    new_pos.x = kCellCenterWidth * (1 + 2 * pos.row);
    new_pos.y = kCellCenterHeight * (1 + 2 * pos.column);
    return new_pos;
};

/// @brief Converts real position to virtual coordinates based on kCellCenterWidth and kCellCenterHeight.
/// 50, 30 -> [2][1]
/// 10, 10 -> [0][0]
/// @param pos Position represented in real coordinates.
/// @return Same position represented in virtual coordinates.
PositionVirtual ConvertRealToVirtual(const PositionReal& pos) {
    PositionVirtual new_pos;
    new_pos.row = (pos.x - kCellCenterWidth) / (2 * kCellCenterWidth);
    new_pos.column = (pos.y - kCellCenterHeight) / (2 * kCellCenterHeight);
    return new_pos;
};

}  // namespace utils