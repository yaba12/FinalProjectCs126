#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/Tile.h"
#include "../src/Shape.h"
#include "../src/Background.h"

TEST_CASE("MAKE NEW BACKGROUND") {
  Background background;
  Background::init(20, 20);
  REQUIRE(background_tile[0][0].inside_color_ == ofColor::orange);
  REQUIRE(background_tile[0][0].stroke == ofColor::black);
  }
  
  TEST_CASE("Get tile from coordinates") {
  Background background;
  Background::init(20, 20);
  Tile temp_tile = Background::GetTileFromCoo(450, 450);
  REQUIRE(temp_tile.x_spawn == background_tile[9][9].x_spawn);
  REQUIRE(temp_tile.y_spawn == background_tile[9][9].y_spawn);
  }
  
  TEST_CASE("Change color") {
  Background background;
  Background::init(20, 20);
  Background::ChangeBackGroundColor(450, 450, ofColor::pink);
  REQUIRE(background_tile[9][9].inside_color == ofColor::pink);
  REQUIRE(Background::GetTileFromCoo(450, 450).inside_color == ofColor::pink);
  }
  
  TEST_CASE("Test Delete Row") {
  Background background;
  Background::init(20, 20);
  Background::ChangeBackGroundColor(450, 450, ofColor::pink);
  Background::DeleteRow(9);
  REQUIRE(Background::GetTileFromCoo(450, 450).inside_color == ofColor::orange);
  Background::ChangeBackGroundColor(450, 450, ofColor::pink);
  REQUIRE(Background::GetTileFromCoo(450, 450).inside_color == ofColor::pink);
  }
