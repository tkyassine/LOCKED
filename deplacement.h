#ifndef HEADERNAME_H_INCLUDED
#define HEADERNAME_H_INCLUDED
typedef struct
{
SDL_Surface *srf[41];
SDL_Rect pos;
}Imm;

int check_input(SDL_Event event, int* test,int done,Imm* ecran,Imm* personnage);
void init(Imm* personnage,Imm* ecran,Imm* bg);
void load(Imm* personnage,Imm* bg);
void display(Imm* personnage,Imm* ecran, Imm* bg ,int *test);

#endif // HEADERNAME_H_INCLUDED
