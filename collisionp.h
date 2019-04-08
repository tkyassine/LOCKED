#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED
typedef struct
{
SDL_Surface *srf[4];
SDL_Rect pos;
}Imm;

int check_input(SDL_Event event, int* test,int done,Imm* ecran,Imm* personnage);
void init(Imm* personnage,Imm* ecran,Imm* bg,Imm* bg1,Imm* play);
void load(Imm* personnage,Imm* bg,Imm * bg1,Imm* play);
void display(Imm* personnage,Imm* ecran, Imm* bg ,Imm * bg1,int *test,Imm* play);
SDL_Color GetPixel (SDL_Surface *pSurface,int x,int y);
int collision_back (Imm *personnage,Imm* bg1);
#endif // HEADERNAME_H_INCLUDED
