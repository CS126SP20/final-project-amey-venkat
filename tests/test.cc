// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cinder/Rand.h>
#include <flappybird/Bird.h>
#include <flappybird/Engine.h>
#include <flappybird/Location.h>
#include <flappybird/Pipe.h>

#include <mylibrary/example.h>

TEST_CASE("Get bird height in engine after setting it", "[engine.h]") {
  Engine* engine = new Engine(4, 0);
  REQUIRE(engine->GetBirdHeight() == 4);
  engine->SetBirdHeight(5);
  REQUIRE(engine->GetBirdHeight() == 5);
}

TEST_CASE("Get the score of the game from engine", "[engine.h]") {
  Engine* engine = new Engine(4, 5);
  REQUIRE(engine->GetGameScore() == 5);
}

TEST_CASE("Get the row of the pipe after setting it", "[pipe.h]") {
  Pipe pipe = Pipe(4, 0);
  REQUIRE(pipe.GetPipeRow() == 0);
  pipe.SetPipeRow(5);
  REQUIRE(pipe.GetPipeRow() == 5);
}

TEST_CASE("Get location of the bird", "[bird.h]") {
  Bird bird = Bird(Location(2,4));
  REQUIRE(bird.GetLocation() == Location(2,4));
}
