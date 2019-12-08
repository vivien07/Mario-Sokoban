#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"

//dimensions écran
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


void stop() {
	
	int continuer = 1;
	SDL_Event event;
	
	while (continuer) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						continuer = 0;
						break;
				}
				break;
		}
	}
	
}

int main(int argc, char* args[]) {
	
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL, *mario = NULL;
	
	SDL_Rect position;
	
	
	//Initialisation de la SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		
		window = SDL_CreateWindow("Evénements", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window == NULL) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {
			screen = SDL_GetWindowSurface(window);
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); //fond d'écran en blanc
			
			//mario
			mario = IMG_Load("mario_bas.gif");
			if (mario == NULL ) {
				printf( "Unable to load image! SDL Error: %s\n", SDL_GetError() );
			}
			position.x = SCREEN_WIDTH/2;
			position.y = SCREEN_HEIGHT/2;
			SDL_BlitSurface(mario, NULL, screen, &position);
			
			SDL_UpdateWindowSurface(window);
			stop();
			
		}
		
	}
	
	//libération mémoire
	SDL_FreeSurface(mario);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
	
}


