//Level.h
//12 4 2015

#include "Sprite.h"
#include "Block.h"
#include "mainFunctions.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "Goomba.h"
#include "Turtle.h"
#include <unistd.h>

using namespace std;

#ifndef LEVEL_H
#define LEVEL_H

class Level {
	public:
		Level();
		void playLevel();
		void display(); //displays on screen based on outputs
		void checksMario();
		void checksEnemy();
		void scrollScreen();
		
	protected:
		Sprite sp;
		
		int numBlocks;
		Block blk[50];
		SDL_Rect blockRect[50];
		SDL_Rect blockSrcRect[50];
		
		int numGoombas;
		Goomba goomba[500]; //500 is temp max
		SDL_Rect goombaRect[500];
		SDL_Rect goombaSrcRect[500];
		bool newGoomba;
		
		int numTurtles;
		Turtle turtle[500]; //500 is temp max
		SDL_Rect turtleRect[500];
		SDL_Rect turtleSrcRect[500];
		bool newTurtle;
		
		SDL_Rect srcRect;
		SDL_Rect dstRect;
		int mapDistMove;
		
		
};
#endif

Level::Level() {
	mapDistMove = 0;
	numBlocks = 50;
	numGoombas = 2;
	newGoomba = false;
	numTurtles = 2;
	newTurtle = false;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 385;
	srcRect.w = 600;

	dstRect.x = 0;
	dstRect.y = 0;
	dstRect.h = 1000;
	dstRect.w = 1000;

	blk[0].setXpos(100);
	blk[0].setYpos(210);
	blk[1].setXpos(120);
	blk[1].setYpos(210);
	blk[2].setXpos(140);
	blk[2].setYpos(210);
	blk[3].setXpos(160);
	blk[3].setYpos(230);
	blk[4].setXpos(180);
	blk[4].setYpos(230);
	blk[5].setXpos(200);
	blk[5].setYpos(230);
	blk[6].setXpos(220);
	blk[6].setYpos(250);
	blk[7].setXpos(240);
	blk[7].setYpos(250);
	blk[8].setXpos(260);
	blk[8].setYpos(250);

	blk[9].setXpos(700);
	blk[9].setYpos(230);
	blk[10].setXpos(720);
	blk[10].setYpos(230);
	blk[11].setXpos(780);
	blk[11].setYpos(180);
	blk[12].setXpos(800);
	blk[12].setYpos(180);
	blk[13].setXpos(880);
	blk[13].setYpos(130);
	blk[14].setXpos(900);
	blk[14].setYpos(130);
	blk[15].setXpos(780);
	blk[15].setYpos(80);
	blk[16].setXpos(800);
	blk[16].setYpos(80);
	blk[17].setXpos(700);
	blk[17].setYpos(30);
	blk[18].setXpos(720);
	blk[18].setYpos(30);

	blk[19].setXpos(1400);
	blk[19].setYpos(250);
	blk[20].setXpos(1420);
	blk[20].setYpos(250);
	blk[21].setXpos(1440);
	blk[21].setYpos(250);
	blk[22].setXpos(1760);
	blk[22].setYpos(250);
	blk[23].setXpos(1780);
	blk[23].setYpos(250);
	blk[24].setXpos(1800);
	blk[24].setYpos(250);

	blk[25].setXpos(2100);
	blk[25].setYpos(305);
	blk[26].setXpos(2100);
	blk[26].setYpos(285);
	blk[27].setXpos(2100);
	blk[27].setYpos(265);
	blk[28].setXpos(2100);
	blk[28].setYpos(245);
	// face figure in blocks
	blk[29].setXpos(2400);
	blk[29].setYpos(250);
	blk[30].setXpos(2420);
	blk[30].setYpos(270);
	blk[31].setXpos(2440);
	blk[31].setYpos(250);
	blk[32].setXpos(2420);
	blk[32].setYpos(190);
	blk[33].setXpos(2500);
	blk[33].setYpos(120);
	blk[34].setXpos(2340);
	blk[34].setYpos(120);

	blk[35].setXpos(3000);
	blk[35].setYpos(305);
	blk[36].setXpos(3020);
	blk[36].setYpos(285);
	blk[37].setXpos(3020);
	blk[37].setYpos(305);
	blk[38].setXpos(3040);
	blk[38].setYpos(265);
	blk[39].setXpos(3040);
	blk[39].setYpos(285);
	blk[40].setXpos(3040);
	blk[40].setYpos(305);
	blk[41].setXpos(3060);
	blk[41].setYpos(245);
	blk[42].setXpos(3060);
	blk[42].setYpos(265);
	blk[43].setXpos(3060);
	blk[43].setYpos(285);
	blk[44].setXpos(3060);
	blk[44].setYpos(305);
	blk[45].setXpos(3080);
	blk[45].setYpos(225);
	blk[46].setXpos(3080);
	blk[46].setYpos(245);
	blk[47].setXpos(3080);
	blk[47].setYpos(265);
	blk[48].setXpos(3080);
	blk[48].setYpos(285);
	blk[49].setXpos(3080);
	blk[49].setYpos(305);

	for(int i = 0; i < 500; i++){
		goomba[i].setX(570);//initialize all possible goombas
	}
	
	for(int i = 0; i < 500; i++){
		turtle[i].setX(570);
	}

}

