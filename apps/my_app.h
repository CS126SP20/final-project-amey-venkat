// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <cinder/gl/gl.h>
#include <Box2D/Box2D.h>
#include <time.h>
#include <vector>

#include "flappybird/Bird.h"
#include "flappybird/Engine.h"
#include "flappybird/Location.h"

namespace myapp {

class MyApp : public cinder::app::App {
 private:
  void DrawBird() const;
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
