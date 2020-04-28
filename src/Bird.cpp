//
// Created by Amey Venkatanarayan on 4/27/20.
//

#include "flappybird/Bird.h"

Bird::Bird(const Location& location)
    : location_(location) {}


Location Bird::GetLocation() const {
  return location_;
}

Location Bird::SetLocation(const Location& location) {
  location_ = location;
  return location_;
}