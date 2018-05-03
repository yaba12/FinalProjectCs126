#include "Tile.h"

Tile::Tile(int x, int y, ofColor fill, ofColor outline) {
	x_spawn = x;
	y_spawn = y;
	stroke = outline;
	inside_color = fill;
}

void Tile::draw() {
	ofFill();
	ofSetColor(inside_color);
	ofDrawRectangle(x_spawn, y_spawn, width, height);
	ofNoFill();
	ofSetColor(stroke);
	ofDrawRectangle(x_spawn, y_spawn, width, height);
}



