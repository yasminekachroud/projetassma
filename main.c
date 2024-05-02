#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "ennemi.h"
#include "collision.h"

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *headerImage = IMG_Load("Tan.png");
    if (headerImage == NULL) {
        printf("Erreur lors du chargement de l'image du header: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Surface *screen, *persotest;
    screen = SDL_SetVideoMode(1280, 668, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    persotest = IMG_Load("graphic/hannibal.png");
    SDL_Rect posperso;
    posperso.x = 64;
    posperso.y = 568;
    posperso.h = 100;
    posperso.w = 100;
    SDL_Rect posHeader;
    posHeader.x = 50;
    posHeader.y = 0;
	int var=0;
    int vitesse = 64;
    entity E;
    SDL_Event event;
    SDL_Surface *back;
    init_entity(&E);
    int running = 1;
    back = IMG_Load("graphic/Background.png");

    while (running) {
	if(var==0){
	animerEntity(&E);}
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            posperso.x -= vitesse;
                            break;
                        case SDLK_RIGHT:
                            posperso.x += vitesse;
                            break;
                        case SDLK_UP:
                            posperso.y -= vitesse;
                            break;
                        case SDLK_DOWN:
                            posperso.y += vitesse;
                            break;
                    }
                    break;
            }
        }
        SDL_BlitSurface(headerImage, NULL, screen, &posHeader);
        SDL_BlitSurface(back, NULL, screen, NULL);
        SDL_BlitSurface(persotest, NULL, screen, &posperso);
        afficher_entity(&E, screen);
        animate_entity(&E);

        if (((E.pos.x - posperso.x) < 400) && ((E.pos.x - posperso.x) > -400)) {
            deplacerIA(&E, posperso);
        } else {
            deplacer(&E);
        }

        if (collisionBB(E.pos, posperso) == 1) {
            printf("collision!!!!!!!!!!! \n");
        }

        Circle circle1 = {E.pos.x, E.pos.y, 20}; // Premier cercle centré sur l'entité
        Circle circle2 = {posperso.x + posperso.w / 2, posperso.y + posperso.h / 2, 25}; // Deuxième cercle centré sur le personnage

        // Test de collision
        if (collisionTRI(circle1, circle2)) {
            printf("Collision détectée !\n");
        } else {
            printf("Pas de collision.\n");
        }
        SDL_BlitSurface(E.image_clock, &E.single_Clock, screen, &E.pos_image_clock);

        SDL_Flip(screen);
        SDL_Delay(32);
    }

    SDL_FreeSurface(back);
    SDL_FreeSurface(persotest);
    SDL_FreeSurface(headerImage);
    SDL_Quit();

    return 0;
}

