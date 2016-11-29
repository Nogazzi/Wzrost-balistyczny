#ifndef klasyEkran_h
#define klasyEkran_h

#include "klasyCzasteczek.h"
#include "funkcjeEkranu.h"

//The button states in the sprite sheet
const int NIEWCISNIETY = 0;
const int WCISNIETY = 1;
//The event structure
extern SDL_Event event;
extern SDL_Rect clips[ 2 ];



class Symulacja{
private:
	bool wyjscie;
	int n;
public:
	Symulacja();
	void menuGlowne();
	void nowaSymulacja();
	void startSymulacji(int n);
	void pauza();
	void statystyki();
	void pokazStatystyki(int n);
	void pokazStatystykiV2(int n);
	void creditsy();
};

//klasa przycisk
class Button
{
private:
	//stan przycisku
	bool czyWcisniety;
	//napis na przycisku
	string napis;
	//atrybuty przycisku
	SDL_Rect box;
	//obrazek kursora
	SDL_Rect* clip;
public:
	//inicjalizacja zmiennych
	Button(int x, int y, int w, int h, string napis);
	//zwraca stan przycisku....... true==wcisniety, false==niewcisniety
	bool getStatus();
	//ustawia stan przycisku
	void setStatus(bool stan);
	//handles events and sprite
	void handle_events();
	//pokazuje przycisk na ekranie
	void show();
};

void set_clips();

#endif