//
// Created by Amey Venkatanarayan on 4/29/20.
//

#include "flappybird/Pipe.h"

Pipe::Pipe() {

}

Pipe::Pipe(int bird_height, int starting_row) {
  //Generates a pipe at a random height between 0 and 9
  int random = rand() % 10;
  if (random >= 6) {
    bottom_opening = random;
    top_opening = bottom_opening - 4;
  } else if (random <= 3) {
    top_opening = random;
    bottom_opening = top_opening + 4;
  } else {
    top_opening = random;
    bottom_opening = top_opening + 4;
  }
  row = starting_row;
}

void Pipe::SetPipeRow(int new_row) {
  row = new_row;
}

int Pipe::GetPipeRow() const {
  return row;
}

int Pipe::GetTopOpen() const {
  return top_opening;
}

int Pipe::GetBotOpen() const {
  return bottom_opening;
}


