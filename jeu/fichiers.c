#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"

#include "constantes.h"
#include "fichiers.h"


int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR], int level) {
	
    FILE* fichier = NULL;
    char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};//caractère de fin de chaîne
	int numeroLigne = 1;
	char caractere = ' ';
    fichier = fopen("niveaux.lvl", "r");
    if (fichier == NULL) //test de l'ouverture
        return 0;

	rewind(fichier);
	while (numeroLigne < level) {
		caractere = fgetc(fichier);
		if (caractere == '\n')
			numeroLigne++;
	}
    fgets(ligneFichier, NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1, fichier);

    for (int i = 0 ; i < NB_BLOCS_HAUTEUR ; i++) { //lignes
		
        for (int j = 0 ; j < NB_BLOCS_LARGEUR ; j++) { //colonnes
            switch (ligneFichier[(i * NB_BLOCS_LARGEUR) + j]) {
					//conversion des caractères en chiffres
                case '0':
                    niveau[i][j] = 0;
                    break;
                case '1':
                    niveau[i][j] = 1;
                    break;
                case '2':
                    niveau[i][j] = 2;
                    break;
                case '3':
                    niveau[i][j] = 3;
                    break;
                case '4':
                    niveau[i][j] = 4;
                    break;
            }
        }
		
    }
	
    fclose(fichier);
    return 1;
	
}



