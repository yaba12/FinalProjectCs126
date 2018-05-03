#include "Shape.h"
#include "Tile.h"
#include <stdlib.h>
#include <time.h>

std::vector<std::vector<std::vector<Tile>>> Shape::different_shapes;

void Shape::CreateShapes() {
	CreateSquare();
	CreateT();
	CreateL();
	CreateLowerCasel();
	CreateS();
	CreateZ();
	CreateJ();
}
void Shape::CreateSquare() {
	std::vector<std::vector<Tile>> square_shape;
	std::vector<Tile> half_square;
	std::vector<Tile> other_half;
	half_square.push_back(Tile(0, 0, ofColor::yellow, ofColor::black));
	half_square.push_back(Tile(0, Tile::height, ofColor::yellow, ofColor::black));
	other_half.push_back(Tile(Tile::width, 0, ofColor::yellow, ofColor::black));
	other_half.push_back(Tile(Tile::width, Tile::height, ofColor::yellow, ofColor::black));
	square_shape.push_back(half_square);
	square_shape.push_back(other_half);
	different_shapes.push_back(square_shape);
}

void Shape::CreateT() {
	std::vector<std::vector<Tile>> t_shape;
	std::vector<Tile> right_t;
	std::vector<Tile> left_t;
	std::vector<Tile> middle_t;
	left_t.push_back(Tile(0, 0, ofColor::purple, ofColor::black));
	middle_t.push_back(Tile(Tile::width, 0, ofColor::purple, ofColor::black));
	middle_t.push_back(Tile(Tile::width, Tile::height, ofColor::purple, ofColor::black));
	right_t.push_back(Tile(Tile::width * 2, 0, ofColor::purple, ofColor::black));
	t_shape.push_back(left_t);
	t_shape.push_back(middle_t);
	t_shape.push_back(right_t);
	different_shapes.push_back(t_shape);
}

void Shape::CreateL() {
	std::vector<std::vector<Tile>> l_shape;
	std::vector<Tile> left_column;
	std::vector<Tile> right_column;
	left_column.push_back(Tile(Tile::width, Tile::height + Tile::height, ofColor::antiqueWhite, ofColor::black));
	right_column.push_back(Tile(0, 0, ofColor::antiqueWhite, ofColor::black));
	right_column.push_back(Tile(0, Tile::height, ofColor::antiqueWhite, ofColor::black));
	right_column.push_back(Tile(0, Tile::height + Tile::height, ofColor::antiqueWhite, ofColor::black));
	l_shape.push_back(left_column);
	l_shape.push_back(right_column);
	different_shapes.push_back(l_shape);
}

void Shape::CreateLowerCasel() {
	std::vector<std::vector<Tile>> long_shape;
	std::vector<Tile> long_piece;
	long_piece.push_back(Tile(0, 0, ofColor::lightBlue, ofColor::black));
	long_piece.push_back(Tile(0, Tile::height, ofColor::lightBlue, ofColor::black));
	long_piece.push_back(Tile(0, Tile::height * 2, ofColor::lightBlue, ofColor::black));
	long_piece.push_back(Tile(0, Tile::height * 3, ofColor::lightBlue, ofColor::black));
	long_shape.push_back(long_piece);
	different_shapes.push_back(long_shape);
}

void Shape::CreateS() {
	std::vector<std::vector<Tile>> right_shape;
	std::vector<Tile> right_side_snake;
	std::vector<Tile> left_side_snake;
	std::vector<Tile> middle_side_snake;
	left_side_snake.push_back(Tile(0, Tile::height, ofColor::red, ofColor::black));
	right_side_snake.push_back(Tile(Tile::width + Tile::width, 0, ofColor::red, ofColor::black));
	middle_side_snake.push_back(Tile(Tile::width, 0, ofColor::red, ofColor::black));
	middle_side_snake.push_back(Tile(Tile::width, Tile::height, ofColor::red, ofColor::black));
	right_shape.push_back(left_side_snake);
	right_shape.push_back(middle_side_snake);
	right_shape.push_back(right_side_snake);
	different_shapes.push_back(right_shape);
}

void Shape::CreateZ() {
	std::vector<std::vector<Tile>> left_shape;
	std::vector<Tile> other_right_side_snake;
	std::vector<Tile> ohter_left_side_snake;
	std::vector<Tile> other_middle_side_snake;
	ohter_left_side_snake.push_back(Tile(0, 0, ofColor::green, ofColor::black));
	other_right_side_snake.push_back(Tile(Tile::width + Tile::width, Tile::height, ofColor::green, ofColor::black));
	other_middle_side_snake.push_back(Tile(Tile::width, 0, ofColor::green, ofColor::black));
	other_middle_side_snake.push_back(Tile(Tile::width, Tile::height, ofColor::green, ofColor::black));
	left_shape.push_back(ohter_left_side_snake);
	left_shape.push_back(other_middle_side_snake);
	left_shape.push_back(other_right_side_snake);
	different_shapes.push_back(left_shape);
}

void Shape::CreateJ() {
	std::vector<std::vector<Tile>> j_shape;
	std::vector<Tile> other_left_column;
	std::vector<Tile> other_right_column;
	other_left_column.push_back(Tile(0, Tile::height + Tile::height, ofColor::gray, ofColor::black));
	other_right_column.push_back(Tile(Tile::width, 0, ofColor::gray, ofColor::black));
	other_right_column.push_back(Tile(Tile::width, Tile::height, ofColor::gray, ofColor::black));
	other_right_column.push_back(Tile(Tile::width, Tile::height + Tile::height, ofColor::gray, ofColor::black));
	j_shape.push_back(other_left_column);
	j_shape.push_back(other_right_column);
	different_shapes.push_back(j_shape);
}

std::vector<std::vector<Tile>> Shape::GetRandomShape() {

	//Get a random number and return the Shape that is at the number
	srand(time(NULL));
	int random_number = rand() % different_shapes.size() + 1;
	return different_shapes[random_number - 1];
}

void Shape::Draw(std::vector<std::vector<Tile>> shape) {
	for (int row_index = 0; row_index < shape.size(); row_index++) {
		for (int col_index = 0; col_index < shape[row_index].size(); col_index++) {
			shape[row_index][col_index].draw();
		}
	}
}

void Shape::Move(std::vector<std::vector<Tile>> shape) {

	//Change the current Shape's coordinates
	for (int row_index = 0; row_index < shape.size(); row_index++) {
		for (int col_index = 0; col_index < shape[row_index].size(); col_index++) {
			shape[row_index][col_index].y_spawn_ += Tile::height;
		}
	}
}

