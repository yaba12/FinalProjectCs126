#include "ofApp.h"
#include "cmath"

int const height = 20;
int const width = 10;
//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("Tetris");

	Background::init(width, height);
	default_shape_.CreateShapes();

	//Play the tetris theme song
	my_sound.load("C:\\Users\\Bryan\\Desktop\\tetris.mp3.mp3", true);
	my_sound.setLoop(true);
	my_sound.play();

}

//--------------------------------------------------------------
void ofApp::update() {
	if (current_state_ == IN_PROGRESS) {

		//Checks if we need a new block
		if (should_generate_shape) {
			random_shape = default_shape_.GetRandomShape();
			should_generate_shape = false;

		}
		if (!should_generate_shape) {

			//Checks if we need to set it, if not then we move down.
			if (IsAtBottom()) {
				SetBlockBottom();
				should_generate_shape = true;

			} else if (CollideWithBlock()) {
				SetBlock();
				should_generate_shape = true;

			} else {
				for (int row_index = 0; row_index < random_shape.size(); row_index++) {
					for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
						random_shape[row_index][col_index].x_spawn_ += x_change;
						random_shape[row_index][col_index].y_spawn_ += y_change;

					}
				}
			}

			//If we are at the edge, correct it.
			if (IsAtEdge()) {
				for (int row_index = 0; row_index < random_shape.size(); row_index++) {
					for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
						random_shape[row_index][col_index].x_spawn_ -= x_change;

					}
				}
			}
			if (IsOver()) {
				current_state_ = FINISHED;
			}
			int delete_row = CheckLine();

			if (delete_row >= 0) {
				Background::DeleteRow(delete_row);
				current_score++;

			}
			x_change = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (current_state_ == BEGIN) {
		DrawBegin();
	}
	if (current_state_ == FINISHED) {
		DrawFinished();
	}
	if (current_state_ == PAUSED) {
		DrawPaused();
	}
	background.draw();
	default_shape_.Draw(random_shape);
	DrawScore();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	int upper_key = toupper(key);

	if (upper_key == 'P' && current_state_ == IN_PROGRESS) {
		current_state_ = PAUSED;
	}
	else if (upper_key == 'B' && current_state_ == BEGIN) {
		current_state_ = IN_PROGRESS;
	}
	else if (upper_key == 'R' && current_state_ == FINISHED) {
		current_state_ = BEGIN;
		Background::Reset();
		NewGame();
	}
	else if (upper_key == 'P' && current_state_ == PAUSED) {
		current_state_ = IN_PROGRESS;
	}
	else if (upper_key == OF_KEY_LEFT && current_state_ == IN_PROGRESS) {
		x_change = -Tile::width;
	}
	else if (upper_key == OF_KEY_RIGHT && current_state_ == IN_PROGRESS) {
		x_change = Tile::width;
	}
	else if (upper_key == OF_KEY_DOWN && current_state_ == IN_PROGRESS) {
		ofSetFrameRate(50);
	}
	else if (upper_key == 'Z' && current_state_ == IN_PROGRESS) {
		Rotate();
	}
}

//--------------------------------------------------------------
void ofApp::DrawBegin() {
	string start_message_ = "Press B to begin";
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(start_message_, ofGetWindowHeight() / 2, ofGetWindowWidth() / 2);
}

//--------------------------------------------------------------
void ofApp::DrawPaused() {
	string pause_message_ = "Press P to unpause";
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(pause_message_, ofGetWindowHeight() / 2, ofGetWindowWidth() / 2);
}

//--------------------------------------------------------------
void ofApp::DrawFinished() {
	string end_message_ = "Press R to reset. Your score was " + to_string(current_score);
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(end_message_, ofGetWindowHeight() / 2, ofGetWindowWidth() / 2);
}

//--------------------------------------------------------------
void ofApp::DrawScore() {
	string score_message_ = "Score: " + to_string(current_score);
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(score_message_, ofGetWindowHeight() * 3 / 4, ofGetWindowWidth() * 3 / 4);

}

//--------------------------------------------------------------
bool ofApp::IsAtBottom() {

	//Checks if we are the bottom and if so, return true
	for (int row_index = 0; row_index < random_shape.size(); row_index++) {
		for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
			if (random_shape[row_index][col_index].y_spawn_ >= (height - 1) * Tile::width) {
				return true;
			}
		}
	}	
	return false;
}

//--------------------------------------------------------------
void ofApp::SetBlockBottom() {
	should_generate_shape = true;

	//Sets the block at the bottom row of the Background
	for (int row_index = 0; row_index < random_shape.size(); row_index++) {
		for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {

			//Checks if we go outside row borders
			if (random_shape[row_index][col_index].y_spawn_ < 0 || random_shape[row_index][col_index].x_spawn_ < 0) {
				current_state_ = FINISHED;
				break;
			}
			int x_coo = random_shape[row_index][col_index].x_spawn_;
			int y_coo = random_shape[row_index][col_index].y_spawn_;
			Tile current_tile = Background::GetTileFromCoo(x_coo, y_coo);

			//Change colors
			if (y_coo == current_tile.y_spawn_ &&x_coo == current_tile.x_spawn_) {
				Background::ChangeBackGroundColor(x_coo, y_coo, random_shape[row_index][col_index].inside_color_);
			}
		}
	}
}

