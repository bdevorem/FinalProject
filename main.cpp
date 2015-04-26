//Breanna DeVore-McDonald, Nicholas JOnes, Tallis Bowers, RIley Revuvers
//CSE 20212.01
//Final Project


#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "Level.h"

using namespace std;

int main (int argc, char* args[]) {//compatible with multiple platforms.
	//bool endGame = false;
/*
	if( !init() ){
		printf( "Failed to initialize!\n" );
	} else {
		//Load media
		if( !loadMedia() ){
			printf( "Failed to load media!\n" );
		} else {

			bool quit = false; //Main loop flag
			SDL_Event e;//Event handler
			
			Sprite sp; //create sprite object
			//Level lvl1;

			//Uint32 startTime = 0; //set timer up

			//While application is running
			while( !quit ){
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

					if(endGame == true) quit = true; //if the game ends (treated as 1st level for now)
					
				}//end while
                                sp.move();
				sp.jump();
				sp.display();
			}//end while
			
			//display ending of level graphics
			
			
		}//end inner if
	}//end if

	//Free resources and close SDL
	close();
	return 0;
*/

	Level lvl;
	lvl.playLevel();
}





