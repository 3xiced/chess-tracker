#include "board.h"

#include "exceptions.h"
#include "magnetbase.h"
#include "piece.h"

/// @brief Moves piece to new location. Checks if current move is illegal, else moves piece
/// by moving magnet. Next, goes over cells touched by moving piece and centers pieces on them in case
/// they were accidentally moved from the center.
/// @param piece Piece.
/// @param new_position Position to move piece to.
/// @throws exceptions::ForbiddenMove
void Board::MovePieceToNewLocation(Piece& piece, const utils::PositionVirtual& new_position) {
    if (!IsLegalMove(piece, new_position))
        throw exceptions::ForbiddenMove();
    utils::PositionVirtual old_piece_position = piece.pos();
    try {
        piece.Move(new_position);
    } catch (const exceptions::ForbiddenMove& e) {
        throw e;
    }

    utils::PositionReal conv_old_piece_position = utils::ConvertVirtualToReal(old_piece_position);
    magnet_->Move(conv_old_piece_position);
    magnet_->Grab();
    magnet_->Move(utils::ConvertVirtualToReal(new_position));
    magnet_->Release();

    auto cells = GetCellsTouchedByMovingPiece(old_piece_position, new_position);
    for (auto cell : cells) {
        magnet_->Move(utils::ConvertVirtualToReal(cell));
        magnet_->Grab();
        magnet_->Center(utils::kCellCenterHeight);
        magnet_->Release();
    }
}

/// @brief Checks if piece move is illegal (new pos is already busy and pieces colors are equal).
/// @param piece Piece
/// @param new_position New position piece is moved to
/// @return bool
bool Board::IsLegalMove(const Piece& piece, const utils::PositionVirtual& new_position) const {
    for (auto piece : *board_pieces_) {
        auto piece_info = piece->piece_info();
        auto current_piece_info = piece->piece_info();

        if (piece_info.pos.column == new_position.column && piece_info.pos.row == new_position.row)
            if (piece_info.color == current_piece_info.color)
                return false;
    }
    return true;
}

/// @brief Gets cells touched by moving piece of any kind
/// @param start_pos start position of piece
/// @param end_pos end position of piece
/// @return vector of cells touched by piece
std::vector<utils::PositionVirtual> Board::GetCellsTouchedByMovingPiece(
    const utils::PositionVirtual& start_pos,
    const utils::PositionVirtual& end_pos) const {
    std::vector<utils::PositionVirtual> moves;

    int dx = start_pos.column - end_pos.column;
    int dy = start_pos.row - end_pos.row;

    if (abs(dx) == abs(dy)) {
        if (dx > 0 && dy > 0) {
            for (char i = start_pos.column, j = start_pos.row; i < end_pos.column; i++, j++) {
                moves.push_back(utils::PositionVirtual(j, i + 1));
                moves.push_back(utils::PositionVirtual(j + 1, i));
            }
        } else if (dx > 0 && dy < 0) {
            for (char i = start_pos.column, j = start_pos.row; i < end_pos.column; i++, j--) {
                moves.push_back(utils::PositionVirtual(j, i + 1));
                moves.push_back(utils::PositionVirtual(j - 1, i));
            }
        } else if (dx < 0 && dy < 0) {
            for (char i = start_pos.column, j = start_pos.row; i > end_pos.column; i--, j--) {
                moves.push_back(utils::PositionVirtual(j, i - 1));
                moves.push_back(utils::PositionVirtual(j - 1, i));
            }
        } else if (dx > 0 && dy > 0) {
            for (char i = start_pos.column, j = start_pos.row; i > end_pos.column; i--, j++) {
                moves.push_back(utils::PositionVirtual(j, i - 1));
                moves.push_back(utils::PositionVirtual(j + 1, i));
            }
        }
    } else {
        if (dx == 1 && dy == 2) {
            moves.push_back(utils::PositionVirtual(start_pos.row + 1, start_pos.column));
            moves.push_back(utils::PositionVirtual(start_pos.row + 1, start_pos.column + 1));
        } else if (dx == 2 && dy == 1) {
            moves.push_back(utils::PositionVirtual(start_pos.row, start_pos.column + 1));
            moves.push_back(utils::PositionVirtual(start_pos.row + 1, start_pos.column + 1));
        } else if (dx == 2 && dy == -1) {
            moves.push_back(utils::PositionVirtual(start_pos.row, start_pos.column + 1));
            moves.push_back(utils::PositionVirtual(start_pos.row - 1, start_pos.column + 1));
        } else if (dx == 1 && dy == -2) {
            moves.push_back(utils::PositionVirtual(start_pos.row - 1, start_pos.column + 1));
            moves.push_back(utils::PositionVirtual(start_pos.row - 1, start_pos.column));
        } else if (dx == -1 && dy == -2) {
            moves.push_back(utils::PositionVirtual(start_pos.row - 1, start_pos.column));
            moves.push_back(utils::PositionVirtual(start_pos.row - 1, start_pos.column - 1));
        } else if (dx == -2 && dy == -1) {
            moves.push_back(utils::PositionVirtual(start_pos.row - 1, start_pos.column));
            moves.push_back(utils::PositionVirtual(start_pos.row - 1, start_pos.column - 1));
        } else if (dx == -2 && dy == 1) {
            moves.push_back(utils::PositionVirtual(start_pos.row, start_pos.column - 1));
            moves.push_back(utils::PositionVirtual(start_pos.row + 1, start_pos.column - 1));
        } else if (dx == -1 && dy == 2) {
            moves.push_back(utils::PositionVirtual(start_pos.row + 1, start_pos.column - 1));
            moves.push_back(utils::PositionVirtual(start_pos.row + 1, start_pos.column));
        }
    }

    return moves;
}