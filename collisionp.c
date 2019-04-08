#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "collisionp.h"

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
void init(Imm* personnage,Imm* ecran,Imm* bg,Imm* bg1,Imm* play){

	personnage->srf[0]=NULL;
	ecran->srf[0]=NULL;
	bg->srf[0]=NULL;
	play->srf[0]=NULL;
	personnage->pos.x=0;
	personnage->pos.y=320;
	play->pos.x=0;
	play->pos.y=0;
	bg->pos.x=0;
	bg->pos.y=0;
	bg1->pos.x=0;
	bg1->pos.y=0;
}

void load(Imm* personnage,Imm* bg,Imm* bg1,Imm* play){

bg->srf[0]=IMG_Load("Unmasked lvl1.png");
bg1->srf[1]=IMG_Load("mask.png");
personnage->srf[2]=IMG_Load("yass.png");
play->srf[3]=IMG_Load("play_h.png");
}


void display(Imm* personnage,Imm* ecran ,Imm * bg,Imm * bg1 ,int *test,Imm* play ){
SDL_BlitSurface(bg->srf[0],NULL,ecran->srf[0],&bg->pos);
//SDL_BlitSurface(bg1->srf[1],NULL,ecran->srf[0],&bg->pos);
SDL_BlitSurface(personnage->srf[2],NULL,ecran->srf[0],&personnage->pos);
if(collision_back(personnage,bg1)==1){
	SDL_BlitSurface(play->srf[3],NULL,ecran->srf[0],&play->pos);
}
SDL_Flip(ecran->srf[0]);
}


SDL_Color GetPixel (SDL_Surface *pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}

int collision_back (Imm *personnage,Imm* bg1)
{
  SDL_Rect point[8];
  SDL_Color couleur[8];

point[0].x=personnage->pos.x+personnage->pos.w+10;
point[0].y=personnage->pos.y+personnage->pos.h/2;

point[4].x=personnage->pos.x+personnage->pos.w+10;
point[4].y=personnage->pos.y+personnage->pos.h/4;

point[5].x=personnage->pos.x+personnage->pos.w+10;
point[5].y=personnage->pos.y+(personnage->pos.h*3)/4;

point[1].x=personnage->pos.x+personnage->pos.w/2;
point[1].y=personnage->pos.y+personnage->pos.h;

point[2].x=personnage->pos.x-10;
point[2].y=personnage->pos.y+personnage->pos.h/2;

point[6].x=personnage->pos.x-10;   
point[6].y=personnage->pos.y+personnage->pos.h/4;

point[7].x=personnage->pos.x-10;
point[7].y=personnage->pos.y+(personnage->pos.h*3)/4;

point[3].x=personnage->pos.x+personnage->pos.w/2;
point[3].y=personnage->pos.y;  
 
couleur[0]=GetPixel (bg1->srf[1], point[0].x, point[0].y);
couleur[1]=GetPixel (bg1->srf[1], point[1].x, point[1].y);
couleur[2]=GetPixel (bg1->srf[1], point[2].x, point[2].y);
couleur[3]=GetPixel (bg1->srf[1], point[3].x, point[3].y);
couleur[4]=GetPixel (bg1->srf[1], point[4].x, point[4].y);
couleur[5]=GetPixel (bg1->srf[1], point[5].x, point[5].y);
couleur[6]=GetPixel (bg1->srf[1], point[6].x, point[6].y);
couleur[7]=GetPixel (bg1->srf[1], point[7].x, point[7].y);


if (couleur[1].r==255 && couleur[1].g==0 && couleur[1].b==252)
return 1;

else if (couleur[3].r==255 && couleur[3].g==0 && couleur[3].b==252)
return 1;

else if (couleur[1].r==255 && couleur[1].g==0 && couleur[1].b==252)
return 1;

else if ((couleur[2].r==255 && couleur[2].g==0 && couleur[2].b==252)||(couleur[6].r==255 && couleur[6].g==0 && couleur[6].b==252)||(couleur[7].r==255 && couleur[7].g==0 && couleur[7].b==252))
return 1;

else if ((couleur[0].r==255 && couleur[0].g==0 && couleur[0].b==252)||(couleur[4].r==255 && couleur[4].g==0 && couleur[4].b==252)||(couleur[5].r==255 && couleur[5].g==0 && couleur[5].b==252))
return 1;

else return 0;

}


