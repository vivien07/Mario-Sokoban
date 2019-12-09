#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"

#include "constantes.h"
#include "fichiers.h"
#include "jeu.h"


void jouer(SDL_Surface* ecran, SDL_Window* window) {
	
	//printf("jeu OK\n");
	
	SDL_Surface *mario[4] = {NULL}; // 4 surfaces pour chaque direction de mario(bas,haut, gauche, droite)
	SDL_Surface *mur = NULL, *caisse = NULL, *caisseOK = NULL, *objectif = NULL, *marioActuel = NULL;
	SDL_Rect position, positionJoueur;
	SDL_Event event;
	int continuer = 1, objectifsRestants = 0;//booléens valant vrai et faux
	int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};
	
	// Chargement des sprites
	mur = IMG_Load("mur.jpg");
	caisse = IMG_Load("caisse.jpg");
	caisseOK = IMG_Load("caisse_ok.jpg");
	objectif = IMG_Load("objectif.png");
	mario[BAS] = IMG_Load("mario_bas.gif");
	mario[GAUCHE] = IMG_Load("mario_gauche.gif");
	mario[HAUT] = IMG_Load("mario_haut.gif");
	mario[DROITE] = IMG_Load("mario_droite.gif");
	marioActuel = mario[BAS]; // orientation de Mario au départ
	
	// Chargement du niveau
	if (!chargerNiveau(carte)) {
		printf("Level can't be loaded\n");
		exit(EXIT_FAILURE);
	}
	
	// Recherche de la position de Mario au départ en parcourant la grille
	for (int i = 0 ; i < NB_BLOCS_LARGEUR ; i++) {
		for (int j = 0 ; j < NB_BLOCS_HAUTEUR ; j++) {
			if (carte[i][j] == MARIO) {
				positionJoueur.x = i;
				positionJoueur.y = j;
				carte[i][j] = VIDE;
			}
		}
	}
	
	while (continuer) {
		
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				continuer = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					case SDLK_UP:
						marioActuel = mario[HAUT];
						//deplacerJoueur(carte, &positionJoueur, HAUT);
						break;
					case SDLK_DOWN:
						marioActuel = mario[BAS];
						//deplacerJoueur(carte, &positionJoueur, BAS);
						break;
					case SDLK_RIGHT:
						marioActuel = mario[DROITE];
						//deplacerJoueur(carte, &positionJoueur, DROITE);
						break;
					case SDLK_LEFT:
						marioActuel = mario[GAUCHE];
						//deplacerJoueur(carte, &positionJoueur, GAUCHE);
						break;
				}
				break;
		}
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); // Effacement de l'écran
		
		// Placement des objets à l'écran
		for (int i = 0; i < NB_BLOCS_LARGEUR; i++) {
			
			for (int j = 0 ; j < NB_BLOCS_HAUTEUR ; j++) {
				position.x = i * TAILLE_BLOC;
				position.y = j * TAILLE_BLOC;
				switch(carte[i][j]) {
					case MUR:
						SDL_BlitSurface(mur, NULL, ecran, &position);
						break;
					case CAISSE:
						SDL_BlitSurface(caisse, NULL, ecran, &position);
						break;
					case CAISSE_OK:
						SDL_BlitSurface(caisseOK, NULL, ecran, &position);
						break;
					case OBJECTIF:
						SDL_BlitSurface(objectif, NULL, ecran, &position);
						objectifsRestants = 1;
						break;
				}
			}
			
		}
		
		// Si on n'a trouvé aucun objectif sur la carte, c'est qu'on a gagné
		if (!objectifsRestants)
			continuer = 0;
		// On place le joueur à la bonne position
		position.x = positionJoueur.x * TAILLE_BLOC;
		position.y = positionJoueur.y * TAILLE_BLOC;
		SDL_BlitSurface(marioActuel, NULL, ecran, &position);
		SDL_UpdateWindowSurface(window);
		
		
	} //fin de la boucle
	
	// Libération des surfaces chargées
	SDL_FreeSurface(mur);
	SDL_FreeSurface(caisse);
	SDL_FreeSurface(caisseOK);
	SDL_FreeSurface(objectif);
	for (int i = 0 ; i < 4 ; i++)
		SDL_FreeSurface(mario[i]);
	
	
}


void deplacerJoueur(int carte[][NB_BLOCS_HAUTEUR], SDL_Rect *pos, int direction) {
	
	
	
	
}