
#include "ennemi.h"
void init_entity (entity *E)
{

E->sprite=IMG_Load("graphic/enemy.png");
    E->pos.x=1000;
    E->pos.y=600;
    E->direction=0; 
    E->directionV=0;


E->possprite.x=0;
E->possprite.y=0;
E->possprite.h=80;
E->possprite.w=64;

E->positionminimale.x=500;
E->positionmaximale.y=300;
E->positionmaximale.x=800;
E->positionminimale.y=240;


(*E).image_clock=IMG_Load("shild.png");  
       
	E->pos_image_clock.x=20;
	E->pos_image_clock.y=20;
        
	
	E->single_Clock.w=57;
	E->single_Clock.h=81;
	E->single_Clock.x=0;
	E->single_Clock.y=0;

	E->clock_num=0;

}

void afficher_entity (entity *E,SDL_Surface *screen)
{
  SDL_BlitSurface(E->sprite,&E->possprite,screen,&E->pos);
  SDL_BlitSurface(E->image_clock,&(E->single_Clock),screen,&E->pos_image_clock);
	
}
void animate_entity (entity *E)
{
E->possprite.y = E->direction * E->possprite.h;
if ( E->possprite.x == 512 - E->possprite.w )
{
    E->possprite.x=0;
}else
{
    E->possprite.x+= E->possprite.w;
}
}
void deplacer(entity *E) 
    {int vitesse=4;
    if (E->pos.y < E->positionminimale.y)
    {
        E->directionV = 0;
    }else if (E->pos.y > E->positionmaximale.y)
    {
        E->directionV = 1;
    
    }

    if (E->pos.x < E->positionminimale.x)
    {
        E->direction = 0;
    }else if (E->pos.x > E->positionmaximale.x)
    {
        E->direction = 1;
    }

    if (E->direction == 0)
    {
        E->pos.x+=vitesse;
    }
    if (E->direction == 1)
    {
        E->pos.x-=vitesse;
    }  
    if (E->directionV == 0)
    {
        E->pos.y+=vitesse;
    }
    if (E->directionV == 1)
    {
        E->pos.y-=vitesse;
    }  
}
void deplacerIA( entity * E, SDL_Rect posPerso)
{int vitesse=8;
    if (((E->pos.x - posPerso.x) < 400) && ((E->pos.x - posPerso.x) > 80)) 
    {
       
        E->pos.x-=vitesse;
	E->direction=1;
    }

    else if (((E->pos.x - posPerso.x) < -80) && ((E->pos.x - posPerso.x) > -400))
    {
     
        E->pos.x+=vitesse;
	E->direction=0;
    }

    if (((E->pos.y - posPerso.y) > 20)) 
    {
       
	E->pos.y-=vitesse;
  
    }
    else if (((E->pos.y - posPerso.y) <-40) ) 
    {
       
	E->pos.y+=vitesse; 
    }
}
int collisionBB (SDL_Rect E,SDL_Rect p)
{
    int collision;
    if (((p.x + p.w) < E.x) || (p.x > (E.x + E.w)) || ((p.y + p.h) < E.y) || (p.y > (E.y + E.h)))
    {
        collision = 0;
    }
    else
    {
        collision = 1;
    }
    
    return collision;
}
 
void animerEntity(entity *E){
		 	
	if (E->clock_num >=0 && E->clock_num <4) {
	E->clock_num++;
	E->single_Clock.x=E->clock_num * E->single_Clock.w;

	}
	
	if ( E->clock_num == 4) {
	E->clock_num=0;
	E->single_Clock.x=E->clock_num * E->single_Clock.w;

	}
 
}


