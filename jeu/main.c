#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"

#include "constantes.h"
#include "jeu.h"


int main(int argc, char* args[]) {
	
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL, *menu = NULL;
	SDL_Rect position;
	SDL_Event event;
	int continuer = 1;
	
	
	//Initialisation de la SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		
		window = SDL_CreateWindow("Mario Sokoban", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LARGEUR_FENETRE, HAUTEUR_FENETRE, SDL_WINDOW_SHOWN);
		if(window == NULL) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {
			screen = SDL_GetWindowSurface(window);
			SDL_SetWindowIcon(window, IMG_Load("caisse.jpg"));
			//menu
			menu = IMG_Load("menu.jpg");
			if (menu == NULL ) {
				printf( "Unable to load image! SDL Error: %s\n", SDL_GetError() );
			}
			position.x = 0;
			position.y = 0;
			
			while (continuer) {
				
				SDL_WaitEvent(&event);
				switch(event.type) {
					case SDL_QUIT: //Arrêt du programme
						continuer = 0;
						break;
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym) {
							case SDLK_ESCAPE: //Stoppe le jeu
								continuer = 0;
								break;
							case SDLK_KP_1: // Demande à jouer
								jouer(screen, window);
								break;
						}
						break;
				}
				
				SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255)); //fond d'écran en blanc
				SDL_BlitSurface(menu, NULL, screen, &position);
				SDL_UpdateWindowSurface(window);
				
			}
			
		}
	}
	
	//libération mémoire
	SDL_FreeSurface(menu);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
	
}


