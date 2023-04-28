#ifndef MAGNETBASE_H
#define MAGNETBASE_H

#include <vector>

#include "utils.h"

class MagnetBase {
   public:
    virtual void Move(const utils::PositionReal& new_position) = 0;
    virtual void Center(double centering_radius) = 0;
    virtual void Grab() = 0;
    virtual void Release() = 0;

    const utils::PositionReal& pos() { return pos_; };

   private:
    utils::PositionReal pos_;
};

#endif  // MAGNETBASE_H
