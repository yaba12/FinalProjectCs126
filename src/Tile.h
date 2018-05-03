#pragma once
#include "ofMain.h"

class Tile {
public:
	int x_spawn;
	int y_spawn;
	ofColor stroke;
	ofColor inside_color;
	static int const width = 50;
	static int const height = 50;

	Tile(int x, int y, ofColor outline, ofColor fill);	//Creates a new tile
	void draw();										//Draws the Tile
};
