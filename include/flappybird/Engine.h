//
// Created by Amey Venkatanarayan on 4/27/20.
//

#ifndef FINALPROJECT_ENGINE_H
#define FINALPROJECT_ENGINE_H

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#import <cinder/audio/Voice.h>
#include <cinder/audio/voice.h>
#include <cinder/gl/gl.h>

#import "Pipe.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "flappybird/Pipe.h"

class Engine {
 public:
  Engine(int starting_height, int score);
  Engine();
  int GetBirdHeight() const;
  void SetBirdHeight(int height);
  int GetGameScore() const;
  bool IsGameOver(Pipe pipe);
  Pipe pipe1;
  Pipe pipe2;
  bool game_over = false;
  cinder::audio::VoiceRef noisePlayer;
  bool game_ended = false;

 private:
  int bird_height;
  int game_score;
};

#endif  // FINALPROJECT_ENGINE_H
