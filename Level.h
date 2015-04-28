//Level.h
//12 4 2015

#include "Sprite.h"
#include "Block.h"
#include "mainFunctions.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "Goomba.h"
using namespace std;

#ifndef LEVEL_H
#define LEVEL_H

class Level {
	public:
		Level();
		void playLevel();
		void display(); //displays on screen based on outputs
		void checks();
		void scrollScreen();
		
	protected:
		Sprite sp;
		int numBlocks;
		int numGoombas;
		Block blk[2];
		Goomba goomba[2];
		SDL_Rect srcRect;
		SDL_Rect dstRect;
		int mapDistMove;
		SDL_Rect blockRect[2];
		SDL_Rect blockSrcRect[2];
		SDL_Rect goombaRect[2];
		SDL_Rect goombaSrcRect[2];
		
};
#endif

Level::Level() {
	mapDistMove = 0;
	numBlocks = 2;
	numGoombas = 1;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.h = 385;
	srcRect.w = 600;

	dstRect.x = 0;
	dstRect.y = 0;
	dstRect.h = 1000;
	dstRect.w = 1000;

	blk[0].setXpos(0);
	blk[0].setYpos(190);

	blk[1].setXpos(200);
	blk[1].setYpos(299);
	
	goomba[0].setX(100);

	for(int i = 0; i < numBlocks; i++)  {
		blockRect[i].x = blk[i].getXpos();
		blockRect[i].y = blk[i].getYpos();
		blockSrcRect[i].w = blk[i].getWidth();
		blockSrcRect[i].h = blk[i].getHeight();
		blockSrcRect[i].x = 0;
		blockSrcRect[i].y = 0;
	}
	
	for(int i = 0; i < numGoombas; i++)  {
		goombaRect[i].x = goomba[i].getX();
		goombaRect[i].y = 295;
		goombaSrcRect[i].w = 24;
		goombaSrcRect[i].h = 24;
		goombaSrcRect[i].x = 0;
		goombaSrcRect[i].y = 0;
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

		while(sp.getX() < 550 && !quit)  {
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
				checks();
                                sp.move();
				display();
			}//end while
		
	}	} // end elses
	close();
}

void Level::display() { //displays Sprite
	jumpImage == NULL;
	SDL_FillRect(gScreenSurface,NULL,0x000000);
	SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image

	SDL_Rect heroSrcRect = sp.getHeroSrcRect();
	SDL_Rect heroRect = sp.getHeroRect();

	if(sp.inAir())
		SDL_BlitSurface( jumpImage, &heroSrcRect, gScreenSurface, &heroRect );	
	else if(sp.getMoveVar()!= 0)
		SDL_BlitSurface( walkImage, &heroSrcRect, gScreenSurface, &heroRect );
	else
		SDL_BlitSurface( heroImage, &heroSrcRect, gScreenSurface, &heroRect );
	
	for(int i = 0; i < numBlocks; i++)  {
		SDL_BlitSurface( blockImage, &blockSrcRect[i], gScreenSurface, &blockRect[i] );
	}
	
	for(int i = 0; i < numGoombas; i++)  {
		SDL_BlitSurface( goombaImage, &goombaSrcRect[i], gScreenSurface, &goombaRect[i] );
		
		goombaRect[i].y = 295;
		goombaRect[i].x = goomba[i].getX();
		
		if(goomba[i].dead() == true)
			goombaImage = NULL;
			
		
	}

	SDL_UpdateWindowSurface( gWindow );//Update the surface
}

void Level::checks()  {

	for(int i = 0; i < numBlocks; i++)  {
		if(blk[i].isHit(sp.getX(), sp.getY()))
			sp.setDirection(-1);

		if(blk[i].isOn(sp.getX(), sp.getY()+32)) {
			sp.setDirection(0);
			sp.resetJumpCounter(); }

		if(blk[i].isHitLeft(sp.getX()+24, sp.getY()+16) && sp.getMoveVar() == -1)
			sp.setMoveVar(0);

		if(blk[i].isHitLeft(sp.getX(), sp.getY()+16) && sp.getMoveVar() == 1)
			sp.setMoveVar(0);
	}

}

void Level::scrollScreen()  {

	if(sp.getX() > 500)  {
		for(int i = 0; i < numBlocks; i++)  {
			blk[i].setXpos(blk[i].getXpos() - sp.getX() + 500);
		}
		sp.setX(500);
	}

}
