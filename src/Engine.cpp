//
// Created by Amey Venkatanarayan on 4/27/20.
//

#include "flappybird/Engine.h"

Engine::Engine() {
  bird_height = 0;
  game_score = 0;
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

bool Engine::IsGameOver(Pipe pipe) {
  if (bird_height >= pipe.GetTopOpen() && bird_height < pipe.GetBotOpen()) {
    game_score = game_score+1;
    cinder::audio::SourceFileRef musicFile =
        cinder::audio::load(cinder::app::loadAsset("point.mp3"));
    noisePlayer = cinder::audio::Voice::create(musicFile);
    noisePlayer->start();
    return false;
  }
  if (game_ended == false) {
    cinder::audio::SourceFileRef musicFile =
        cinder::audio::load(cinder::app::loadAsset("hit.mp3"));
    noisePlayer = cinder::audio::Voice::create(musicFile);
    noisePlayer->start();
    cinder::audio::SourceFileRef musicFile2 =
        cinder::audio::load(cinder::app::loadAsset("die.mp3"));
    noisePlayer = cinder::audio::Voice::create(musicFile2);
    noisePlayer->start();
    game_ended = true;
  }
  return true;
}
