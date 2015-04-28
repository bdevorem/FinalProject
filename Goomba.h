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
		
	private:
		SDL_Rect goombaRect;
		SDL_Rect goombaSrcRect;
		int x;
		int y;
		int width;
		
		
}
#endif

Goomba::Goomba() : Enemy() {
	x = 576;
	y = 295;
	width = 24;

} 

void Goomba::moveEnemy() { //moves enemy

	goombaRect.x -= 1;

}

bool Goomba::isOn(int xpos, int ypos) {

	if(ypos == y)
		if( xpos >= x && xpos <= x+width)
			return true;
			
	return false;
}




















