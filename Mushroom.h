//Mushroom.h
//nicholascjones

#include <SDL2/SDL.h>

#ifndef MUSHROOM_H
#define MUSHROOM_H

class Mushroom {
	
	public:
		Mushroom();
		bool isTouch(int, int);
		void setX(int);
		void setY(int);
		int getX();
		int getY();
		int getWidth();
		int getHeight();

	private:
		int X;
		int Y;
		int width;
		int height;

};

#endif

Mushroom::Mushroom()  {
	width = height = 20;
	X = 0;
	Y = 0;
}

bool Mushroom::isTouch(int Xpos, int Ypos)  {
	if(Y == Ypos+height)
		if(Xpos >= X && Xpos <= X+width)
			return true;

	if(Y == Ypos)
		if(Xpos >= X && Xpos <= X+width)
			return true;

	if(X == Xpos)
		if(Ypos >= Y && Ypos <= Y+height)
			return true;

	if(X == Xpos + width)
		if(Ypos >= Y && Ypos <= Y+height)
			return true;

	return false;
}

void Mushroom::setX(int a)  {
	X = a;
}

void Mushroom::setY(int a)  {
	Y = a;
}

int Mushroom::getX()  {
	return(X);
}

int Mushroom::getY()  {
	return(Y);
}

int Mushroom::getWidth()  {
	return(width);
}

int Mushroom::getHeight()  {
	return(height);
}
