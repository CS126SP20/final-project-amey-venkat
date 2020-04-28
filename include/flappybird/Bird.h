//
// Created by Amey Venkatanarayan on 4/27/20.
//

#ifndef FINALPROJECT_BIRD_H
#define FINALPROJECT_BIRD_H

#include "Location.h"

class Bird {
 public:
  explicit Bird(const Location& location);
  Location GetLocation() const;
  Location SetLocation(const Location&);
 private:
  Location location_;
  bool visible_;
};

#endif  // FINALPROJECT_BIRD_H
