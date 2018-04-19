#pragma once
#include <vector>
#include "Tile.h"

class BackGround {

public:
	int rows;
	int const width = 20;
	int const height = 20;
	int cols;
	std::vector<std::vector<Tile>> background_tile;		

	BackGround(int row, int col);								// Creates the background
	void delete_bottom_row();									// Deletes the bottom row
	void draw();												// Draws the Background


};
