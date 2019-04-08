#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "deplacement.h"

int main()
{
   Imm ecran,personnage,bg;
   SDL_Event event;
   SDL_Init(SDL_INIT_EVERYTHING);
	int done=0;
	int test=0;
   	int i;
   
   init(&personnage,&ecran,&bg); 
   ecran.srf[0] = SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF|SDL_SWSURFACE); 
   load(&personnage,&bg);
   SDL_EnableKeyRepeat(120, 120);

  while(!done)
{
   display(&personnage,&ecran,&bg,&test);
   done= check_input(event,&test,done,&ecran,&personnage);

}
for(i=0;i<6;i++){
SDL_FreeSurface(personnage.srf[i]);
} 
SDL_FreeSurface(personnage.srf[0]);
SDL_FreeSurface(bg.srf[0]); 
SDL_Quit();


return 0;
}
