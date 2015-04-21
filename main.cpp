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

	if( !init() ){
		printf( "Failed to initialize!\n" );
	} else {
		//Load media
		if( !loadMedia() ){
			printf( "Failed to load media!\n" );
		} else {

			bool quit = false; //Main loop flag
			SDL_Event e;//Event handler

			SDL_Rect heroRect;
			heroRect.x = 100;
			heroRect.y = 295;

			SDL_Rect heroSrcRect;
			heroSrcRect.x = 0;
			heroSrcRect.y = 0;
			heroSrcRect.h = 32;
			heroSrcRect.w = 24;

			SDL_Rect srcRect;
			srcRect.x = 100;
			srcRect.y = 100;
			srcRect.h = 385;
			srcRect.w = 600;

			SDL_Rect dstRect;
			dstRect.x = 100;
			dstRect.y = 100;
			dstRect.h = 1000;
			dstRect.w = 1000;

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
							if(heroRect.x > 100)
								heroRect.x--;
							SDL_FillRect(gScreenSurface,NULL,0x000000);
						}
						if(e.key.keysym.sym == SDLK_RIGHT){
							//user moves right
							if(heroRect.x < 600)
								heroRect.x++;
							SDL_FillRect(gScreenSurface,NULL,0x000000);
						}
						if(e.key.keysym.sym == SDLK_UP){
							//user moves up
						}
						if(e.key.keysym.sym == SDLK_DOWN){
							//user moves down
						}

						break;

					}//end switch
				}//end while

				SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image	
				SDL_BlitSurface( heroImage, &heroSrcRect, gScreenSurface, &heroRect );
				SDL_UpdateWindowSurface( gWindow );//Update the surface
			}//end while
		}//end inner if
	}//end if

	//Free resources and close SDL
	close();
	return 0;
}





