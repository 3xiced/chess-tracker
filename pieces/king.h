#ifndef KING_H
#define KING_H

#include "piece.h"

class King : Piece {
   protected:
    void CalculatePositionsCanMoveTo() override {
        positions_can_move_to_->clear();
        auto x = pos().row;
        auto y = pos().column;

        if (x > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, y));  // Вниз
        if (x < 7)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 1, y));  // Вверх
        if (y > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, y - 1));  // Влево
        if (y < 7)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, y + 1));  // Вправо
        if (x > 0 && y > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x - 1, y - 1));  // Вниз влево
        if (x > 0 && y < 7)
            positions_can_move_to_->push_back(utils::PositionVirtual(x - 1, y + 1));  // Вниз вправо
        if (x < 7 && y > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 1, y - 1));  // Вверх влево
        if (x < 7 && y < 7)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 1, y + 1));  // Вверх вправо
    }
};

#endif
