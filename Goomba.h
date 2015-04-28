//Goomba.h
//goomba class inherited from enemy class

#include "Enemy.h"
#include <SDL2/SDL.h>
#ifndef GOOMBA_H
#define GOOMBA_H

class Goomba: public Enemy {
	public:
		Goomba(); //default constructor w/ x and y position
		void moveGoomba(); //moves enemy
		bool isOn(int, int); //if mario is on goomba
		int getX();
		int getY();
		void setX(int);
		bool dead();
		void setAlive();
		void displayLives();
		bool isHitLeft(int, int);
		bool isHitRight(int, int);
		void setMoveVar(int);
		
	private:
		int x;
		int y;
		int width;
		int height;
		bool alive = true;
		int counter;
		int moveVar;
		
		
};
#endif

Goomba::Goomba() : Enemy() {
	x = 576;
	y = 295;
	width = height = 24;
	counter = 0;
	moveVar = 1;
} 

void Goomba::moveGoomba() { //moves enemy

	if(moveVar == 1){
		counter++; //goomba is SUPER fast, so fix this without making coordinates floats
	
		if(counter%5 == 0)
			x -= 1;
	}
}

bool Goomba::isOn(int xpos, int ypos) {

	if(ypos == y)
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

bool Goomba::dead(){
	return !alive;

}

void Goomba::setX(int a){
	x = a;


}

void Goomba::setAlive(){
	alive = false;

}

void Goomba::displayLives(){
	/////////////////////////////add stuff//////////////////

}

bool Goomba::isHitLeft(int Xpos, int Ypos)  {

	if(Xpos == x)
		if(Ypos >= y && Ypos <= y+height)
			return true;

	return false;

}

bool Goomba::isHitRight(int Xpos, int Ypos)  {

	if(Xpos == x + width)
		if(Ypos >= y && Ypos <= y+height)
			return true;

	return false;

}

void Goomba::setMoveVar(int i){
	moveVar = i;
}















