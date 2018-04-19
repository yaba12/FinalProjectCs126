#include "BackGround.h"
#include <vector>

BackGround::BackGround(int row, int col) {
	rows = row;
	cols = col;
	for (int i = 0; i < row; i++) {
		std::vector<Tile> row;
		for (int j = 0; j < col; j++) {
			row.push_back(Tile(i * height, j * width, ofColor::orange));
		}
		background_tile.push_back(row);
	}
}

	void BackGround::draw() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				background_tile[i][j].draw();
			}
		}
	}
	
	void BackGround::delete_bottom_row() {
		std::vector<std::vector<Tile>> temp_other;
		for (int i = 0; i < rows; i++) {
			std::vector<Tile> temp_row;
			for (int j = 0; j < cols; j++) {
				if (i == rows - 1) {
					temp_row.push_back(Tile(i * height, j * width, ofColor::orange));
				}	
				else {
					temp_row.push_back(background_tile[i][j]);
				}
				temp_other.push_back(temp_row);
			}
		}
