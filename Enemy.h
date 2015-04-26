// This is a tentative sketch for the abstract enemy class.
#include "Sprite.h"

#ifndef ENEMY_H
#define ENEMY_H
class Enemy  {

  public:
  	Enemy(int,int); // non-default constructor used because all enemies will be initialized from the same spot on the screen
	void touch(); //determines if touching in any capacity
  	bool getTouchTop()// will return a true value when the player hits the top of the enemy
    	bool getTouchSide(); // wil return a true value when any object or the player touches the enemy on either side
    	virtual void moveEnemy() = 0;  // will describe the motion of each of the enemies in derived classes
    	virtual int DeadState() = 0;  // will be used to determine if the enemy is dead and should leave the screen or is in another state	
	virtual void display() = 0; //pure virtual function to draw enemy
	int getxp(); //gets xposition
	int getyp(); //gets y position
  private:
    	int xpos;  // private data members for storing the location of the enemy
   	int ypos;
	bool alive;
	bool touchTop;
	bool touchSide;
    
}
#endif

Enemy::Enemy(int x, int y) { //default constructor for enemy class
	xpos = x;
	ypos = y;
	bool alive = true;
	bool touchTop = false;
	bool touchSide = false;
}
	
/*
void Enemy::touch() { //if sprite is touching top of enemy
	mx = Sprite::getX(); //get x coordinate of sprite
	my = Sprite::getY(); //get y coordinate of sprite
	if ((xpos > mx-5) && (xpos < mx+5)) { //if within 5 horizontal pixels
		if (my < (ypos + 5)) { //if touching top of enemy
			touchTop = true;
		} else {
			touchSide = true;
		}
	}
}
*/
int getxp() { //gets x position
	return xpos;
}

int getyp() { //gets y position
	return ypos;
}

bool Enemy::getTouchSide() { //if sprite is touching side of enemy
	return touchSide;
}

bool Enemy::getTouchTop() { //if sprite is touching top of enemy
	return touchTop;
}
			
			
		 
	

	
