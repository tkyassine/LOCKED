#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
typedef struct
{
SDL_Surface *srf[1];
SDL_Rect pos;
}Imm;

void init(Imm* ennemi,Imm* ecran,Imm* bg);
void display(Imm* ennemi , Imm* ecran , Imm* bg);
void load(Imm* ennemi, Imm* bg);
#endif
