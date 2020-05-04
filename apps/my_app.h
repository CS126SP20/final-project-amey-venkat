// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <cinder/gl/gl.h>
#include <Box2D/Box2D.h>
#include <cinder/audio/voice.h>
#include <time.h>
#include <vector>
#include <string>

#include "flappybird/Bird.h"
#include "flappybird/Engine.h"
#include "flappybird/Pipe.h"
#include "flappybird/Location.h"

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  void DrawBird() const;
  void DrawPipe(Pipe pipe) const;
  void DrawGameOver() const;
  void PrintText(const std::string& text, const cinder::Color& color, const cinder::ivec2& size,
                 const cinder::vec2& loc) const;
  cinder::gl::Texture2dRef board_image;
  cinder::gl::Texture2dRef plane_image;
  cinder::audio::VoiceRef noisePlayer;

 private:
  Engine *engine_ = new Engine();
  int count = 0;

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
