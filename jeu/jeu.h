#include <SDL2/SDL.h>

#ifndef jeu_h
#define jeu_h

	void jouer(SDL_Surface* ecran, SDL_Window* window);
	void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos, int direction);
void deplacerCaisse(int *premiereCase, int *secondeCase);

#endif
