//Sprite.h
//nicholascjones
//Creates sprite class for character in Mario game that can perform as a character inthe game given controls


#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "mainFunctions.h"
//#include "Level.h"    ***not needed yet
using namespace std;

#ifndef SPRITE_H
#define SPRITE_H

class Sprite() { //fix to be derived class of level

	public:
		Sprite(); //default constructor
		int move(char c); //moves character based on user input
		int jump(); //allows character to jump based on user input in a loop
		void grow(); //grows mario when he gets mushroom
		void shrink(); //shrinks mario when he takes damage
		int getX(); //gives x positon of sprite
		int getY(); //gives y position of sprite
		void damage(int, int); //mario takes damage based on enemy
		void die(); //mario dies if taking damage

	private:
		int x; //x position of sprite
		int y; //y position of sprite
		bool large; //T if mushroom, F if not
		bool alive; //T if alive, F if false
		

}; //end class definition
#endif

Sprite::Sprite() { //default constructor
	
