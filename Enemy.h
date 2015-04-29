
#include <SDL2/SDL.h>

#ifndef ENEMY_H
#define ENEMY_H
class Enemy  {

  public:
  	Enemy(); // non-default constructor used because all enemies will be initialized from the same spot on the screen (right)

  protected:
  	 int xpos; 
 	 int ypos;
	
};


Enemy::Enemy() { //default constructor for enemy class
	xpos = 576;
	ypos = 295;
}
#endif

