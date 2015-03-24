//Using SDL and standard IO
#include <SDL2/SDL_image.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* pic = NULL;

	window = SDL_CreateWindow( "My First Image!!1!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	screenSurface = SDL_GetWindowSurface(window);
	pic = SDL_LoadBMP( "mario.bmp" );
	SDL_BlitSurface(pic, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(5000);
	SDL_FreeSurface(pic);
	pic = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
	return 0;

}
