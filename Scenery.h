//Scenery.h
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#ifndef SCENERY_H
#define SCENERY_H

class Scenery {
public:
	Scenery();
	int getX();
	int getY();
	void setX(int);
	int getWidth();
	int getHeight();

private:
	int x;
	int y;
	int width;
	int height;
};

#endif

Scenery::Scenery() {
	x = 0;
	y = 25;
	width = 196;
	height = 149;
}

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
