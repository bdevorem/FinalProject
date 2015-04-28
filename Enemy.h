// This is a tentative sketch for the abstract enemy class.
#include "Sprite.h"

#ifndef ENEMY_H
#define ENEMY_H
class Enemy  {

  public:
  	Enemy(int,int); // non-default constructor used because all enemies will be initialized from the same spot on the screen
	void touch(Sprite); //determines if touching in any capacity
    	virtual void moveEnemy() = 0;  // will describe the motion of each of the enemies in derived classes
    	virtual int DeadState() = 0;  // will be used to determine if the enemy is dead and should leave the screen or is in another state
	void kill(); //kills enemy
	virtual void display() = 0; //pure virtual function to draw enemy
	void checkDamage(); //checks whether damage is done
	void damage(); //subtracts 1 from enemy's hp
	void checkAlive(); //checks whether or not enemy is alive

  protected:
    	int xpos;  // private data members for storing the location of the enemy
   	int ypos;
	bool alive;
	bool touchTop;
	bool touchSide;
	int hp;
    
}
#endif

Enemy::Enemy(int x, int y) { //default constructor for enemy class
	xpos = x;
	ypos = y;
	alive = true;
	touchTop = false;
	touchSide = false;
	hp = 2;
}
	

void Enemy::touch(Sprite mario) { //if sprite is touching top of enemy
	mx = Sprite::mario.getX(); //get x coordinate of sprite
	my = Sprite::mario.getY(); //get y coordinate of sprite
	if ((xpos > mx-5) && (xpos < mx+5)) { //if within 5 horizontal pixels
		if (my < (ypos + 5)) { //if touching top of enemy
			touchTop = true;
		} else {
			touchSide = true;
		}
	}
}

void Enemy::damage() {
	hp -= 1; //lowers HP by one
}

void Enemy::checkDamage() { //checks for damage given position
	if (touchTop == true) damage();
}
			
void Enemy::checkAlive() { //checks if enemy is alive
	if (hp == 0) {
		alive = false;
	}
}		
	
void Enemy::kill() { //actions when alive is set to false
	//DISPLAY DEATH SPRITE AT CURRENT POSITION
	xpos = 0; //x and y position set to (0,0)
	ypos = 0;	//to prevent any conflict
}
