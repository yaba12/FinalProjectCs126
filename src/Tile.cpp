#include "Tile.h"

Tile::Tile(int x, int y, ofColor fill, ofColor outline) {
	x_spawn_ = x;
	y_spawn_ = y;
	stroke = outline;
	inside_color_ = fill;
}

void Tile::draw() {
	ofFill();
	ofSetColor(inside_color_);
	ofDrawRectangle(x_spawn_, y_spawn_, width, height);
	ofNoFill();
	ofSetColor(stroke);
	ofDrawRectangle(x_spawn_, y_spawn_, width, height);
}



