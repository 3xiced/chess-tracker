#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : Piece {
   protected:
    void CalculatePositionsCanMoveTo() override {
        positions_can_move_to_->clear();
        auto x = pos().row;
        auto y = pos().column;

        for (char i = 1; i < 8; i++) {
            if (x + i < 8)
                positions_can_move_to_->push_back(utils::PositionVirtual(x + i, y));  // Вверх
            else
                break;
        }

        for (char i = 1; i < 8; i++) {
            if (x - i >= 0)
                positions_can_move_to_->push_back(utils::PositionVirtual(x - i, y));  // Вниз
            else
                break;
        }
        for (char i = 1; i < 8; i++) {
            if (y + i < 8)
                positions_can_move_to_->push_back(utils::PositionVirtual(x, y + i));  // Вправо
            else
                break;
        }
        for (char i = 1; i < 8; i++) {
            if (y - i >= 0)
                positions_can_move_to_->push_back(utils::PositionVirtual(x, y - i));  // Влево
            else
                break;
        }

        for (char i = 1; i < 8; i++) {
            if (x + i < 8 && y + i < 8)
                positions_can_move_to_->push_back(utils::PositionVirtual(x + i, y + i));  // Вверх вправо
            else
                break;
        }

        for (char i = 1; i < 8; i++) {
            if (x - i >= 0 && y + i < 8)
                positions_can_move_to_->push_back(utils::PositionVirtual(x - i, y + i));  // Вниз вправо
            else
                break;
        }
        for (char i = 1; i < 8; i++) {
            if (x + i < 8 && y - i >= 0)
                positions_can_move_to_->push_back(utils::PositionVirtual(x + i, y - i));  // Вверх влево
            else
                break;
        }
        for (char i = 1; i < 8; i++) {
            if (x - i >= 0 && y - i >= 0)
                positions_can_move_to_->push_back(utils::PositionVirtual(x + i, y + i));  // Вниз влево
            else
                break;
        }
    }
};

#endif
