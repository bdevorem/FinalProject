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
	int getX(); //returns x position
	int getY();//returns y
	void setX(int); //sets x
	int dead(); //returns alive variable
	void damage(); //applies damage to turtle
	bool isHitLeft(int, int); //clearly checks if it is hit on the left side
	bool isHitRight(int, int); //samzies
	void setMoveVar(int); //sets the move variable, shocker
	bool makeNewTurtle(); //what does this do
	void setNewTurtle(bool); //changes the variable
	int getMoveVar();
	void setPushed(bool); //pushed variable for shelled turtles

private:
	int x;
	int y;
	int width;
	int height;
	int alive; //2 = alive, 1 = in shell, 0 = dead
	int counter;
	int moveVar;
	bool newTurtle;
	bool pushed;



};
#endif
Turtle::Turtle() : Enemy() {

	srand(time(NULL)); //seed time

	x = 576;
	y = 302;
	width = height = 24;
	counter = 0;
	moveVar = 1;
	newTurtle = false;
	alive = 2;
	pushed = false;
} 

void Turtle::moveTurtle() { //moves enemy
	counter++;

	if(alive == 2 || pushed == true)  { //if turtle is completely alive or pushed
		if(moveVar == 1){
			if(counter%5 == 0)//same speed as goomba
				x -= 1;
		}
		else if(moveVar == -1)  { //if the turtle is moving right-wards
			if(counter%5 == 0)
				x += 1;
		}
	}
}

bool Turtle::isOn(int xpos, int ypos) {
	if(ypos == y) //check if the entered points are on top of turtle
		if( xpos >= x && xpos <= x+width)
			return true;

	return false;
}

int Turtle::getX() { //these are pretty clear
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

bool Turtle::isHitLeft(int Xpos, int Ypos) { //checks if the entered points are on the left edge of the turtle
	if(Xpos == x)
		if(Ypos >= y && Ypos <= y+height)
			return true;
	return false;
}

bool Turtle::isHitRight(int Xpos, int Ypos) { //same, for right side
	if(Xpos == x + width)
		if(Ypos >= y && Ypos <= y+height)
			return true;
	return false;
}

void Turtle::setMoveVar(int i){ //sets the move variable
	moveVar = i;
}

bool Turtle::makeNewTurtle(){
	/*
	this is Breanna's awesome weird yet incredibly beautiful function that randomly makes new turtles. First, a random number
	all the way to ONE MILLION is generated. Then, with an incredibly painful yet excrutiatingly satisfying testing process, I check
	if the number is greater than the magic number 999 thousand, three hundred. If so, then a new turtle will be created after a 
 	perfect amount of wait time... unless it overlaps with the previous monsters.
	*/
	int temp = rand()%1000000;	

	if(temp > 999300) //less turtles than goombas
		return true;
	else
		return false;
}

void Turtle::setNewTurtle(bool a){ //this.is.clear
	newTurtle = a;
}

int Turtle::getMoveVar() {
	return moveVar;
}

void Turtle::setPushed(bool a){
	pushed = a;
}





