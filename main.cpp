//Breanna DeVore-McDonald
//CSE 20212.01
//Final Project test


#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "mainFunctions.h"
using namespace std;

int main (int argc, char* args[]) {//compatible with multiple platforms.

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

					if( e.type == SDL_QUIT ){ //User requests quit
						quit = true;
					}
				}

				SDL_BlitSurface( gImage, NULL, gScreenSurface, NULL ); //Apply the image				
				SDL_UpdateWindowSurface( gWindow );//Update the surface
			}//end while
		}//end inner if
	}//end if

	//Free resources and close SDL
	close();
	return 0;
}



