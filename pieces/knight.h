#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : Piece {
   protected:
    void CalculatePositionsCanMoveTo() override {
        positions_can_move_to_->clear();
        auto x = pos().row;
        auto y = pos().column;

        if (x < 6 && y > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 2, y - 1));  // Вверх влево
        if (x < 6 && y < 7)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 2, y + 1));  // Вверх вправо
        if (x > 1 && y > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x - 2, y - 1));  // Вниз влево
        if (x > 1 && y < 7)
            positions_can_move_to_->push_back(utils::PositionVirtual(x - 2, y + 1));  // Вниз вправо
        if (x > 0 && y > 2)
            positions_can_move_to_->push_back(utils::PositionVirtual(x - 1, y - 2));  // Влево вниз
        if (x < 7 && y > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 1, y - 2));  // Влево вверх
        if (x > 1 && y < 6)
            positions_can_move_to_->push_back(utils::PositionVirtual(x - 1, y + 1));  // Вправо вниз
        if (x < 7 && y < 6)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 1, y + 2));  // Вправо вверх
    }
};

#endif
