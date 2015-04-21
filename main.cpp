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
			
			
			

			//While application is running
			while( !quit ){
				while( SDL_PollEvent( &e ) != 0 ){//Handle events on queue
				
					switch(e.type){
					
						case SDL_QUIT: //User requests quit
							quit = true;
							break;
							
						case SDL_KEYDOWN:
							if(e.key.keysym.sym == SDLK_LEFT){
								//user moves left
							}
							if(e.key.keysym.sym == SDLK_RIGHT){
								//user moves right
							}
							if(e.key.keysym.sym == SDLK_UP){
								//user moves up
							}
							if(e.key.keysym.sym == SDLK_DOWN){
								//user moves down
							}
							break;
					
					}//end switch
					
					if(endGame == true) quit = true; //if the game ends (treated as 1st level for now)
					
				}//end while

				SDL_BlitSurface( gImage, NULL, gScreenSurface, NULL ); //Apply the image				
				SDL_UpdateWindowSurface( gWindow );//Update the surface
			}//end while
			
			//display ending of level graphics
			
			
		}//end inner if
	}//end if

	//Free resources and close SDL
	close();
	return 0;
}



