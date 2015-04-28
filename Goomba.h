//Goomba.h
//goomba class inherited from enemy class

#include "Enemy.h"
#include <SDL2/SDL.h>
#ifndef GOOMBA_H
#define GOOMBA_H

class Goomba: public Enemy {
	public:
		Goomba(); //default constructor w/ x and y position
		void moveEnemy(); //moves enemy
		bool isOn(int, int); //if mario is on goomba
		int getX();
		int getY();
		void setX(int);
		bool dead();
		void setAlive();
		void displayLives();
		bool isHitLeft(int, int);
		bool isHitRight(int, int);
		
	private:
		int x;
		int y;
		int width;
		int height;
		bool alive = true;
		
		
};
#endif

Goomba::Goomba() : Enemy() {
	x = 576;
	y = 295;
	width = height = 24;

} 

void Goomba::moveEnemy() { //moves enemy

	x -= 1;

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
















