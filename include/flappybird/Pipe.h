//
// Created by Amey Venkatanarayan on 4/29/20.
//

#ifndef FINALPROJECT_PIPE_H
#define FINALPROJECT_PIPE_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <cmath>

#include "Location.h"

class Pipe {
 public:
  Pipe();
  Pipe(int bird_height, int starting_row);
  void SetPipeRow(int new_row);
  int GetPipeRow() const;
  int GetTopOpen() const;
  int GetBotOpen() const;

 private:
  int top_opening;
  int bottom_opening;
  int row;
};

#endif  // FINALPROJECT_PIPE_H
