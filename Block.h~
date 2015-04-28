//Block.h
//nicholascjones

#include <SDL2/SDL.h>

#ifndef BLOCK_H
#define BLOCK_H

class Block {

	public:
		Block(int = 0, int = 0); //non-default constructor
		bool isHit(int, int);
		void setXpos(int);
		int getXpos();
		int getYpos();
		int getWidth();
		int getHeight();
		void setYpos(int);
		bool isOn(int, int);
		bool isHitLeft(int, int);
		bool isHitRight(int, int);

	private:
		int Xpos;
		int Ypos;
		int width;
		int height;
};
#endif

Block::Block(int x, int y)  {

	Xpos = x;
	Ypos = y;
	width = 20;
	height = 20;

}

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

bool Block::isHit(int marioX, int marioY)  {

	if(marioY == Ypos+height)
		if(marioX >= Xpos && marioX <= Xpos+width)
			return(1);

	return(0);
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
