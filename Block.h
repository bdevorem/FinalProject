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
		void setYpos(int);
		bool isOn(int, int);

	private:
		SDL_Rect blockRect;
		SDL_Rect blockSrcRect;
		int Xpos;
		int Ypos;
		int width;
		int height;
};
#endif

Block::Block(int x, int y)  {

	blockRect.x = x;
	blockRect.y = y;
	blockSrcRect.w = 20;
	blockSrcRect.h = 20;

	Xpos = x;
	Ypos = y;
	width = 20;
	height = 20;

}

void Block::setXpos(int a)  {
	Xpos = a;
}

void Block::setYpos(int a)  {
	Ypos = a;
}

bool Block::isHit(int marioX, int marioY)  {

	if(marioY == Ypos)
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
