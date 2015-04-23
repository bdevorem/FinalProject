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
	void display(); //displays on screen based on outputs
	int move(char); //moves character based on user input
	int jump(); //allows character to jump based on user input in a loop
	void grow(); //grows mario when he gets mushroom
	void shrink(); //shrinks mario when he takes damage
	int getX(); //gives x positon of sprite
	int getY(); //gives y position of sprite
	int getXradius(); //gives x damage radius of sprite
	int getYradius(); //gives y damage radius of sprite
	void damage(); //mario takes damage based on enemy
	void die(); //mario dies if taking damage
	void jumpUp(); //jumping from stationary position upwards
	void jumpDown(); //jumping from stationary position downward
	int inAir();
	int posX(); //returns the current x position of the sprite
	int posY(); //returns the current y position of the sprite
	void setY(int);
	void resetTimer(); //resets the air timer
	void setDirection(int);
	int getDirection();
	Uint32 getTime();
	SDL_Rect getHeroRect();
	SDL_Rect getHeroSrcRect();
	SDL_Rect getJumpRect();
	SDL_Rect getJumpSrcRect();
	SDL_Rect getWalkRect();
	SDL_Rect getWalkSrcRect();
	SDL_Rect getSrcRect();
	SDL_Rect getDstRect();

private:
	int x; //x position of sprite
	int y; //y position of sprite
	bool large; //T if mushroom, F if not
	bool alive; //T if alive, F if false
	int xRadius; //damage radius in x dimension of mario
	int yRadius; //damage radius in y dimension of mario
	//int inAir; //determines if the character is in the air
	Uint32 startTime = 0;
	int direction; //1 means going up, 0 means going down
	SDL_Rect heroRect;
	SDL_Rect heroSrcRect;
	SDL_Rect jumpRect;
	SDL_Rect jumpSrcRect;
	SDL_Rect walkRect;
	SDL_Rect walkSrcRect;
	SDL_Rect srcRect;
	SDL_Rect dstRect;


}; //end class definition
#endif


Sprite::Sprite() { //default constructor
	bool alive = true;
	bool large = false;
	x = 100;
	y = 295;

	heroRect.x = 100;
	heroRect.y = 295;

	heroSrcRect.x = 0;
	heroSrcRect.y = 0;
	heroSrcRect.h = 32;
	heroSrcRect.w = 24;

	jumpRect.x = 0;
	jumpRect.y = 0;

	jumpSrcRect.x = 0;
	jumpSrcRect.y = 0;
	jumpSrcRect.h = 32;
	jumpSrcRect.w = 32;

	walkRect.x = 0;
	walkRect.y = 0;

	walkSrcRect.x = 0;
	walkSrcRect.y = 0;
	walkSrcRect.h = 30;
	walkSrcRect.w = 26;

	srcRect.x = 100;
	srcRect.y = 100;
	srcRect.h = 385;
	srcRect.w = 600;

	dstRect.x = 100;
	dstRect.y = 100;
	dstRect.h = 1000;
	dstRect.w = 1000;

} //end



int Sprite::jump() { //jump function

	if (inAir() == 0){
		jumpUp();
		setDirection(1);
	}

	SDL_Event e;//Event handler

		resetTimer();
		while (inAir() == 1) {
			if(e.type == SDL_KEYDOWN)  {
				if(e.key.keysym.sym == SDLK_LEFT){
					move('l');  }
				if(e.key.keysym.sym == SDLK_RIGHT){
					//user moves right
					move('r');
				}
			}
			if (((SDL_GetTicks() - getTime()) > 110) && getDirection() == 1) {
				jumpUp();
				heroRect.y = NULL;
				jumpRect.y = posY();
				jumpRect.x = heroRect.x;
				SDL_FillRect(gScreenSurface,NULL,0x000000);
				SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image
				SDL_BlitSurface( jumpImage, &jumpSrcRect, gScreenSurface, &jumpRect );
				SDL_UpdateWindowSurface( gWindow );//Update the surface
				resetTimer();
			} else if (((SDL_GetTicks() - getTime()) > 110) && getDirection() == 0) {
				jumpDown();
				heroRect.y = NULL;
				jumpRect.y = posY();
				jumpRect.x = heroRect.x;
				SDL_FillRect(gScreenSurface,NULL,0x000000);
				SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image
				SDL_BlitSurface( jumpImage, &jumpSrcRect, gScreenSurface, &jumpRect );
				SDL_UpdateWindowSurface( gWindow );//Update the surface
				resetTimer();
			}
			if (posY() <= 195) {
				setDirection(0);
			}
			if (posY() > 295)
				setY(295);
		}
	heroRect.y = 295;
					
}		

