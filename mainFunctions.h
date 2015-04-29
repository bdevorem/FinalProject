#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
using namespace std;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 385;

bool init(); //Starts up SDL and creates window
bool loadMedia(); //Loads media
void close(); //Frees media and shuts down SDL

//bad bad global variables that are necessary but bad
SDL_Window* gWindow = NULL; //The window we'll be rendering to
SDL_Surface* gScreenSurface = NULL; //The surface contained by the window
SDL_Surface* gImage = NULL;//The image we will load and show on the screen
SDL_Surface* heroImage = NULL; //The hero image will load
SDL_Surface* jumpImage = NULL; //The jumping image loads
SDL_Surface* walkImage = NULL; //The jumping image loads
SDL_Surface* blockImage = NULL; //The jumping image loads
SDL_Surface* goombaImage = NULL; //The jumping image loads
SDL_Surface* turtleImage = NULL; //The jumping image loads
SDL_Surface* shellImage = NULL; //The jumping image loads
SDL_Surface* deadImage = NULL; //The jumping image loads
SDL_Surface* winImage = NULL; //The jumping image loads
SDL_Surface* loseImage = NULL; //The jumping image loads
SDL_Surface* lives2Image = NULL; //The jumping image loads
SDL_Surface* lives1Image = NULL; //The jumping image loads
SDL_Surface* shroomImage = NULL; //The jumping image loads
SDL_Surface* herogImage = NULL; //The jumping image loads
SDL_Surface* walkgImage = NULL; //The jumping image loads
SDL_Surface* jumpgImage = NULL; //The jumping image loads

bool init() {
	bool success = true;//Initialization flag

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { //Initialize SDL
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	} else { //Create window
		gWindow = SDL_CreateWindow( "Super Mario Bros", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

		if( gWindow == NULL ) {
			cout << "Window could not be created! SDL_Error: "<< SDL_GetError() << endl;
			success = false;
		} else { //Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}//end if
	}//end outer if

	return success;
}

bool loadMedia() {
	bool success = true; //Loading success flag

	gImage = SDL_LoadBMP( "Overworld.bmp" );//Load image
	if( gImage == NULL ){
		success = false;
	}
	heroImage = SDL_LoadBMP( "marionew.bmp" );
	if( heroImage == NULL )
		success = false;
	jumpImage = SDL_LoadBMP( "jump.bmp" );
	if( jumpImage == NULL )
		success = false;
	walkImage = SDL_LoadBMP( "walk.bmp" );
	if( walkImage == NULL )
		success = false;
	blockImage = SDL_LoadBMP( "block.bmp" );
	if( blockImage == NULL )
		success = false;
	goombaImage = SDL_LoadBMP( "goomba.bmp" );
	if( goombaImage == NULL )
		success = false;
	turtleImage = SDL_LoadBMP( "turtle.bmp" );
	if( turtleImage == NULL )
		success = false;
	shellImage = SDL_LoadBMP( "shell.bmp" );
	if( shellImage == NULL )
		success = false;
	deadImage = SDL_LoadBMP( "dead.bmp" );
	if( deadImage == NULL )
		success = false;
	shroomImage = SDL_LoadBMP( "shroom.bmp" );
	if( shroomImage == NULL )
		success = false;
	winImage = SDL_LoadBMP( "win.bmp" );
	if( winImage == NULL )
		success = false;
	loseImage = SDL_LoadBMP( "lose.bmp" );
	if( loseImage == NULL )
		success = false;
	lives2Image = SDL_LoadBMP( "2lives.bmp" );
	if( lives2Image == NULL )
		success = false;
	lives1Image = SDL_LoadBMP( "lives1.bmp" );
	if( lives1Image == NULL )
		success = false;
	herogImage = SDL_LoadBMP( "mario2.bmp" );
	if( herogImage == NULL )
		success = false;
	walkgImage = SDL_LoadBMP( "walkg.bmp" );
	if( walkgImage == NULL )
		success = false;
	jumpgImage = SDL_LoadBMP( "jumpg.bmp" );
	if( jumpgImage == NULL )
		success = false;

	return success;
}

void close() {
	SDL_FreeSurface( gImage );//Deallocate surface

	gImage = NULL;

	SDL_DestroyWindow( gWindow ); //Destroy window
	gWindow = NULL;

	SDL_Quit();//Quit SDL subsystems
}


#endif
