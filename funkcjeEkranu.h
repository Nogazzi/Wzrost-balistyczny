#ifndef funkcjeEkranu_h
#define funkcjeEkranu_h

#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "dirent.h"
#include "SDL.h"
#include "SDL_ttf.h"

#define N 100000		//stala definiujaca ilosc czasteczek, ktore skladaja sie na zbior koncowy(efekt koncowy)
#define vCzasteczki 1
using namespace std;



//obrazki
extern SDL_Surface* pixel;
extern SDL_Surface* pixel_czerwony;
extern SDL_Surface* pixel_niebieski;
extern SDL_Surface* pixel_zielony;
extern SDL_Surface* screen;
extern SDL_Surface* seconds;
extern SDL_Surface* tlo;
extern SDL_Surface* liczbaCzasteczek;
extern SDL_Surface* buttonSheet;
//extern SDL_Surface* kierunki;
//przyciski

//The event structure
extern SDL_Event event;
//czcionka
extern TTF_Font* font;
//kolor czcionki
extern SDL_Color textColor;

//Screen attributes
extern const int SZEROKOSC_EKRANU;
extern const int WYSOKOSC_EKRANU;
extern const int SCREEN_BPP;
//The clip regions of the sprite sheet
extern SDL_Rect clips[ 2 ];


//funkcja losujaca liczbe z przedzialu <min, max>
int losujZPrzedzialu(int min, int max);
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip);
bool porownajNapisy(string napis1, string napis2, int ileZnakow);


//funkcje SDLa
bool init();
bool loadFiles();
void updateScreen();
void sprzataj();




#endif