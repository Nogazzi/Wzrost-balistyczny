#ifndef klasyCzasteczek_h
#define klasyCzasteczek_h

#include "funkcjeEkranu.h"
#include <fstream>
#define DZIESIEC 10000
#define PIECDZIESIAT 50000
#define STO 100000
#define PIECSET 300000
#define N 100000

extern SDL_Rect clips[ 2 ];
class Czasteczka
{
//private:
	int x;
	int y;
	int kierunek;	//1 - w dol, 2 - w gore, 3 - w lewo, 4 - w prawo
	//SDL_Surface* obrazek;
	int ilosc;

public:
	Czasteczka();
	Czasteczka(int x, int y);	//kontruktor klasy Czasteczka. Tworzy nowa czasteczke o wspolrzednych X oraz Y
	Czasteczka(int x, int y, int kierunek);		//konstruktor klasy Czasteczka. Tworzy nowa czasteczke o wspolrzednych X oraz Y rozpoczynajaca ruch w kierunku podanym w 3argumencie
	int getSzerokosc();
	int getWysokosc();
	int getKierunek();
	int getX();					//funkcja zwracajaca wspolrzedna X danej czasteczki
	int getY();					//funkcja zwracajaca wspolrzedna Y danej czasteczki
	void lec();					//zmiana polozenia czasteczki w linii prostej na podstawie kierunku jej lotu
	void cofnijCzasteczke();	//cofa ruch czasteczki o jedna jednostke(po wykryciu kolizji)
	void wyswietlCzasteczke();
	void wyswietlCzasteczkeNaLewo();
	void wyswietlCzasteczkeNaPrawo();
	void wyswietlNaStatystyki();
	void zwiekszIlosc();

	~Czasteczka();
	friend class Zbior;
};

//Klasa bedaca kontenerem klasy Czasteczka,
//przechowuje wskazniki na obiekty typu Czasteczka
class Zbior
{
private: 
	int docelowaIloscCzasteczek;
	vector<Czasteczka*> tablicaCzasteczek;	//kontener na czasteczki
//	Czasteczka* czasteczki[PIECSET];	//tablica przechowujaca wskazniki na obiekty dynamiczne typu Czasteczka
	int iloscCzasteczek;		//liczba czasteczek aktualnie przechowywanych w zbiorze
	int szerokoscZbioru;		//wartosc opisujaca odleglosc na osi X pomiedzy najbardziej wysunietymi ( na prawo i lewo ) czasteczkami bedacymi w zbiorze
	int wysokoscZbioru;			//wartosc opisujaca odleglosc na osi Y pomiedzy najbardziej wysunietymi ( w gore i w dol ) czasteczkami bedacymi w zbiorze
	int wspolrzedneSrodka[2];	//wspolrzedne srodka zbioru wspolrzedneSrodka[0]=x, wspolrzedneSrodka[1]=y
	int iloscDziur;
	int polePowierzchni;
	int xSrodka;
	int ySrodka;
	double gestoscCalkowita;
	double delty[9];
	double gestosci[9];
	
public:
	Zbior(int n);	//tworzy pierwsze 4 czasteczki
	Zbior( string nazwaPliku, int n );
	int getSzerokoscZbioru();		//funkcja zwracajaca wartosc odpowiadajaca aktualnej szerokosci zbioru
	int getWysokoscZbioru();		//funkcja zwracajaca wartosc odpowiadajaca aktualnej wysokosci zbioru
	void dodajCzasteczke(int xStartu, int yStartu, int kierunek);
	//int pozycjaStartowa[N];
	int getIloscCzasteczek();
	int getDocelowaIloscCzasteczek();
	int getXSkrajnieLewejCzasteczki();		//zwraca wartosc wspolrzednej X czasteczki (aktualnie przechowywanej w zbiorze) wysunietej najbardziej na lewo
	int getXSkrajniePrawejCzasteczki();		//zwraca wartosc wspolrzednej X czasteczki (aktualnie przechowywanej w zbiorze) wysunietej najbardziej na prawo
	int getYSkrajnieGornejCzasteczki();		//zwraca wartosc wspolrzednej Y czasteczki (aktualnie przechowywanej w zbiorze) wysunietej najbardziej w gore
	int getYSkrajnieDolnejCzasteczki();		//zwraca wartosc wspolrzednej Y czasteczki (aktualnie przechowywanej w zbiorze) wysunietej najbardziej w dol
	int obliczIloscDziur();
	void obliczPolePowierzchni();
	void obliczGestoscCalkowita();
	void obliczXSrodka();
	void obliczYSrodka();
	void liczGestosciObszarowe();
	void rysujObiekt();
	void wypiszDane();			//wypisanie listy czasteczek aktualnie przechowywanych w zbiorze oraz ich wspolrzednych X i Y
	void wyswietlZbior();
	void wyswietlZbiorNaLewo();
	void wyswietlZbiorNaPrawo();
	void zapisdopliku();
	void destruktorZbioru();
	bool spotkanoCzasteczke(int x, int y);	//spradza czy istnieje czasteczka o podanych wspolrzednych
	void usunCzasteczki();
	~Zbior();
	bool sprawdzKolizje(Czasteczka czasteczka);
	friend class Czasteczka;
	friend class KolekcjaZbiorow;
};

class KolekcjaZbiorow{
private:
	int liczbaCzasteczek;	//liczba czasteczek
	vector<Zbior*> tablicaZbiorow;	//kontener przechowujacy wczytane zbiory
	vector<string>listaPlikow;
	vector<Czasteczka*>listaCzasteczekDoStatystyk;	//lista wszystkich czasteczek do wyswietlenia w statystykach
	int iloscZbiorow;	//ilosc zbiorow branych do statystyki
	
	int dol;
	int gora;
	int lewo;
	int prawo;
	int liczbaDziur;	//liczba dziur ze wszystkich zbiorow
public:
	KolekcjaZbiorow();
	KolekcjaZbiorow(int n);	//konstruktor tworzacy kolekcje zbiorow zawierajacych n czasteczek
	void zrobListePlikow();
	int getLiczbaCzasteczek();
	int getIloscZbiorow();
	int getLiczbaDziur();
	int getDol();
	int getGora();
	int getLewo();
	int getPrawo();
	void stworzListeCzasteczek();
	int getLiczbeZListyCzasteczek();
	bool sprawdzCzyIstniejeNaLiscie(int x, int y);
	void obliczLiczbeDziur();
	void wyswietlZbiory();
	void wyswietlZbiorNaLewo(int n);
	void wyswietlZbiorNaPrawo(int n);
	void wyswietlNaStatystyki();
	void usunZbiory();
	void zliczKierunki();
	void wypiszStatystykeKierunkow();
	
};

class Dziura{
	int x;
	int y;
public:
	Dziura(int x, int y);
};

#endif