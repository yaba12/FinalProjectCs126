#include "Tile.h"

Tile::Tile(int x, int y, ofColor outline) {
	x_spawn = x;
	y_spawn = y;
	stroke = outline;
}

Tile::~Tile() {
	delete this;
}

void Tile::draw() {
	ofSetColor(stroke);
	ofDrawRectangle(width, height, x_spawn, y_spawn);
}