void Level::playLevel() {
	bool quit = false;

	if( !init() ){
		printf( "Failed to initialize!\n" );
	} else {
		//Load media
		if( !loadMedia() ){
			printf( "Failed to load media!\n" );
		} else {
		SDL_Event e;//Event handler

		while(sp.getAliveStatus() && sp.getX() < 3080 - mapDistMove && !quit)  {
				while( SDL_PollEvent( &e ) != 0 ){//Handle events on queue

					switch(e.type){

					case SDL_QUIT: //User requests quit
						quit = true;
						break;

					case SDL_KEYDOWN:
						if(e.key.keysym.sym == SDLK_LEFT){
							sp.setMoveVar(1);  }
						if(e.key.keysym.sym == SDLK_RIGHT){
							//user moves right
							sp.setMoveVar(-1);
						}
						if(e.key.keysym.sym == SDLK_UP){
							if(!sp.inAir())
								sp.setDirection(1);  }
						if(e.key.keysym.sym == SDLK_DOWN){
							//user moves down
						}

						break;
						
					case SDL_KEYUP:
						if(e.key.keysym.sym == SDLK_LEFT)
							sp.setMoveVar(0);
						if(e.key.keysym.sym == SDLK_RIGHT)
							sp.setMoveVar(0);
						break;
					}//end switch
					
				}//end while
				sp.jump();
				checksMario();
				sp.move();
				checksEnemy();
				scrollScreen();
				display();
				
				newGoomba = goomba[0].makeNewGoomba();
				
				if(newGoomba == true){
					newGoomba = false;
					goomba[0].setNewGoomba(false);
					numGoombas++;
				}
				
				for(int i = 0; i < numGoombas; i++)  {
					goomba[i].moveGoomba();
				}
						
				newTurtle = turtle[0].makeNewTurtle();
				
				if(newTurtle == true){
					newTurtle = false;
					turtle[0].setNewTurtle(false);
					numTurtles++;
				}
				
				for(int i = 0; i < numTurtles; i++)  {
					turtle[i].moveTurtle();
				}
						
			}//end while
		if(!quit)
			usleep(2000000);
	}	} // end elses
	close();
}

