//Goomba.h
//nicholascjones

//goomba class inherited from enemy class

#include "Enemy.h"
#ifndef GOOMBA_H
#define GOOMBA_H

class Goomba: public Enemy {
	public:
		Goomba(int, int); //default constructor w/ x and y position
		void die(); //dead function
		void moveEnemy(); //moves enemy
}
#endif

Goomba::Goomba(int x, int y) : Enemy(x, y) {
	damage(); //sets goomba's default hp to 1 rather than 2
} //end constructor

void Goomba::moveEnemy() { //moves enemy

} //fix this

void Goomba::display() { //displays goomba


} //figure this out

void Goomba::die() { 


} //figure this out
		
		
		

