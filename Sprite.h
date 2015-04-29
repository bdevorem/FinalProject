//Sprite.h
//nicholascjones
//Creates sprite class for character in Mario game that can perform as a character inthe game given controls


#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "mainFunctions.h"
#include <sstream>
#include <string>
using namespace std;

#ifndef SPRITE_H
#define SPRITE_H

class Sprite{ 

public:
	Sprite(); //default constructor
	int move(); //moves character based on user input
	int jump(); //allows character to jump based on user input in a loop
	void grow(); //grows mario when he gets mushroom
	void shrink(); //shrinks mario when he takes damage
	int getX(); //gives x positon of sprite
	int getY(); //gives y position of sprite
	void damage(); //mario takes damage based on enemy
	void die(); //mario dies if taking damage
	void jumpUp(); //jumping from stationary position upwards
	void jumpDown(); //jumping from stationary position downward
	int inAir();
	int posX(); //returns the current x position of the sprite
	void setX(int); // sets mario's x position on the screen
	void setY(int);
	int posY(); //returns the current y position of the sprite
	void setDirection(int);  // sets the moving up direction
	int getDirection();   // returns the moving up direction
	SDL_Rect getHeroRect();  // get and set the rect for mario
	SDL_Rect getHeroSrcRect();
	void setMoveVar(int);  // get and set the variable used to determine the direction mario is moving
	int getMoveVar();
	void resetJumpCounter();  // resets the counter used to see how long Mario has been moving up
	bool getAliveStatus();  // returns whether Mario has kicked the bucket yet 
	bool isBig();


private:
	int moveVar;  // holds the direction mario should be moving
	int jumpCounter;  // lets the program know how long mario has been jumping
	int x; //x position of sprite
	int y; //y position of sprite
	bool large; //T if mushroom, F if not
	bool alive; //T if alive, F if false
	int xRadius; //damage radius in x dimension of mario
	int yRadius; //damage radius in y dimension of mario
	int direction; //1 means going up, -1 means going down, 0 means not falling or jumping
	SDL_Rect heroRect;   // rects for displaying mario
	SDL_Rect heroSrcRect;



}; //end class definition
#endif


Sprite::Sprite() { //default constructor
	alive = true;
	large = false;
	moveVar = 0;
	x = 0;
	y = 295;
	jumpCounter = 0;

	heroRect.x = 0;
	heroRect.y = 295;

	heroSrcRect.x = 0;
	heroSrcRect.y = 0;
	heroSrcRect.h = 32;
	heroSrcRect.w = 24;

	direction = 0;

} //end



int Sprite::jump() { //jump function


	if(direction == 1)  {
		jumpUp();
		jumpCounter++;  }
	if(direction == -1)  {  // moves mario laterally depending on the direction variable
		jumpDown();
		jumpCounter = 0;  }
	if(jumpCounter >= 150) {  // makes mario start to fall if he has been jumping for 150 cycles
		setDirection(-1);
	}
	if(posY() > 295) {  // makes sure Mario lands fluch with the ground
		setY(295);
		setDirection(0);
	}

	heroRect.y = posY();
	if(posY() < 295 && direction == 0) // for falling off of blocks
		setDirection(-1);

}		

int Sprite::move() { //move function

	if(moveVar == 1)  {
		if(heroRect.x > 0) {  // won't let mario go backwards off the map
			heroRect.x -= 1;
		}
	}
	else if(moveVar == -1)  {  // moving forwards
		heroRect.x += 1;
	}
}

void Sprite::grow() { //mario becomes large in case of getting a mushroom
	large = true; //sets large value to true, changes animation
	//animation?
}

void Sprite::shrink() { //mario becomes small in case of getting a mushroom
	large = false; //sets large value to false, changes animation
}

void Sprite::damage() { //mario can take damage from enemy based on a position check given in main
	if (large == true) { //tests if mario is large and can take damage
		shrink(); //makes mario small
	} else { //if mario is small
		die(); //mario dies
	}
} //end function execution

void Sprite::die() { //mario dies
	alive = false; //sets alive value to false, killing him
} //end function

int Sprite::getX() { //gives mario's x coordinate
	return heroRect.x;
}

void Sprite::setX(int a)  {  // sets mario's x coordinate
	heroRect.x = a;
}

int Sprite::getY() { //gives mario's y coordinate
	return y;
}

int Sprite::inAir() {
	if (direction != 0) //if the sprite is not on the ground or block, it must be in the air
		return 1;
	else
		return 0;
}

void Sprite::jumpUp() {  // used each cycle with jump
	y = y - 1;
}

void Sprite::jumpDown() { // look up a few lines
	y = y + 1;
}

int Sprite::posX() {  // repeat functions made in group confusion and git hub failure
	return x;
}

int Sprite::posY() {
	return y;
}

void Sprite::setY(int a) {  ///////// more set and get functions that are necessary and satisfying  ////////
	y = a;
	heroRect.y = a;
}

void Sprite::setDirection(int a) {
	direction = a;
}

int Sprite::getDirection() {
	return direction;
}


SDL_Rect Sprite::getHeroRect()  {
	return(heroRect);
}

SDL_Rect Sprite::getHeroSrcRect()  {
	return(heroSrcRect);
}

void Sprite::setMoveVar(int a)  {
	moveVar = a;
}

int Sprite::getMoveVar()  {
	return moveVar;
}

void Sprite::resetJumpCounter()  {
	jumpCounter = 0;
}

bool Sprite::getAliveStatus()  {
	return alive;
}

bool Sprite::isBig() {
	return large;
}
