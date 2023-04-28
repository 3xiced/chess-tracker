#ifndef UTILS_H
#define UTILS_H

namespace utils {

extern const unsigned short kCellCenterWidth;
extern const unsigned short kCellCenterHeight;

enum Color {
    White,
    Black
};

struct PositionVirtual {
    explicit PositionVirtual(char row, char column) : row(row), column(column) {}
    explicit PositionVirtual() : row(0), column(0) {}
    char row;
    char column;
};

struct PositionReal {
    double x;
    double y;
};

struct PieceInfo {
    PositionVirtual pos;
    PieceType type;
    Color color;
    bool is_first_move = true;
};

enum class PieceType {
    kPawn,
    kBishup,
    kKing,
    kQueen,
    kRook,
    kKnight
};

PositionReal ConvertVirtualToReal(const PositionVirtual& pos);
PositionVirtual ConvertRealToVirtual(const PositionReal& pos);

}  // namespace utils

#endif