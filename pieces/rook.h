#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : Piece {
   protected:
    void CalculatePositionsCanMoveTo() override {
        positions_can_move_to_->clear();
        auto x = pos().row;
        auto y = pos().column;

        for (char i = x + 1; i < 8; i++)
            positions_can_move_to_->push_back(utils::PositionVirtual(i, y));

        for (char i = x - 1; i > -1; i--)
            positions_can_move_to_->push_back(utils::PositionVirtual(i, y));

        for (char i = y + 1; i < 8; i++)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, i));

        for (char i = y - 1; i > -1; i--)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, i));
    }
};

#endif
