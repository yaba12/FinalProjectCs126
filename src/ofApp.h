#pragma once

#include "Tile.h"
#include "Background.h"
#include "Shape.h"
#include "ofMain.h"

class ofApp : public ofBaseApp {

	// Enum to represent the current state of the game
	enum GameState {
		IN_PROGRESS = 0,
		PAUSED,
		BEGIN,
		FINISHED
	};

private:
	GameState current_state_ = BEGIN;
	int const columns = 10;
	int const rows = 15;
	Background background;
	Shape default_shape_;
	bool should_generate_shape = true;
	std::vector < std::vector<Tile>> random_shape;
	int x_change = 0;
	int y_change = Tile::height;
	int frame_rate = 3;
	int rotation_case = 0;
	std::vector<int> high_score;
	int current_score = 0;
	ofSoundPlayer my_sound;

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void DrawBegin();
	void DrawFinished();
	void DrawPaused();
	void DrawScore();
	bool IsAtBottom();						//Checks if the Shape is at the Bottom
	void SetBlockBottom();				//Sets Block and goes next
	bool IsAtEdge();						//Checks if the block is at the edge
	bool CollideWithBlock();				//Checks if the Block touches another
	void SetBlock();			//Sets block and goes to the next
	void Rotate();
	bool CheckXNegative();					//Checks if Rotate goes into the negative x axis.
	bool CheckXOver();						//Checks if Rotate goes out of bounds.
	int CheckLine();						//Checks if there is a full row.
	bool IsOver();							//Checks if we lost
	void NewGame();							//Resets
};
