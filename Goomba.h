//Goomba.h
//goomba class inherited from enemy class
#include "Enemy.h"
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#ifndef GOOMBA_H
#define GOOMBA_H
class Goomba {

	public:
		Goomba(); //default constructor w/ x and y position
		void moveGoomba(); //moves enemy
		bool isOn(int, int); //if mario is on goomba
		int getX(); //returns x
		int getY(); //same
		void setX(int);
		bool dead(); //returns alive variable
		void setAlive();
		bool isHitLeft(int, int); //checks if it is hit on the left
		bool isHitRight(int, int); //on the right
		void setMoveVar(int);
		bool makeNewGoomba(); //make a new goomba
		void setNewGoomba(bool); //set the variable
		int getMoveVar();		

	private:
		int x;
		int y;
		int width;
		int height;
		bool alive = true;
		int counter;
		int moveVar;
		bool newGoomba;
	
};
#endif
Goomba::Goomba() {

	srand(time(NULL)); //seed time
	
	x = 576;
	y = 302;
	width = height = 24;
	counter = 0;
	moveVar = 1;
	newGoomba = false;
} 

void Goomba::moveGoomba() { //moves enemy

		counter++; //goomba is SUPER fast, so fix this without making coordinates floats

	if(moveVar == 1){
		//counter++; //goomba is SUPER fast, so fix this without making coordinates floats
		if(counter%5 == 0)
			x -= 1;
	}
	else if(moveVar == -1)  {
		if(counter%5 == 0)
			x += 1;
	}
}

bool Goomba::isOn(int xpos, int ypos) {

	if(ypos == y) //if the entered coords are on top of goomba
		if( xpos >= x && xpos <= x+width)
			return true;
	return false;
}

int Goomba::getX() { //gives mario's x coordinate
	return x;
}

int Goomba::getY() { //gives mario's y coordinate
	return y;
}

bool Goomba::dead(){ //return opposite of alive
	return !alive;
}

void Goomba::setX(int a){
	x = a;
}

void Goomba::setAlive(){
	alive = false;
}

bool Goomba::isHitLeft(int Xpos, int Ypos) { //these are the same as in the turtle

	if(Xpos == x)
		if(Ypos >= y && Ypos <= y+height)
			return true;
	return false;
}

bool Goomba::isHitRight(int Xpos, int Ypos) {

	if(Xpos == x + width)
		if(Ypos >= y && Ypos <= y+height)
			return true;
	return false;
}

void Goomba::setMoveVar(int i){
	moveVar = i;
}

bool Goomba::makeNewGoomba(){
	/*
	If you are looking at this function before the similar one in Turtle, please view that first to enjoy Breanna's long speech
	that was a product of 10 shots of espresso, lack of precious sleep, and hysterical laughing from how far this project has gotten.
	*/

	int temp = rand()%1000000;	
	
	if(temp > 999300)
		return true;
	else
		return false;
}

void Goomba::setNewGoomba(bool a){
	newGoomba = a;
}

int Goomba::getMoveVar() {
	return moveVar;
}

