//Turtle.h
//nicholascjones

//turtle class inherited from enemy class

#include "Enemy.h"
#ifndef TURTLE_H
#define TURTLE_H

class Turtle: public Enemy {
	public:
		Turtle(int, int); //default constructor w/ x and y position
		void die(); //dead function
		int DeadState(); //determines dead state based on damage
		void moveEnemy(); //moves enemy
		void checkMoving(); //checks if turtle is able to move, in state
	private:
		bool moving; //whether it is in a moving state or not
}
#endif

Turtle::Turtle(int x, int y) : Enemy(x, y) {
	moving = true;
} //end constructor

void Turtle::checkMoving() { //checks if turtle is moving
	int hp = getHP();
	if (hp < 2) moving = false;
}
	

void Turtle::moveEnemy() {
	if (moving == true) {
	} //figure out
}	



