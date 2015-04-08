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

	return success;
}

void close() {
	SDL_FreeSurface( gImage );//Deallocate surface

	gImage = NULL;

	SDL_DestroyWindow( gWindow ); //Destroy window
	gWindow = NULL;

	SDL_Quit();//Quit SDL subsystems
}

