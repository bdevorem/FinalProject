//Sprite.h
//nicholascjones
//Creates sprite class for character in Mario game that can perform as a character inthe game given controls


#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "mainFunctions.h"
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

	private:
		int x; //x position of sprite
		int y; //y position of sprite
		bool large; //T if mushroom, F if not
		bool alive; //T if alive, F if false
		int xRadius; //damage radius in x dimension of mario
		int yRadius; //damage radius in y dimension of mario
		

}; //end class definition
#endif

/*
Sprite::Sprite() { //default constructor
	bool alive = true;
	bool large = false;
} //end



int Sprite::jump() { //jump function
	
int Sprite::move(char c) { //move function

void Sprite::display() { //displays Sprite

*/


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


	

	
