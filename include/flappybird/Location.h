//
// Created by Amey Venkatanarayan on 4/27/20.
//

#ifndef FINALPROJECT_LOCATION_H
#define FINALPROJECT_LOCATION_H

class Location {
 public:
  Location(int row, int col);
  bool operator==(const Location& rhs) const;
  bool operator!=(const Location& rhs) const;
  int Row() const;
  int Col() const;
 private:
  int row_;
  int col_;
};

#endif  // FINALPROJECT_LOCATION_H
