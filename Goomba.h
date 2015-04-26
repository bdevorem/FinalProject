//Goomba.h
//nicholascjones

//goomba class inherited from enemy class

#include "Enemy.h"
#ifndef GOOMBA_H
#define GOOMBA_H

class Goomba: public Enemy {
	public:
		Goomba(int, int); //default constructor w/ x and y position
		die(); //dead function
		int DeadState(); //determines dead state based on damage
		void moveEnemy(); //moves enemy
		void display(); //displays Goomba
}
#endif

Goomba::Goomba(int x, int y) : Enemy(x, y) {
	damage(); //sets goomba's default hp to 1 rather than 2
} //end constructor

void Goomba::moveEnemy() { //moves enemy
} //fix this
	
		
		

