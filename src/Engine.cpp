//
// Created by Amey Venkatanarayan on 4/27/20.
//

#include "flappybird/Engine.h"

Engine::Engine() {

}

Engine::Engine(int height, int score) {
  bird_height = height;
  game_score = score;
}

int Engine::GetBirdHeight() const {
  return bird_height;
}

void Engine::SetBirdHeight(int height) {
  bird_height = height;
}

int Engine::GetGameScore() const {
  return game_score;
}


