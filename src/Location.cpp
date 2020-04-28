//
// Created by Amey Venkatanarayan on 4/27/20.
//

#include "flappybird/Location.h"

Location::Location(int row, int col) {
  row_= row;
  col_ = col;
}

bool Location::operator==(const Location& rhs) const {
  return row_ == rhs.row_ && col_ == rhs.col_;
}

bool Location::operator!=(const Location& rhs) const {
  return !(*this == rhs);
}

int Location::Row() const { return row_; }

int Location::Col() const { return col_; }
