//Turtle.h

//turtle class inherited from enemy class

#include "Enemy.h"
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <time.h>
#ifndef Turtle_H
#define Turtle_H
class Turtle: public Enemy {

	public:
		Turtle(); //default constructor w/ x and y position
		void moveTurtle(); //moves enemy
		bool isOn(int, int); //if mario is on Turtle
		int getX();
		int getY();
		void setX(int);
		int dead();
		void damage();
		void displayLives();
		bool isHitLeft(int, int);
		bool isHitRight(int, int);
		void setMoveVar(int);
		bool makeNewTurtle();
		void setNewTurtle(bool);
		int getMoveVar();		

	private:
		int x;
		int y;
		int width;
		int height;
		int alive; //2 = alive, 1 = in shell, 0 = dead
		int counter;
		int moveVar;
		bool newTurtle;
		
		

};
#endif
Turtle::Turtle() : Enemy() {

	srand(time(NULL));
	
	x = 576;
	y = 302;
	width = height = 24;
	counter = 0;
	moveVar = 1;
	newTurtle = false;
	alive = 2;
} 

void Turtle::moveTurtle() { //moves enemy
	counter++;

	if(alive == 2)  {
		if(moveVar == 1){
			if(counter%5 == 0)//same speed as goomba
				x -= 1;
		}
		else if(moveVar == -1)  {
			if(counter%5 == 0)
				x += 1;
		}
	}
}

bool Turtle::isOn(int xpos, int ypos) {
	if(ypos == y)
		if( xpos >= x && xpos <= x+width)
			return true;
			
	return false;
}

int Turtle::getX() { 
	return x;
}

int Turtle::getY() { 
	return y;
}

int Turtle::dead(){
	//2 = alive, 1 = in shell, 0 = dead

	return alive;
}

void Turtle::setX(int a){
	x = a;
}

void Turtle::damage(){
	if(alive != 0) alive--; //decrease alive level by one
}

void Turtle::displayLives(){

	/////////////////////////////add stuff//////////////////

}

bool Turtle::isHitLeft(int Xpos, int Ypos) {
	if(Xpos == x)
		if(Ypos >= y && Ypos <= y+height)
			return true;
	return false;
}

bool Turtle::isHitRight(int Xpos, int Ypos) {
	if(Xpos == x + width)
		if(Ypos >= y && Ypos <= y+height)
			return true;
	return false;
}

void Turtle::setMoveVar(int i){
	moveVar = i;
}

bool Turtle::makeNewTurtle(){
	int temp = rand()%1000000;	
	
	if(temp > 999500) //less turtles than goombas
		return true;
	else
		return false;
}

void Turtle::setNewTurtle(bool a){

	newTurtle = a;
}

int Turtle::getMoveVar() {
	return moveVar;
}





