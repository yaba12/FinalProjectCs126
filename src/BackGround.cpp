#include "BackGround.h"
#include <vector>

BackGround::BackGround(int row, int col) {
	rows = row;
	cols = col;
	for (int x_index = 0; x_index < row; x_index++) {
		std::vector<Tile> row;
		for (int y_index = 0; y_index < col; y_index++) {
			row.push_back(Tile(x_index * height, y_index * width, ofColor::orange));
		}
		background_tile.push_back(row);
	}
}

void BackGround::draw() {
	for (int x_index = 0; x_index < rows; x_index++) {
		for (int y_index = 0; y_index < cols; y_index++) {
			background_tile[x_index][y_index].draw();
		}
	}
}

void BackGround::delete_row(int row) {
	for (int x_index = row; x_index >= 0; x_index++) {
		for (int y_index = 0; y_index < cols; y_index++) {
			if (x_index - 1 >= 0) {
				background_tile[y_index][x_index].stroke = background_tile[y_index - 1][x_index].stroke;
			}
			else {
				background_tile[y_index][0].stroke = ofColor::orange;
			}
		}
	}
}
