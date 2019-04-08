#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "deplacement.h"

int check_input(SDL_Event event, int* test,int done ,Imm* ecran,Imm* personnage){
int i=1;
	while( SDL_PollEvent( &event )){
		switch( event.type ){
			case SDL_KEYUP:
				switch( event.key.keysym.sym ){
					case SDLK_SPACE:
					personnage->pos.x+=50;
					personnage->pos.y+=50;
					break;
					case SDLK_d:
					(*test)=0;
					}
break;
			 case SDL_MOUSEBUTTONUP:

			        if (event.button.button == SDL_BUTTON_RIGHT){
            			personnage->pos.x = event.button.x;
           		        personnage->pos.y = event.button.y;
           		        break;

				}else if(event.button.button == SDL_BUTTON_LEFT){
				personnage->pos.x+=8;
				personnage->pos.y=personnage->pos.y-20;
				}

			case SDL_KEYDOWN:
				switch( event.key.keysym.sym ){
					case SDLK_ESCAPE:
						done=1;
						break;
					case SDLK_d:
						personnage->pos.x+=10;
						(*test)=1;							
						break;
					case SDLK_q:
						personnage->pos.x-=10;
						(*test)=2;
						break;
					case SDLK_e:
						(*test)=3;
						break;
		
					case SDLK_SPACE:
						personnage->pos.x+=50;
						personnage->pos.y-=50;
						break;		
				}
					break;
		}
	}
	return done;
}
void init(Imm* personnage,Imm* ecran,Imm* bg){
	personnage->srf[0]=NULL;
	ecran->srf[0]=NULL;
	bg->srf[0]=NULL;
	personnage->pos.x=0;
	personnage->pos.y=320;
	bg->pos.x=0;
	bg->pos.y=0;
}
void load(Imm* personnage,Imm* bg){

bg->srf[0]=IMG_Load("GameBG_Prototype1.png");
personnage->srf[0]=IMG_Load("yass.png");

personnage->srf[1] = IMG_Load("sprites/walkright/1.png");
personnage->srf[2] = IMG_Load("sprites/walkright/2.png");
personnage->srf[3] = IMG_Load("sprites/walkright/3.png");
personnage->srf[4] = IMG_Load("sprites/walkright/4.png");
personnage->srf[5] = IMG_Load("sprites/walkright/5.png");
personnage->srf[6] = IMG_Load("sprites/walkright/6.png");
personnage->srf[7] = IMG_Load("sprites/walkright/7.png");
}



void display(Imm* personnage,Imm* ecran ,Imm * bg ,int *test ){
int i;
SDL_Surface* update_player=personnage->srf[1];
SDL_BlitSurface(bg->srf[0],NULL,ecran->srf[0],&bg->pos);
SDL_BlitSurface(personnage->srf[0],NULL,ecran->srf[0],&personnage->pos);
SDL_Flip(ecran->srf[0]);	
}






















