//Mushroom.h
//Tally

#include <SDL2/SDL.h>

#ifndef MUSHROOM_H
#define MUSHROOM_H

class Mushroom {
	
	public:
		Mushroom();  // default constructor
		bool isTouch(int, int);  // if its being touched
		void setX(int);  // love those get and set
		void setY(int);
		int getX();
		int getY();
		int getWidth();
		int getHeight();

	private:
		int X;
		int Y;     // coordinates of location
		int width; // size of shroom
		int height;

};

#endif

Mushroom::Mushroom()  {
	width = height = 20;
	X = 0;
	Y = 0;
}

bool Mushroom::isTouch(int Xpos, int Ypos)  {
	if(Y == Ypos+height)                    // if it is touched on bottom
		if(Xpos >= X && Xpos <= X+width)
			return true;

	if(Y == Ypos)                            // touched on top
		if(Xpos >= X && Xpos <= X+width)
			return true;

	if(X == Xpos)                              // touched on left
		if(Ypos >= Y && Ypos <= Y+height)
			return true;

	if(X == Xpos + width)                      // touched by an angel
		if(Ypos >= Y && Ypos <= Y+height)
			return true;

	return false;
}

/////////////      Set AND Get      NUFF SAID   /////////////////////

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
