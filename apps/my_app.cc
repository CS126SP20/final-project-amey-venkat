// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>


#include <algorithm>
#include <chrono>
#include <cmath>


namespace myapp {

const int tile_size = 50;

using cinder::app::KeyEvent;

MyApp::MyApp() {
  srand(time(NULL));
  int random = rand() % 11;
  engine_ = Engine(4, 0);
}

void MyApp::setup() {
  board_image = cinder::gl::Texture2d::create(loadImage(loadAsset("cave_background.jpg")));
}

void MyApp::update() {

}

void MyApp::draw() {
  cinder::gl::clear();
  cinder::gl::draw(board_image, getWindowBounds());
  DrawBird();
}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_SPACE:
    case KeyEvent::KEY_UP: {
      if (engine_.GetBirdHeight() != 0) {
        engine_.SetBirdHeight(engine_.GetBirdHeight() - 1);
      }
      break;
    }
    case KeyEvent::KEY_DOWN: {
      if (engine_.GetBirdHeight() != 9) {
        engine_.SetBirdHeight(engine_.GetBirdHeight() + 1);
      }
      break;
    }
  }
}

void MyApp::DrawBird() const {
  const Location loc = Location(2, engine_.GetBirdHeight());
  cinder::gl::drawSolidRect(cinder::Rectf(tile_size * loc.Row(),
                                  tile_size * loc.Col(),
                                  tile_size * loc.Row() + tile_size,
                                  tile_size * loc.Col() + tile_size));
}

}  // namespace myapp
