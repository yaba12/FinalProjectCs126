#pragma once
#include <vector>
#include "Tile.h"

class Background {

public:
	static int const WIDTH = 50;
	static int const HEIGHT = 50;
	static std::vector<std::vector<Tile>> background_tile;
	Background() {};	
	static void init(int row, int col);												// Creates the background
	static void DeleteRow(int row);													// Deletes the bottom row
	static void draw();																// Draws the Background
	static Tile GetTileFromCoo(int x_coo, int y_coo);								//Finds the Tile given coordinates
	static void ChangeBackGroundColor(int x_coo, int y_coo, ofColor new_color);		//Changes Background Color
	static void Reset();															//New Game
};
