//Breanna DeVore-McDonald, Nicholas JOnes, Tallis Bowers, RIley Revuvers
//CSE 20212.01
//Final Project


#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "mainFunctions.h"
#include "Sprite.h"
#include "Level.h"
using namespace std;

int main (int argc, char* args[]) {//compatible with multiple platforms.
	bool endGame = false;

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
							sp.move('l');  }
						if(e.key.keysym.sym == SDLK_RIGHT){
							//user moves right
							sp.move('r');
						}
						if(e.key.keysym.sym == SDLK_UP){
							sp.jump();  }
						if(e.key.keysym.sym == SDLK_DOWN){
							//user moves down
						}

						break;

					}//end switch
					
					if(endGame == true) quit = true; //if the game ends (treated as 1st level for now)
					
				}//end while
				sp.display();
			}//end while
			
			//display ending of level graphics
			
			
		}//end inner if
	}//end if

	//Free resources and close SDL
	close();
	return 0;
}





