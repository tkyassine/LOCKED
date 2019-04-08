#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include "ennemi.h"
void init(Imm* ennemi,Imm* ecran,Imm* bg){
	ennemi->srf[0]=NULL;
	bg->srf[0]=NULL;
	bg->pos.x=0;
	bg->pos.y=0;
	ennemi->pos.x=50;
	ennemi->pos.y=60;
}
void load(Imm* ennemi, Imm* bg){
	ennemi->srf[0]=IMG_Load("ennemi.png");
	bg->srf[0]=IMG_Load("Menu prototype.png");
}
void display(Imm* ennemi , Imm* ecran , Imm* bg){

	SDL_BlitSurface(bg->srf[0], NULL, ecran->srf[0], &bg->pos);
	SDL_BlitSurface(ennemi->srf[0], NULL, ecran->srf[0], &ennemi->pos);
	SDL_Flip(ecran->srf[0]);

}
