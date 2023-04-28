#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : Piece {
   protected:
    void CalculatePositionsCanMoveTo() override {
        positions_can_move_to_->clear();
        auto x = pos().row;
        auto y = pos().column;

        if (piece_info().color == utils::Color::Black && y > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, y - 1));
        if (piece_info().color == utils::Color::White && y < 8)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, y + 1));
        if (piece_info().is_first_move && piece_info().color == utils::Color::Black)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, y - 2));
        if (piece_info().is_first_move && piece_info().color == utils::Color::White)
            positions_can_move_to_->push_back(utils::PositionVirtual(x, y + 2));
        if (piece_info().color == utils::Color::Black && y > 0 && x < 8)
            positions_can_move_to_->push_back(utils::PositionVirtual(x - 1, y - 1));
        if (piece_info().color == utils::Color::Black && y > 0 && x > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 1, y - 1));
        if (piece_info().color == utils::Color::White && y < 8 && x > 0)
            positions_can_move_to_->push_back(utils::PositionVirtual(x + 1, y + 1));
        if (piece_info().color == utils::Color::White && y < 8 && x < 8)
            positions_can_move_to_->push_back(utils::PositionVirtual(x - 1, y + 1));
    }
};

#endif
