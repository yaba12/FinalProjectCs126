#include "BackGround.h"
#include <vector>

std::vector<std::vector<Tile>> Background::background_tile;

  void Background::init(int row, int col) {
	for (int row_index = 0; row_index < row; row_index++) {
		std::vector<Tile> row;

		for (int col_index = 0; col_index < col; col_index++) {
			row.push_back(Tile(row_index * Tile::height, col_index * Tile::width, ofColor::orange, ofColor::black));
		}
		background_tile.push_back(row);
	}	
}

void Background::draw() {
	for (int row_index = 0; row_index < background_tile.size(); row_index++) {
		for (int col_index = 0; col_index < background_tile[0].size(); col_index++) {
			background_tile[row_index][col_index].draw();
		}
	}
}

void Background::DeleteRow(int row) {

	//Shift every row down one, and the new one on top is orange
	for (int row_index = 0; row_index < background_tile.size(); row_index++) {
		for (int col_index = row; col_index >= 0; col_index--) {
			if (col_index - 1 >= 0) {
				background_tile[row_index][col_index].inside_color_ = background_tile[row_index][col_index - 1].inside_color_;
			}
			else {
				background_tile[row_index][0].inside_color_ = ofColor::orange;
			}
		}
	}
}

Tile Background::GetTileFromCoo(int x_coo, int y_coo) {

	//Calculate which Tile we are on
	int x_block = x_coo / Tile::width;
	int y_block = y_coo / Tile::height;
	return background_tile[x_block][y_block];
}

void Background::ChangeBackGroundColor(int x_coo, int y_coo, ofColor new_color) {
	
	//Change the color of our current Tile
	Tile current_tile = GetTileFromCoo(x_coo, y_coo);
	current_tile.inside_color_ = new_color;
}

void Background::Reset() {
	for (int row_index = 0; row_index < background_tile.size(); row_index++) {
		background_tile[0].clear();
	}

	background_tile.clear();
}
