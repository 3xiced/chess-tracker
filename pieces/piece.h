#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include "utils.h"

class Piece {
   public:
    explicit Piece(const utils::PieceInfo& info) : piece_info_(info), positions_can_move_to_(new std::vector<utils::PositionVirtual>()) {}
    explicit Piece() : positions_can_move_to_(new std::vector<utils::PositionVirtual>()) {}
    ~Piece();

    const utils::PositionVirtual& pos() const { return piece_info_.pos; };
    const std::vector<utils::PositionVirtual>* positions_can_move_to() const { return positions_can_move_to_; };
    const utils::PieceInfo& piece_info() const { return piece_info_; };
    void Move(const utils::PositionVirtual& new_pos);

   protected:
    utils::PieceInfo piece_info_;
    std::vector<utils::PositionVirtual>* positions_can_move_to_;

    virtual void CalculatePositionsCanMoveTo() = 0;
};

#endif  // PIECE_H
