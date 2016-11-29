#include "funkcjeEkranu.h"


//obrazki
extern SDL_Surface* pixel = NULL;
extern SDL_Surface* pixel_czerwony = NULL;
extern SDL_Surface* pixel_niebieski = NULL;
extern SDL_Surface* pixel_zielony = NULL;
extern SDL_Surface* screen = NULL;
extern SDL_Surface* seconds = NULL;
extern SDL_Surface* tlo = NULL;
extern SDL_Surface* liczbaCzasteczek = NULL;
extern SDL_Surface* buttonSheet = NULL;
//extern SDL_Suraface* kierunki = NULL;
//The event structure
extern SDL_Event event;
//czcionka
extern TTF_Font* font = NULL;
//kolor czcionki
extern SDL_Color textColor = { 255, 255, 255};

//Screen attributes
extern const int SZEROKOSC_EKRANU = 1024;
extern const int WYSOKOSC_EKRANU = 768;
extern const int SCREEN_BPP = 32;

int losujZPrzedzialu(int min, int max)
{
	//cout<<"Losuje z przedzialu <"<<min<<", "<<max<<">"<<endl;
	int wartosc = 0;	
	wartosc = (rand()%(max -(min-1)) ) + min;
	//cout<<"Wylosowana wartosc to: "<<wartosc<<endl<<endl;
	return wartosc;
}

bool init()
{
	//start SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) )
	{
		return false;
	}
	 //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }
	//set up screen
	screen = SDL_SetVideoMode( SZEROKOSC_EKRANU, WYSOKOSC_EKRANU, 32, SDL_SWSURFACE );
	if( screen == NULL )
	{
		return false;
	}
	
	//ustawiamy nazwe okna
	SDL_WM_SetCaption("Wzrost Balistyczny", NULL);
	return true;
}

bool loadFiles()
{
	//load image
	pixel = SDL_LoadBMP("pixel.bmp");
	if( pixel == NULL )
	{
		return false;
	}
	pixel_czerwony = SDL_LoadBMP("pixel_czerwony.bmp");
	if( pixel_czerwony == NULL )
	{
		return false;
	}
	pixel_zielony = SDL_LoadBMP("pixel_zielony.bmp");
	if( pixel_zielony == NULL )
	{
		return false;
	}
	pixel_niebieski = SDL_LoadBMP("pixel_niebieski.bmp");
	if( pixel_niebieski == NULL )
	{
		return false;
	}
	tlo = SDL_LoadBMP("tlo.bmp");
	if( tlo == NULL )
	{
		return false;
	}
	buttonSheet = SDL_LoadBMP("mybutton.bmp");
	if( buttonSheet == NULL )
	{
		return false;
	}
	//Open the font
    font = TTF_OpenFont( "TobagoPoster.ttf", 28 );
	//If there was an error in loading the font
	if( font == NULL )
    {
        return false;
    }
	return true;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}


//Update the screen
void updateScreen()
{
	SDL_Flip( screen );    
}

void sprzataj()
{
	SDL_FreeSurface(pixel);
	SDL_FreeSurface(tlo);
	SDL_FreeSurface(buttonSheet);
	TTF_CloseFont(font);

	TTF_Quit();
	SDL_Quit();
}

bool porownajNapisy(string napis1, string napis2, int ileZnakow){
	int x = 0;
	if( napis1.length() < ileZnakow ){
		return false;
	}
	for( int i=0 ; i<ileZnakow ; i++ ){
		if( napis1.at(i) == napis2.at(i) ){
			x++;
		}
	}
	if( x==ileZnakow){
		return true;//napisy takie same
	}
	return false;//napisy rozne
}