void Level::display() { //displays Sprite
	jumpImage == NULL;
	SDL_FillRect(gScreenSurface,NULL,0x000000);
	SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image

	SDL_Rect heroSrcRect = sp.getHeroSrcRect();
	SDL_Rect heroRect = sp.getHeroRect();
	if(sp.getAliveStatus())  {
		if(sp.inAir())
			SDL_BlitSurface( jumpImage, &heroSrcRect, gScreenSurface, &heroRect );	
		else if(sp.getMoveVar()!= 0)
			SDL_BlitSurface( walkImage, &heroSrcRect, gScreenSurface, &heroRect );
		else
			SDL_BlitSurface( heroImage, &heroSrcRect, gScreenSurface, &heroRect );
	} else  {
		sp.setLives(sp.getLives()-1);
		SDL_BlitSurface( deadImage, &heroSrcRect, gScreenSurface, &heroRect );	// he dead, change image to dead one
		if (sp.getLives() == 0) {
			//game over bruh, display screen
		} else {
			//display other screen
		}
	}

	for(int i = 0; i < numBlocks; i++)  {
		blockRect[i].x = blk[i].getXpos();
		blockRect[i].y = blk[i].getYpos();
		blockSrcRect[i].w = blk[i].getWidth();
		blockSrcRect[i].h = blk[i].getHeight();
		blockSrcRect[i].x = 0;
		blockSrcRect[i].y = 0;
		SDL_BlitSurface( blockImage, &blockSrcRect[i], gScreenSurface, &blockRect[i] );
	}
	
	for(int i = 0; i < numGoombas; i++)  {
		goombaRect[i].x = goomba[i].getX();
		goombaRect[i].y = 302;
		goombaSrcRect[i].w = 24;
		goombaSrcRect[i].h = 24;
		goombaSrcRect[i].x = 0;
		goombaSrcRect[i].y = 0;
		
		
		if(goomba[i].dead() == false)	
			SDL_BlitSurface( goombaImage, &goombaSrcRect[i], gScreenSurface, &goombaRect[i] );
	}

	for(int i = 0; i < numTurtles; i++)  {
		turtleRect[i].x = turtle[i].getX();
		turtleRect[i].y = 302;
		turtleSrcRect[i].w = 24;
		turtleSrcRect[i].h = 24;
		turtleSrcRect[i].x = 0;
		turtleSrcRect[i].y = 0;
		
		
		if(turtle[i].dead() == 2) //alive image
			SDL_BlitSurface( turtleImage, &turtleSrcRect[i], gScreenSurface, &turtleRect[i] );
		else if(turtle[i].dead() == 1) //in shell image
			SDL_BlitSurface( shellImage, &turtleSrcRect[i], gScreenSurface, &turtleRect[i] );
			//if dead, no image is displayed
	}

	SDL_UpdateWindowSurface( gWindow );//Update the surface
}

void Level::checksMario()  {

	for(int i = 0; i < numBlocks; i++)  {
		if(blk[i].isHit(sp.getX()+4, sp.getY()) || blk[i].isHit(sp.getX()+20, sp.getY()))
			sp.setDirection(-1);

		if(blk[i].isOn(sp.getX()+4, sp.getY()+32) || blk[i].isOn(sp.getX()+20, sp.getY()+32)) {
			sp.setDirection(0);
			sp.resetJumpCounter();
		}

		if(blk[i].isHitLeft(sp.getX()+24, sp.getY()+16) && sp.getMoveVar() == -1)
			sp.setMoveVar(0);

		if(blk[i].isHitRight(sp.getX(), sp.getY()+16) && sp.getMoveVar() == 1)
			sp.setMoveVar(0);
	
	}
}

