#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <math.h>

// Structure représentant un cercle
typedef struct {
    float x, y;     // Coordonnées du centre
    float radius;   // Rayon du cercle
} Circle;

typedef struct entity
	{
	
    SDL_Surface *sprite;
	int direction,directionV;
	SDL_Rect pos,positionminimale,positionmaximale,possprite;
	SDL_Surface *image_clock;
	SDL_Rect pos_image_clock;
	SDL_Rect single_Clock;
	int clock_num;
	}entity;

void init_entity (entity *E);
void afficher_entity (entity *E,SDL_Surface *screen);
void animate_entity (entity *E);
int collisionBB(SDL_Rect E, SDL_Rect personnage);
void deplacer( entity * E);
void deplacerIA( entity * E, SDL_Rect posPerso);
void animerEntity(entity *E);
int collisionTRI(Circle c1, Circle c2);



















#endif // DS_H_INCLUDED
