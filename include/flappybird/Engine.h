//
// Created by Amey Venkatanarayan on 4/27/20.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

class Engine {
 public:
  Engine(int height, int score);
  Engine();
  int GetBirdHeight() const;
  void SetBirdHeight(int height);
  int GetGameScore() const;

 private:
  int bird_height;
  int game_score;
};

#endif  // FINALPROJECT_ENGINE_H
