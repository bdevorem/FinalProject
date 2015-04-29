//Block.h
//Tallis

#include <SDL2/SDL.h>

#ifndef BLOCK_H
#define BLOCK_H

class Block {

	public:
		Block(int = 0, int = 0); //non-default constructor with fallback values
		bool isHit(int, int); // function used to see if a block is hit from below 
		void setXpos(int);
		int getXpos();
		int getYpos();  // these functions do what you would guess
		int getWidth();
		int getHeight();
		void setYpos(int);
		bool isOn(int, int); // top touch of block
		bool isHitLeft(int, int);  // side touches
		bool isHitRight(int, int);

	private:
		int Xpos;  // coordinates of upper left of block
		int Ypos;
		int width; // size of blocks are all the same
		int height;
};
#endif

Block::Block(int x, int y)  {  // very simple constructor

	Xpos = x;
	Ypos = y;
	width = 20;
	height = 20;

}

// The following are those functions you put into every class you make because you don't want to think about
// the hard stuff, and you know you will need them.

void Block::setXpos(int a)  {
	Xpos = a;
}

int Block::getXpos()  {
	return(Xpos);
}

void Block::setYpos(int a)  {
	Ypos = a;
}

int Block::getYpos()  {
	return(Ypos);
}

int Block::getWidth()  {
	return(width);
}

int Block::getHeight()  {
	return(height);
}

// all of the touch functions for block return bools like every other touch in every other class

bool Block::isHit(int marioX, int marioY)  {

	if(marioY == Ypos+height)
		if(marioX >= Xpos && marioX <= Xpos+width)
			return true;

	return false;
}

bool Block::isOn(int X, int Y)  {

	if(Y == Ypos)
		if(X >= Xpos && X <= Xpos+width)
			return true;

	return false;
}

bool Block::isHitLeft(int X, int Y)  {

	if(X == Xpos)
		if(Y >= Ypos && Y <= Ypos+height)
			return true;

	return false;

}

bool Block::isHitRight(int X, int Y)  {

	if(X == Xpos + width)
		if(Y >= Ypos && Y <= Ypos+height)
			return true;

	return false;

}