void Level::checksEnemy()  {
	for(int i = 0; i < numGoombas; i++)  {

		if(!goomba[i].dead() && goomba[i].isOn(sp.getX(), sp.getY()+32) || goomba[i].isOn(sp.getX()+24, sp.getY()+32)) {
			goomba[i].setAlive();
			sp.setDirection(1);
		}
		
		if(!goomba[i].dead() && goomba[i].isHitLeft(sp.getX()+24, sp.getY()+16)){
			sp.setMoveVar(0);
			sp.damage();
		}
		
		if(!goomba[i].dead() && goomba[i].isHitRight(sp.getX(), sp.getY()+16)){
			sp.setMoveVar(0);
			sp.damage();
		}
		for(int j = 0; j < numBlocks; j++)  {
			if(!goomba[i].dead() && goomba[i].isHitLeft(blk[j].getXpos()+20, blk[j].getYpos())){
				goomba[i].setMoveVar(-goomba[i].getMoveVar());
			}
		
			if(!goomba[i].dead() && goomba[i].isHitRight(blk[j].getXpos(), blk[j].getYpos())){
				goomba[i].setMoveVar(-goomba[i].getMoveVar());
			}
		}
	}
	
	
	for(int i = 0; i < numTurtles; i++)  {

		if(turtle[i].dead() != 0 && turtle[i].isOn(sp.getX(), sp.getY()+32) || turtle[i].isOn(sp.getX()+24, sp.getY()+32)) {
			turtle[i].damage();
			sp.setDirection(1);
		}
		
		if(turtle[i].dead() != 0 && turtle[i].isHitLeft(sp.getX()+24, sp.getY()+16)){
			sp.setMoveVar(0);
			sp.damage();
		}
		
		if(turtle[i].dead() != 0 && turtle[i].isHitRight(sp.getX(), sp.getY()+16)){
			sp.setMoveVar(0);
			sp.damage();
		}
		for(int j = 0; j < numBlocks; j++)  {
			if(turtle[i].dead() !=0 && turtle[i].isHitLeft(blk[j].getXpos()+20, blk[j].getYpos())){
				turtle[i].setMoveVar(-turtle[i].getMoveVar());
			}
		
			if(turtle[i].dead() !=0 && turtle[i].isHitRight(blk[j].getXpos(), blk[j].getYpos())){
				turtle[i].setMoveVar(-turtle[i].getMoveVar());
			}
		}
		////////////////////////////////
	
	/*		for(int n = 0; n < numGoombas; n++){
			
				if(turtle[i].dead() != 0 && turtle[i].isHitLeft(goomba[n].getX()+24, goomba[n].getY())){
						if(turtle[i].dead() == 1) turtle[i].setPushed(true);
						else turtle[i].setMoveVar(-turtle[i].getMoveVar());
				}
				
			}*/
			
			//if in shell and is hit on the left by the previous turtles
			for(int l = 0; l < numTurtles; l++){
				if(turtle[i].dead() != 0 && turtle[i].isHitLeft(turtle[l].getX()+24, turtle[l].getY())){
					if(turtle[i].dead() == 1) turtle[i].setPushed(true);
					else turtle[i].setMoveVar(-turtle[i].getMoveVar());
				}
			}
			
	///////////////////////////////////////////////		
				//if in shell and is hit on the right by the next turtles
		for(int k = i+1; k < numTurtles; k++){
			if(turtle[i].dead() != 0 && turtle[i].isHitRight(turtle[k].getX(), turtle[k].getY())){
				if(turtle[i].dead() == 1) turtle[i].setPushed(true);
				else turtle[i].setMoveVar(-turtle[i].getMoveVar());
			}
		}
		
		//if in shell and is hit on the right/left by goombas
		for(int m = 0; m < numGoombas; m++){
			if(turtle[i].dead() != 0 && turtle[i].isHitRight(goomba[m].getX(), goomba[m].getY())){
				if(turtle[i].dead() == 1) turtle[i].setPushed(true);
				else turtle[i].setMoveVar(-turtle[i].getMoveVar());
			}
			
		}
		
	
		////////////////////////////////
		
	}
	
}

void Level::scrollScreen()  {

	if(sp.getX() > 350)  {
		mapDistMove += sp.getX() - 350;
		
		for(int i = 0; i < numBlocks; i++)  {
			blk[i].setXpos(blk[i].getXpos() - sp.getX() + 350);
		}
		
		for(int i = 0; i < numGoombas; i++)  {
			goomba[i].setX(goomba[i].getX() - sp.getX() + 350);
		}
		
		for(int i = 0; i < numTurtles; i++)  {
			turtle[i].setX(turtle[i].getX() - sp.getX() + 350);
		}
		
		sp.setX(350);
	}

}








