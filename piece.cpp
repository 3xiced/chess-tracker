#include "piece.h"

#include "exceptions.h"

/// @brief Explicitly moves piece to new position if it is in positions_can_move_to and on success recalculates positions_can_move_to.
/// @param new_pos New position in virtual coordinates.
/// @throws exceptions::ForbiddenMove if move is forbidden.
void Piece::Move(const utils::PositionVirtual& new_pos) {
    for (auto pos : *positions_can_move_to_) {
        if (pos.row != new_pos.row && pos.column != new_pos.column) continue;

        piece_info_.pos = new_pos;
        CalculatePositionsCanMoveTo();
        return;
    }
    throw new exceptions::ForbiddenMove();
}

Piece::~Piece() {
    delete positions_can_move_to_;
}
