#include "Shape.h"
#include "Tile.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

void Shape::CreateShapes() {
	CreateSquare();
	CreateT();
	CreateL();
	CreateLowerCasel();
	CreateS();
	CreateZ();
	CreateJ();
}
	void CreateSquare(){
	std::vector<std::vector<Tile>> square_shape;
	std::vector<Tile> half_square;
	std::vector<Tile> other_half;
	half_square.push_back(Tile(0, 0, ofColor::yellow));
	half_square.push_back(Tile(0, Tile::height, ofColor::yellow));
	other_half.push_back(Tile(Tile::width, 0, ofColor::yellow));
	other_half.push_back(Tile(Tile::width, Tile::height, ofColor::yellow));
	square_shape.push_back(half_square);
	square_shape.push_back(other_half);
	different_shapes.push_back(square_shape);
	}

	void CreateT(){
		std::vector<std::vector<Tile>> t_shape;
	std::vector<Tile> right_t;
	std::vector<Tile> left_t;
	std::vector<Tile> middle_t;
	left_t.push_back(Tile(0, 0, ofColor::purple));
	middle_t.push_back(Tile(Tile::width, 0, ofColor::purple));
	middle_t.push_back(Tile(Tile::width, Tile::height, ofColor::purple));
	right_t.push_back(Tile(Tile::width * 2, 0, ofColor::purple));
	t_shape.push_back(left_t);
	t_shape.push_back(middle_t);
	t_shape.push_back(right_t);
	different_shapes.push_back(t_shape);
	}

	void CreateL(){
	std::vector<std::vector<Tile>> l_shape;
	std::vector<Tile> left_column;	
	std::vector<Tile> right_column;
	right_column.push_back(Tile(Tile::width, Tile::height * 2, ofColor::antiqueWhite));
	right_column.push_back(Tile(0, 0, ofColor::antiqueWhite));
	right_column.push_back(Tile(0, Tile::height, ofColor::antiqueWhite));
	right_column.push_back(Tile(0, Tile::height * 2, ofColor::antiqueWhite));
	l_shape.push_back(left_column);
	l_shape.push_back(right_column);
	different_shapes.push_back(l_shape);
	}

	void CreateLowerCasel() {
	std::vector<std::vector<Tile>> long_shape;
	std::vector<Tile> long_piece;
	long_piece.push_back(Tile(0, 0, ofColor::lightBlue));
	long_piece.push_back(Tile(0, Tile::height, ofColor::lightBlue));
	long_piece.push_back(Tile(0, Tile::height * 2, ofColor::lightBlue));
	long_piece.push_back(Tile(0, Tile::height * 3, ofColor::lightBlue));
	long_shape.push_back(long_piece);
	different_shapes.push_back(long_shape);
	}

	void CreateS(){
	std::vector<std::vector<Tile>> right_shape;
	std::vector<Tile> right_side_snake;
	std::vector<Tile> left_side_snake;
	std::vector<Tile> middle_side_snake;
	left_side_snake.push_back(Tile(0, Tile::height, ofColor::red));
	right_side_snake.push_back(Tile(Tile::width * 2, 0, ofColor::red));
	middle_side_snake.push_back(Tile(Tile::width, 0, ofColor::red));
	middle_side_snake.push_back(Tile(Tile::width, Tile::height, ofColor::red));
	right_shape.push_back(left_side_snake);
	right_shape.push_back(middle_side_snake);
	right_shape.push_back(right_side_snake);
	different_shapes.push_back(right_shape);
	}

	void CreateZ() {
	std::vector<std::vector<Tile>> left_shape;
	std::vector<Tile> other_right_side_snake;
	std::vector<Tile> ohter_left_side_snake;
	std::vector<Tile> other_middle_side_snake;
	ohter_left_side_snake.push_back(Tile(0, 0, ofColor::green));
	other_right_side_snake.push_back(Tile(Tile::width * 2, Tile::height, ofColor::green));
	other_middle_side_snake.push_back(Tile(Tile::width, 0, ofColor::green));
	other_middle_side_snake.push_back(Tile(Tile::width, Tile::height, ofColor::green));
	left_shape.push_back(ohter_left_side_snake);
	left_shape.push_back(other_middle_side_snake);
	left_shape.push_back(other_right_side_snake);
	different_shapes.push_back(left_shape);
	}

	void CreateJ(){
	std::vector<std::vector<Tile>> j_shape;
	std::vector<Tile> other_left_column;
	std::vector<Tile> other_right_column;
	other_left_column.push_back(Tile(0, Tile::height * 2, ofColor::black));
	other_right_column.push_back(Tile(Tile::width, 0, ofColor::black));
	other_right_column.push_back(Tile(Tile::width, Tile::height, ofColor::black));
	other_right_column.push_back(Tile(Tile::width, Tile::height * 2, ofColor::black));
	j_shape.push_back(other_left_column);
	j_shape.push_back(other_right_column);
	different_shapes.push_back(j_shape);
	}

std::vector<std::vector<Tile>> Shape::get_random_shape() {
	srand(time(NULL));
	int random_number = rand() % different_shapes.size() + 1;
	return different_shapes[random_number - 1];
}

void Shape::draw(std::vector<std::vector<Tile>> shape) {
	for (int i = 0; i < shape.size(); i++) {
		for (int j = 0; j < shape[0].size(); j++) {
			shape[i][j].draw();
		}
	}
}
