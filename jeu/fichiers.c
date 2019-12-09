#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "SDL2_image/SDL_image.h"

#include "constantes.h"
#include "fichiers.h"


int chargerNiveau(int niveau[][NB_BLOCS_HAUTEUR]) {
	
    FILE* fichier = NULL;
    char ligneFichier[NB_BLOCS_LARGEUR * NB_BLOCS_HAUTEUR + 1] = {0};//caractère de fin de chaîne

    fichier = fopen("niveaux.lvl", "r");
    if (fichier == NULL) //test de l'ouverture
        return 0;

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


int sauvegarderNiveau(int niveau[][NB_BLOCS_HAUTEUR]) {
	
    FILE* fichier = NULL;
	
    fichier = fopen("niveaux.lvl", "w");
    if (fichier == NULL)
        return 0;

    for (int i = 0 ; i < NB_BLOCS_LARGEUR ; i++) {
		
        for (int j = 0 ; j < NB_BLOCS_HAUTEUR ; j++) {
            fprintf(fichier, "%d", niveau[j][i]);
        }
		
    }
    fclose(fichier);
    return 1;
	
}
