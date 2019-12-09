#ifndef constantes_h
#define constantes_h


	//attributions de valeurs précises à des constantes
	#define TAILLE_BLOC         34 //en pixels
	#define NB_BLOCS_LARGEUR    12
	#define NB_BLOCS_HAUTEUR    12
	#define LARGEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_LARGEUR
	#define HAUTEUR_FENETRE     TAILLE_BLOC * NB_BLOCS_HAUTEUR

	//la valeur attribuée aux constantes n'importe pas
	enum {HAUT, BAS, GAUCHE, DROITE};
	enum {VIDE, MUR, CAISSE, OBJECTIF, MARIO, CAISSE_OK};


#endif
