#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

#include "utils.h"

class MagnetBase;
class Piece;

class Board {
   public:
    explicit Board(std::vector<Piece*>* board_pieces) : board_pieces_(board_pieces){};
    explicit Board() : board_pieces_(new std::vector<Piece*>()){};

    std::vector<Piece*>* board_pieces() { return board_pieces_; };
    void MovePieceToNewLocation(Piece& piece, const utils::PositionVirtual& new_position);
    void AddPiece(Piece* piece_ptr) { board_pieces_->push_back(piece_ptr); };

   private:
    bool IsLegalMove(const Piece& piece, const utils::PositionVirtual& new_position) const;
    std::vector<utils::PositionVirtual> GetCellsTouchedByMovingPiece(
        const utils::PositionVirtual& start_pos,
        const utils::PositionVirtual& end_pos) const;

    std::vector<Piece*>* board_pieces_;
    MagnetBase* magnet_;
};

#endif  // BOARD_H