//--------------------------------------------------------------
bool ofApp::IsAtEdge() {

	//Checks if we are outside the column borders
	for (int row_index = 0; row_index < random_shape.size(); row_index++) {
		for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
			if (random_shape[row_index][col_index].x_spawn_ >= (width) * Tile::width ||
				random_shape[row_index][col_index].x_spawn_ < 0) {
				return true;
			}
		}
	}
	return false;
}

//--------------------------------------------------------------
bool ofApp::CollideWithBlock() {

	//Checks if the current block we are on is not of orange color
	for (int row_index = 0; row_index < random_shape.size(); row_index++) {
		for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
			int x_coo = random_shape[row_index][col_index].x_spawn_;
			int y_coo = random_shape[row_index][col_index].y_spawn_;

			if (y_coo < 0 || x_coo < 0) {
				current_state_ = FINISHED;
				break;
			}
			Tile current_tile = Background::GetTileFromCoo(x_coo, y_coo);

			if (current_tile.inside_color_ != ofColor::orange) {
				return true;
			}
		}
	}
	return false;
}

//--------------------------------------------------------------
void ofApp::SetBlock() {

	//If the current block we are on is orange, move it back.
	for (int row_index = 0; row_index < random_shape.size(); row_index++) {
		for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
			random_shape[row_index][col_index].y_spawn_ -= y_change;
			random_shape[row_index][col_index].x_spawn_ -= x_change;
			int x_coo = random_shape[row_index][col_index].x_spawn_;
			int y_coo = random_shape[row_index][col_index].y_spawn_;

			if (y_coo < 0 || x_coo < 0) {
				current_state_ = FINISHED;
				break;
			}
			Tile current_tile = Background::GetTileFromCoo(random_shape[row_index][col_index].x_spawn_, random_shape[row_index][col_index].y_spawn_);
			
			if (y_coo == current_tile.y_spawn_ && x_coo == current_tile.x_spawn_) {
				Background::ChangeBackGroundColor(x_coo, y_coo, random_shape[row_index][col_index].inside_color_);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::Rotate() {
	Tile starting_point = random_shape[0][0];

	for (int row_index = 0; row_index < random_shape.size(); row_index++) {
		for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
			int temp_x = random_shape[row_index][col_index].x_spawn_ - starting_point.x_spawn_;
			int temp_y = random_shape[row_index][col_index].y_spawn_ - starting_point.y_spawn_;
			random_shape[row_index][col_index].x_spawn_ = temp_y + starting_point.x_spawn_;
			random_shape[row_index][col_index].y_spawn_ = temp_x + starting_point.y_spawn_;
		}
	}

	//Moves Back any tiles that rotated out of the Background
	while (CheckXNegative()) {
		for (int row_index = 0; row_index < random_shape.size(); row_index++) {
			for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
				random_shape[row_index][col_index].x_spawn_ += Tile::width;
			}
		}
	}

	//Moves Back any tiles that rotated out of the Background
	while (CheckXOver()) {
		for (int row_index = 0; row_index < random_shape.size(); row_index++) {
			for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
				random_shape[row_index][col_index].x_spawn_ -= Tile::width;
			}
		}
	}

}

//--------------------------------------------------------------
bool ofApp::CheckXNegative() {

	//Checks to see if any Tiles in Shapes are outside the borders
	for (int row_index = 0; row_index < random_shape.size(); row_index++) {
		for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
			if (random_shape[row_index][col_index].x_spawn_ < 0) {
				return true;
			}
		}
	}
	return false;
}

//--------------------------------------------------------------
bool ofApp::CheckXOver() {

	//Checks to see if any Tiles in Shapes are outside the borders
	for (int row_index = 0; row_index < random_shape.size(); row_index++) {
		for (int col_index = 0; col_index < random_shape[row_index].size(); col_index++) {
			if (random_shape[row_index][col_index].x_spawn_ >= columns * Tile::width) {
				return true;
			}	
		}
	}
	return false;
}

//--------------------------------------------------------------
int ofApp::CheckLine() {

	//Checks to see if we have a full Line of blocks
	for (int row_index = 0; row_index < Background::background_tile[0].size(); row_index++) {
		bool full_row = true;

		for (int col_index = 0; col_index < Background::background_tile.size() ; col_index++) {
			if (Background::background_tile[col_index][row_index].inside_color_ == ofColor::orange) {
				full_row = false;
			}
		}
		if (full_row) {
			return row_index;
		}
	}
	return -1;
}

//--------------------------------------------------------------
bool ofApp::IsOver() {
	for (int row_index = 0; row_index < Background::background_tile.size(); row_index++) {
		if (Background::background_tile[row_index][0].inside_color_ != ofColor::orange) {
			return true;
		}
	}
	return false;
}

//--------------------------------------------------------------
void ofApp::NewGame() {
	Background::init(width, height);
	current_score = 0;
}


