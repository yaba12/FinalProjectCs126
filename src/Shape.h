#pragma once
#include "Tile.h"
#include <vector>

class Shape {
public:
	std::vector<std::vector<std::vector<Tile>>> different_shapes;
	void CreateShapes();
	std::vector < std::vector<Tile>> get_random_shape();
	void draw(std::vector<std::vector<Tile>> shape);
};
