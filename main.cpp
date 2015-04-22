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
			
			
			

			SDL_Rect heroRect;
			heroRect.x = 100;
			heroRect.y = 295;

			SDL_Rect heroSrcRect;
			heroSrcRect.x = 0;
			heroSrcRect.y = 0;
			heroSrcRect.h = 32;
			heroSrcRect.w = 24;

			SDL_Rect jumpRect;
			jumpRect.x = 0;
			jumpRect.y = 0;

			SDL_Rect jumpSrcRect;
			jumpSrcRect.x = 0;
			jumpSrcRect.y = 0;
			jumpSrcRect.h = 32;
			jumpSrcRect.w = 32;

			SDL_Rect walkRect;
			walkRect.x = 0;
			walkRect.y = 0;

			SDL_Rect walkSrcRect;
			walkSrcRect.x = 0;
			walkSrcRect.y = 0;
			walkSrcRect.h = 30;
			walkSrcRect.w = 26;

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
							//user moves left
							if(heroRect.x > 100) {

								heroRect.x -= 3;
								jumpRect.x -= 3;
							}
							SDL_FillRect(gScreenSurface,NULL,0x000000);
						}
						if(e.key.keysym.sym == SDLK_RIGHT){
							//user moves right
							if(heroRect.x < 600) {
								walkRect.x = heroRect.x;
								walkRect.y = heroRect.y;
								heroRect.y = NULL;
								SDL_FillRect(gScreenSurface,NULL,0x000000);
								SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image
								SDL_BlitSurface( walkImage, &walkSrcRect, gScreenSurface, &walkRect );
								SDL_UpdateWindowSurface( gWindow );//Update the surface*/
								heroRect.x += 3;
								heroRect.y = walkRect.y;
								walkRect.x = NULL;
							}
							SDL_FillRect(gScreenSurface,NULL,0x000000);
						}
						if(e.key.keysym.sym == SDLK_UP){
							if (sp.inAir() == 0) {
								sp.jumpUp();
								sp.setDirection(1);
							}
							sp.resetTimer();
							while (sp.inAir() == 1) {
								if (((SDL_GetTicks() - sp.getTime()) > 110) && sp.getDirection() == 1) {
									sp.jumpUp();
									heroRect.y = NULL;
									jumpRect.y = sp.posY();
									jumpRect.x = heroRect.x;
									SDL_FillRect(gScreenSurface,NULL,0x000000);
									SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image
									SDL_BlitSurface( jumpImage, &jumpSrcRect, gScreenSurface, &jumpRect );
									SDL_UpdateWindowSurface( gWindow );//Update the surface
									sp.resetTimer();
								} else if (((SDL_GetTicks() - sp.getTime()) > 110) && sp.getDirection() == 0) {
									sp.jumpDown();
									heroRect.y = NULL;
									jumpRect.y = sp.posY();
									jumpRect.x = heroRect.x;
									SDL_FillRect(gScreenSurface,NULL,0x000000);
									SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image
									SDL_BlitSurface( jumpImage, &jumpSrcRect, gScreenSurface, &jumpRect );
									SDL_UpdateWindowSurface( gWindow );//Update the surface
									sp.resetTimer();
								}
								if (sp.posY() <= 195) {
									sp.setDirection(0);
								}
								if (sp.posY() > 295)
									sp.setY(295);
							}
							heroRect.y = 295;

							break;
					

						}
						heroRect.y = 295;
						if(e.key.keysym.sym == SDLK_DOWN){
							//user moves down
						}

						break;

					}//end switch
					
					if(endGame == true) quit = true; //if the game ends (treated as 1st level for now)
					
				}//end while
				jumpImage == NULL;
				SDL_BlitSurface( gImage, &srcRect, gScreenSurface, &dstRect ); //Apply the image	
				SDL_BlitSurface( heroImage, &heroSrcRect, gScreenSurface, &heroRect );
				SDL_UpdateWindowSurface( gWindow );//Update the surface
			}//end while
			
			//display ending of level graphics
			
			
		}//end inner if
	}//end if

	//Free resources and close SDL
	close();
	return 0;
}





