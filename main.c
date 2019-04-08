#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "collisionp.h"

int main()
{
   Imm ecran,personnage,bg,bg1,play;
   SDL_Event event;
   SDL_Init(SDL_INIT_EVERYTHING);
	int done=0;
	int test=0;
   	int i;

   
   init(&personnage,&ecran,&bg,&bg1,&play); 
   ecran.srf[0] = SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF|SDL_SWSURFACE); 
   load(&personnage,&bg,&bg1,&play);
   SDL_EnableKeyRepeat(120, 120);

  while(!done)
{
   display(&personnage,&ecran,&bg,&bg1,&test,&play);
   done= check_input(event,&test,done,&ecran,&personnage);
   collision_back (&personnage,&bg1);

}
SDL_FreeSurface(personnage.srf[0]);
SDL_FreeSurface(bg.srf[0]); 
SDL_Quit();


return 0;
}
