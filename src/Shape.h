
#pragma once
#include "Tile.h"
#include <vector>
class Shape {
private: 
	static std::vector<std::vector<std::vector<Tile>>> different_shapes;
	static void CreateSquare();									//Creates all the shapes we use
	static void CreateT();
	static void CreateL();
	static void CreateLowerCasel();
	static void CreateS();
	static void CreateZ();
	static void CreateJ();
		
public:
	static void CreateShapes();									//Generates list of different shapes
	static std::vector < std::vector<Tile>> GetRandomShape();	//Returns a randomly generated shape
	static void Draw(std::vector<std::vector<Tile>> shape);		//Draws the shape
	static void Move(std::vector<std::vector<Tile>> shape);		//Moves the shape
};