int Sprite::move(char c) { //move function

	if(c == 'l')  {
		if(heroRect.x > 100) {

			heroRect.x -= 3;
			jumpRect.x -= 3;
		}
			SDL_FillRect(gScreenSurface,NULL,0x000000);
	}
        else if(c == 'r')  {
		if(heroRect.x < 600) {
			walkRect.x = heroRect.x;
			walkRect.y = heroRect.y;
			heroRect.y = NULL;
			SDL_FillRect(gScreenSurface,NULL,0x000000);
			SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image
			SDL_BlitSurface( walkImage, &walkSrcRect, gScreenSurface, &walkRect );
			SDL_UpdateWindowSurface( gWindow );//Update the surface*/
			heroRect.x += 3;
			heroRect.y = walkRect.y;
			walkRect.x = NULL;
		}
		SDL_FillRect(gScreenSurface,NULL,0x000000);
	}
}

void Sprite::display() { //displays Sprite
	jumpImage == NULL;
	SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image	
	SDL_BlitSurface( heroImage, &heroSrcRect, gScreenSurface, &heroRect );
	SDL_UpdateWindowSurface( gWindow );//Update the surface
}


void Sprite::grow() { //mario becomes large in case of getting a mushroom
	large = true; //sets large value to true, changes animation
	//animation?
}

void Sprite::shrink() { //mario becomes small in case of getting a mushroom
	large = false; //sets large value to false, changes animation
	//animation?
}

void Sprite::damage() { //mario can take damage from enemy based on a position check given in main
	if (large = true) { //tests if mario is large and can take damage
		shrink(); //makes mario small
	} else { //if mario is small
		die(); //mario dies
	}
} //end function execution

void Sprite::die() { //mario dies
	alive = false; //sets alive value to false, killing him
	//animation;
} //end function

int Sprite::getX() { //gives mario's x coordinate
	return x;
}

int Sprite::getY() { //gives mario's y coordinate
	return y;
}

int Sprite::getXradius() { //returns the damage radius of mario in the x direction
	return xRadius;
}

int Sprite::getYradius() { //returns the damage radius of mario in the y direction
	return yRadius;
}

int Sprite::inAir() {
	if (y < 295) //if the sprite is not on the ground, it must be in the air
		return 1;
	else
		return 0;
}

void Sprite::resetTimer() {
	startTime = SDL_GetTicks(); //reset the air timer
}

void Sprite::jumpUp() {
	y = y - 10;
}

void Sprite::jumpDown() {
	y = y + 10;
}

int Sprite::posX() {
	return x;
}

int Sprite::posY() {
	return y;
}

void Sprite::setY(int a) {
	y = a;
}

void Sprite::setDirection(int a) {
	direction = a;
}

int Sprite::getDirection() {
	return direction;
}

Uint32 Sprite::getTime() {
	return startTime;
}

SDL_Rect Sprite::getHeroRect()  {
	return(heroRect);
}

SDL_Rect Sprite::getHeroSrcRect()  {
	return(heroSrcRect);
}

SDL_Rect Sprite::getJumpRect()  {
	return jumpRect;
}

SDL_Rect Sprite::getJumpSrcRect()  {
	return jumpSrcRect;
}

SDL_Rect Sprite::getWalkRect()  {
	return walkRect;
}

SDL_Rect Sprite::getWalkSrcRect()  {
	return walkSrcRect;
}

SDL_Rect Sprite::getSrcRect()  {
	return srcRect;
}

SDL_Rect Sprite::getDstRect()  {
	return dstRect;
}


