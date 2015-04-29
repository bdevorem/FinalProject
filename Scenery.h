//Scenery.h
//Thanks for those dope clouds Riley
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#ifndef SCENERY_H
#define SCENERY_H

class Scenery {
public:
	///////Prototypes for functions///////

	Scenery(); //default constructor
	int getX();
	int getY();
	void setX(int);
	int getWidth();
	int getHeight();

private:
	/////Variables for Scenery declared//////
	int x;
	int y;
	int width;
	int height;
};

#endif

Scenery::Scenery() { //Default constructor, set intial position for clouds and the dimensions of the cloud image
	x = 0;
	y = 25;
	width = 196;
	height = 149;
}

////////Get and set functions simply return a variable or set the variable///////////////

void Scenery::setX(int a) {
	x = a;
}

int Scenery::getX() {
	return x;
}

int Scenery::getY() {
	return y;
}

int Scenery::getWidth() {
	return width;
}

int Scenery::getHeight() {
	return height;
}
