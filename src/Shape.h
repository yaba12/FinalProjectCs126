#pragma once
#include "Tile.h"
#include <vector>

class Shape {
public:
	std::vector<std::vector<std::vector<Tile>>> different_shapes;
	
	//Make the Shapes and add to vector
	void CreateShapes();
	void CreateSquare();
	void CreateT();
	void CreateL();
	void CreateLowerCasel();
	void CreateS();
	void CreateZ();
	void CreateJ();
	std::vector < std::vector<Tile>> GetRandomShape();
	void draw(std::vector<std::vector<Tile>> shape);
};
