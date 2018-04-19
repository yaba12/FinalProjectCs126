#pragma once
#include "ofMain.h"

class Tile {
public:
	int x_spawn;
	int y_spawn;
	ofColor stroke;
	int const width = 20;
	int const height = 20;

	Tile(int x, int y, ofColor outline);				//Creates a new tile
	~Tile();											//Deletes
	void draw();										//Draws the Tile
};
