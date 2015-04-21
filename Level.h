//Level.h
//12 4 2015

#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
using namespace std;

class Level {
	public:
		Level();
		//void EndofLevel();
		void blocks();
		
	protected:
		bool endLevel;
};
#endif

Level::Level() {
	endLevel = false;

}

void Level::Blocks() {

}
