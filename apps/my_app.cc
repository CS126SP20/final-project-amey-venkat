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

MyApp::MyApp() { }

void MyApp::setup() {
  //cinder::gl::Texture2dRef background_ = cinder::gl::Texture2d::create(loadImage(loadAsset("cave_background.jpg")));
  //cinder::Area area = cinder::Area(0, 0, getWindowWidth() * 4, getWindowHeight() * 4);
  //cinder::gl::draw(background_, area);
  cinder::gl::clear(cinder::Color(0.5, 0, 0.75));
}

void MyApp::update() { }

void MyApp::draw() {
  DrawBird();
}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_SPACE:
    case KeyEvent::KEY_UP: {

      break;
    }
  }
}

void MyApp::DrawBird() const {
  srand(time(NULL));
  int random = rand() % 11;
  const Location loc = Location(2, random);
  cinder::gl::drawSolidRect(cinder::Rectf(tile_size * loc.Row(),
                                  tile_size * loc.Col(),
                                  tile_size * loc.Row() + tile_size,
                                  tile_size * loc.Col() + tile_size));
}

}  // namespace myapp
