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
  engine_ = new Engine(4, 0);
  //False means game is not over
  engine_->game_over = false;
  //Starts at the end of the board
  engine_->pipe1 = Pipe(engine_->GetBirdHeight(), 9);
  //Starts 5 units right of the first pipe
  engine_->pipe2 = Pipe(engine_->GetBirdHeight(), 14);
}

void MyApp::setup() {
  board_image = cinder::gl::Texture2d::create(loadImage(loadAsset("cave_background.jpg")));
}

void MyApp::update() {
  if (engine_->GetBirdHeight() != 9) {
    engine_->SetBirdHeight(engine_->GetBirdHeight() + 1);
  }

  if (count % 3 == 0) {
    engine_->pipe1.SetPipeRow(engine_->pipe1.GetPipeRow() - 1);
    engine_->pipe2.SetPipeRow(engine_->pipe2.GetPipeRow() - 1);
  }

  //Checks if the bird earns a point or if the game is over
  if (engine_->pipe1.GetPipeRow() == 2) {
    engine_->game_over = engine_->IsGameOver(engine_->pipe1);
  } else if (engine_->pipe2.GetPipeRow() == 2) {
    engine_->game_over = engine_->IsGameOver(engine_->pipe2);
  }

  //Redraws the pipes after they go off the left side of the screen
  if (engine_->pipe1.GetPipeRow() < 0) {
    engine_->pipe1 = Pipe(engine_->GetBirdHeight(), 9);
  } else if (engine_->pipe2.GetPipeRow() < 0) {
    engine_->pipe2 = Pipe(engine_->GetBirdHeight(), 9);
  }
  count++;
}

void MyApp::draw() {
  cinder::gl::clear();
  cinder::gl::enableAlphaBlending();
  cinder::gl::draw(board_image, getWindowBounds());
  if (engine_->game_over) {
    DrawGameOver();
    return;
  } else {
    DrawBird();
    DrawPipe(engine_->pipe1);
    DrawPipe(engine_->pipe2);
  }
}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_SPACE:
    case KeyEvent::KEY_UP: {
      if (!engine_->game_over) {
        cinder::audio::SourceFileRef musicFile =
            cinder::audio::load(cinder::app::loadAsset("wing.mp3"));
        noisePlayer = cinder::audio::Voice::create(musicFile);
        noisePlayer->start();
        if (engine_->GetBirdHeight() >= 0) {
          engine_->SetBirdHeight(engine_->GetBirdHeight() - 2);
          if (engine_->GetBirdHeight() < 0) {
            engine_->SetBirdHeight(-1);
          }
        }
        break;
      }
    }
  }
}

void MyApp::DrawBird() const {
  //Keeps the bird always in column 2 (third row from the left)
  cinder::gl::color(0, 0.75, 0);
  const Location loc = Location(2, engine_->GetBirdHeight());
  cinder::gl::drawSolidRect(cinder::Rectf(tile_size * loc.Row(),
                                  tile_size * loc.Col(),
                                  tile_size * loc.Row() + tile_size,
                                  tile_size * loc.Col() + tile_size));
}
void MyApp::DrawPipe(Pipe pipe) const {
  //Draw first pipe
  cinder::gl::color(1, 1, 1);
  const Location top_loc = Location(pipe.GetPipeRow(), pipe.GetTopOpen());
  if (pipe.GetTopOpen() > 0) {
    cinder::gl::drawSolidRect(cinder::Rectf(tile_size * top_loc.Row(),
                                            tile_size * top_loc.Col(),
                                            tile_size * top_loc.Row() + tile_size,
                                            tile_size * top_loc.Col() - pipe.GetTopOpen() * tile_size));
  }

  const Location bot_loc = Location(pipe.GetPipeRow(), pipe.GetBotOpen());
  if (pipe.GetBotOpen() <= 9) {
    cinder::gl::drawSolidRect(cinder::Rectf(tile_size * bot_loc.Row(),
                                            tile_size * bot_loc.Col(),
                                            tile_size * bot_loc.Row() + tile_size,
                                            tile_size * bot_loc.Col() + (10 - pipe.GetBotOpen()) * tile_size));
  }
}

void MyApp::PrintText(const std::string& text, const cinder::Color& color,
                      const cinder::ivec2& size, const cinder::vec2& loc) const{
  cinder::gl::color(color);

  auto box = cinder::TextBox()
      .alignment(cinder::TextBox::CENTER)
      .font(cinder::Font("Arial", 30))
      .size(size)
      .color(color)
      .backgroundColor(cinder::ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::DrawGameOver() const {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const cinder::Color color = cinder::Color::white();
  size_t row = 0;
  std::stringstream score;
  score << "Score: " << engine_->GetGameScore()/3;
  PrintText(score.str(), color, size, {center.x, center.y - 100});
}

}  // namespace myapp
