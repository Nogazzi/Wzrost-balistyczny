#include "klasyEkran.h"

//The button states in the sprite sheet
//const int NIEWCISNIETY = 0; 
//const int WCISNIETY = 1;
//The event structure
extern SDL_Event event;

bool czyZapisac = true;
Symulacja::Symulacja()
{
	this->n = 0;
	this->wyjscie = false;
}

void Symulacja::menuGlowne()
{
		//clip the sprite sheet
	set_clips();
	
	//stworz przyciski	
	Button buttonSymulacja( 30, 20, 160, 60, "Symulacja");
	Button buttonStatystyki( 30, 100, 160, 60, "Statystyki");
	Button buttonCreditsy( 30, 180, 160, 60, "Creditsy");
	Button buttonWyjscie( 30, 260, 160, 60, "Wyjscie");

	//wyswietl przycisk1(NOWA SYMULACJA)
	buttonSymulacja.show();

	//wyswietl przycisk2(POKAZ STATYSTYKI)
	buttonStatystyki.show();
	//wyswietl przycisk3(CREDITSY)
	buttonCreditsy.show();
	//wyswietl przycisk4(WYJDZ Z PROGRAMU)
	buttonWyjscie.show();
	//PETLA GLOWNA FUNKCJI
	while( wyjscie == false )
	{
		//If there's events to handle
        if( SDL_PollEvent( &event ) )
        {
		
			//OBSLUGA ZDARZEN
			//jesli kliknieto przycisk1, wlacz nowaSymluacja()
			buttonSymulacja.handle_events();
				//jesli kliknieto przycisk2, wlacz pokazStatystyki()
			buttonStatystyki.handle_events();
				//jesli kliknieto przycisk3, wlacz creditsy()
			buttonCreditsy.handle_events();
				//jesli kliknieto przycisk4, wyjscie=true
			buttonWyjscie.handle_events();

			//WYNIK OBSLUGI ZDARZEN
			//jesli wybrano przycisk WYJSCIE
			if( buttonWyjscie.getStatus() == true )
			{
				wyjscie = true;
			}
			//jesli wybrano przycisk SYMULACJA
			if( buttonSymulacja.getStatus() == true )
			{
				buttonSymulacja.setStatus(false);
				this->nowaSymulacja();
			}
			//jesli wybrano przycisk STATYSTYKI
			if( buttonStatystyki.getStatus() == true )
			{
				buttonStatystyki.setStatus(false);
				this->statystyki();
			}
			if( buttonCreditsy.getStatus() == true )
			{
				buttonCreditsy.setStatus(false);
				this->creditsy();
			}


			 //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                wyjscie = true;
            }
		}
		
			//WYSWIETLENIE TLA
			//Fill the screen white
		    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
			apply_surface(0, 0, tlo, screen, NULL);
			//WYSWIETLENIE PRZYCISKOW
			//wyswietl przycisk1(NOWA SYMULACJA)
			buttonSymulacja.show();
			//wyswietl przycisk2(POKAZ STATYSTYKI)
			buttonStatystyki.show();
			//wyswietl przycisk3(CREDITSY)
			buttonCreditsy.show();
			//wyswietl przycisk4(WYJDZ Z PROGRAMU)
			buttonWyjscie.show();

			updateScreen();
		
	}
	return;
}

void Symulacja::nowaSymulacja()
{
	
	//clip the sprite sheet
	set_clips();
	
	//stworz przyciski	
	Button button10K( 30, 440, 160, 60, "10 000");
	Button button50K( 30, 520, 160, 60, "50 000");
	Button button100K( 30, 600, 160, 60, "100 000");
	Button button500K( 30, 680, 160, 60, "500 000");
	Button buttonCofnij(220, 680, 160, 60, "Cofnij");
	//wyswietl przycisk1( 10K )
	button10K.show();
	//wyswietl przycisk2( 50K )
	button50K.show();
	//wyswietl przycisk3( 100K )
	button100K.show();
	//wyswietl przycisk4( 500K )
	button500K.show();
	//wyswietl przyciski5( cofnij do menu glownego )
	buttonCofnij.show();
	//PETLA GLOWNA FUNKCJI
	while( wyjscie == false )
	{
		//If there's events to handle
        if( SDL_PollEvent( &event ) )
        {
		
			//OBSLUGA ZDARZEN
			//jesli kliknieto przycisk1, wlacz nowaSymluacja()
			button10K.handle_events();
				//jesli kliknieto przycisk2, wlacz pokazStatystyki()
			button50K.handle_events();
				//jesli kliknieto przycisk3, wlacz creditsy()
			button100K.handle_events();
				//jesli kliknieto przycisk4, wyjscie=true
			button500K.handle_events();
			
			buttonCofnij.handle_events();

			//WYNIK OBSLUGI ZDARZEN
			if( buttonCofnij.getStatus() == true )
			{
				buttonCofnij.setStatus(false);
				return;
			}
			//uzytkownik kliknal symulacje 10K
			if( button10K.getStatus() == true )
			{
				button10K.setStatus(false);
				startSymulacji(10000);
				/////////////////////////////////////kaspodhiasuohfioasjofaosfa////////////
			}
			//uzytkownik kliknal symulacje 50K
			if( button50K.getStatus() == true )
			{
				button50K.setStatus(false);
				startSymulacji(50000);
			}
			//uzytkownik kliknal symulacje 100K
			if( button100K.getStatus() == true )
			{
				button100K.setStatus(false);
				startSymulacji(100000);
			}
			//uzytkownik kliknal symulacje 500K
			if( button500K.getStatus() == true )
			{
				button500K.setStatus(false);
				startSymulacji(500000);
			}

			 //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                wyjscie = true;
            }
		}
		
			//WYSWIETLENIE TLA
			//Fill the screen white
		    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
			apply_surface(0, 0, tlo, screen, NULL);
			//WYSWIETLENIE PRZYCISKOW
			//wyswietl przycisk1(NOWA SYMULACJA)
			button10K.show();
			//wyswietl przycisk2(POKAZ STATYSTYKI)
			button50K.show();
			//wyswietl przycisk3(CREDITSY)
			button100K.show();
			//wyswietl przycisk4(WYJDZ Z PROGRAMU)
			button500K.show();
			//wysiwtl przycisk5( cofnij do menu glownego)
			buttonCofnij.show();

			updateScreen();
	}
	
}

void Symulacja::startSymulacji(int n)
{
	Uint32 start;
	clock_t czasStart;
	clock_t czasKoniec;
	czyZapisac = true;
	

	//zbior przechowujacy kolekcje czasteczek
	Zbior* zbiorek1 = new Zbior(n);		

	srand(time(NULL));

//Czasteczka* czasteczkaTemp;
	int kierunek = 0;
	int xMinStartu; int xMaxStartu;		//przedzial mozliwych wspolrzednych X dla miejsca startu
	int yMinStartu; int yMaxStartu;		//przedzial mozliwych wspolrzednych Y dla miejsca startu
	int xStartu;	//wspolrzedna X miejsca pojawienia sie nowej czasteczki
	int yStartu;	//wspolrzedna Y miejsca pojawienia sie nowej czasteczki
	int wDol=0;
	int wGore=0;
	int wLewo=0;
	int wPrawo=0;

	//button wlaczenia pauzy
	Button buttonPauza(850, 690, 160, 60, "Pauza");
	//wlaczenie timera
	start = SDL_GetTicks();

	//licznik petli (d¹¿y do wartoœci zapisanej w parametrze 'n')
	int i=4;
	//PETLA GLOWNA FUNKCJI 
	while( (wyjscie == false) && (zbiorek1->getIloscCzasteczek() <= n) && (i<=n) )
	{
		//OBSLUGA ZDARZEN
		//If there's events to handle
        if( SDL_PollEvent( &event ) )
        {
			buttonPauza.handle_events();
			//jesli kliknieto przycisk pauzy
			if( buttonPauza.getStatus() == true )
			{
				
				buttonPauza.setStatus(false);
				pauza();
			}
			//If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                wyjscie = true;
				czyZapisac=false;
            }
		}
		
		//DODANIE NOWEGO ELEMENTU(CZASTECZKI) ZBIORU
		kierunek = losujZPrzedzialu(1, 4);
		if( kierunek == 1 )		//czasteczka pojawi sie nad zbiorem i bedzie sie ruszac w dol
		{
			xMinStartu = zbiorek1->getXSkrajnieLewejCzasteczki();	//wartosc wspolrzednej X padajacej na najbardziej wysunieta na lewo czastke w zbiorze
			xMaxStartu = zbiorek1->getXSkrajniePrawejCzasteczki();	//wartosc wspolrzednej X padajacej na najbardziej wysunieta na lewo czastke w zbiorze
			xStartu = losujZPrzedzialu( xMinStartu, xMaxStartu );	//losuje wspolrzedna X nowej czasteczki zawierajaca sie w przedziale najbardziej wysunietych na lewo i prawo czasteczek przechowywanych w zbiorze
			yStartu = zbiorek1->getYSkrajnieGornejCzasteczki();		//Y gornej czasteczki potrzebny do ustalenia odleglosci nowej tworzonej czasteczki od zbioru 
			yStartu -= 20;
			wDol++;
			//czasteczkaTemp = new Czasteczka( xStartu, yStartu, kierunek );	//tworze nowa czasteczke o okreslonych poczatkowych wspolrzednych X i Y oraz kierunku lotu skierowanego w strone zbioru
		
		}
		else if( kierunek == 2 )	//czasteczka pojawi sie pod zbiorem i bedzie sie ruszac w gore
		{
			xMinStartu = zbiorek1->getXSkrajnieLewejCzasteczki();
			xMaxStartu = zbiorek1->getXSkrajniePrawejCzasteczki();
			xStartu = losujZPrzedzialu( xMinStartu, xMaxStartu );
			yStartu = zbiorek1->getYSkrajnieDolnejCzasteczki();
			yStartu += 20;
			wGore++;
			//czasteczkaTemp = new Czasteczka( xStartu, yStartu, kierunek );
		}
		else if( kierunek == 3 )	//czasteczka pojawi sie po prawej stronie zbioru i bedzie sie ruszac w lewo
		{
			yMinStartu = zbiorek1->getYSkrajnieGornejCzasteczki();
			yMaxStartu = zbiorek1->getYSkrajnieDolnejCzasteczki();
			yStartu = losujZPrzedzialu( yMinStartu, yMaxStartu );
			xStartu = zbiorek1->getXSkrajniePrawejCzasteczki();
			xStartu += 20;
			wLewo++;
		}
		else if( kierunek == 4 )	//czasteczka pojawi sie po prawej stronie zbioru i bedzie sie ruszac w prawo
		{
			yMinStartu = zbiorek1->getYSkrajnieGornejCzasteczki();
			yMaxStartu = zbiorek1->getYSkrajnieDolnejCzasteczki();
			yStartu = losujZPrzedzialu( yMinStartu, yMaxStartu );
			xStartu = zbiorek1->getXSkrajnieLewejCzasteczki();
			xStartu -= 20;
			wPrawo++;
		}
		zbiorek1->dodajCzasteczke(xStartu, yStartu, kierunek);	
		//wrzuc tlo na ekran
		SDL_FillRect(screen, NULL, 0x000000);
		zbiorek1->wyswietlZbior();
	
		//WYSWIETLANIE CZASU PRACY PROGRAMU
		//czas wyswietlany jako napis
		stringstream time;
		//konwersja czasu do string
		time << "Timer: " << SDL_GetTicks() - start;
		//renderuj powierzchnie seconds
		seconds = TTF_RenderText_Solid( font, time.str().c_str(), textColor);
		//wrzuc powierzchnie second na ekran
		apply_surface( 50, 50, seconds, screen, NULL);
		//zwolnij powierzchnie seconds
		SDL_FreeSurface(seconds);
		//WYWIETLANIE LICZBY CZASTECZEK
		//liczba czasteczek wyswietlana jako napis
		stringstream ssiloscCzasteczek;
		double procent = ((double)zbiorek1->getIloscCzasteczek()/zbiorek1->getDocelowaIloscCzasteczek())*100;
		ssiloscCzasteczek << "Liczba czasteczek: "<< zbiorek1->getIloscCzasteczek()<<" /"<<zbiorek1->getDocelowaIloscCzasteczek()<<" ("<<procent<<"%)" ;
		liczbaCzasteczek = TTF_RenderText_Solid(font, ssiloscCzasteczek.str().c_str(), textColor);
		//wrzuc powierzchnie LiczbaCzasteczek na ekran
		apply_surface( 50, 100, liczbaCzasteczek, screen, NULL);
		//zwolnij powierzchnie liczbaCzasteczek
		SDL_FreeSurface(liczbaCzasteczek);
		
		

		//wyswetl przycisk pauzy
		buttonPauza.show();
		//wyswietl interfejs symulacji

			
		//update screen
		updateScreen();
		i++;
		//zapisz symulacje
		
	}//KONIEC GLOWNEJ  PETLI WHILE
	zbiorek1->liczGestosciObszarowe();
	if( czyZapisac == true ){
		zbiorek1->zapisdopliku();
	}
	zbiorek1->usunCzasteczki();
	delete zbiorek1;
}

void Symulacja::pauza()
{
	set_clips();
	Button buttonKontynuuj(500, 300, 160, 60, "Kontunuuj");
	Button buttonWyjdzDoMenu(500, 380, 160, 60, "Wyjdz do menu");
	Button buttonWyjdzZProgramu(500, 460, 160, 60, "Wyjscie z programu");
	//wyswietl przyciski
	buttonKontynuuj.show();
	buttonWyjdzDoMenu.show();
	buttonWyjdzZProgramu.show();
	while( wyjscie == false )
	{
		//OBSLUGA ZDARZEN
		//If there's events to handle
        if( SDL_PollEvent( &event ) )
        {
			buttonKontynuuj.handle_events();
			buttonWyjdzDoMenu.handle_events();
			buttonWyjdzZProgramu.handle_events();
			//jesli uzytkownik kliknal kontynuuj
			if( buttonKontynuuj.getStatus() == true )
			{
				buttonKontynuuj.setStatus(false);
				return;
			}
			//jesli uzytkownik kliknal wyjscie do menu glownego
			if( buttonWyjdzDoMenu.getStatus() == true )
			{
				buttonWyjdzDoMenu.setStatus(false);
				return;
			}
			//jesli uzytwkonik kliknal wyjscie z programu
			if( buttonWyjdzZProgramu.getStatus() == true )
			{
				czyZapisac = false;
				buttonWyjdzZProgramu.setStatus(false);
				wyjscie = true;
			}
			//If the user has Xed out the window
			if( event.type == SDL_QUIT )
			{
			    //Quit the program
				wyjscie = true;
			}
		}
		buttonKontynuuj.show();
		buttonWyjdzDoMenu.show();
		buttonWyjdzZProgramu.show();
		updateScreen();
	}
	//wyswietl przycisk2, wyjdzDoMenu

	//wyswietl przycisk3, wyjdzZprogramu

	//PETLA GLOWNA FUNKCJI
	
}

void Symulacja::statystyki()
{
	//clip the sprite sheet
	set_clips();
	
	//stworz przyciski	
	Button button10K( 30, 440, 160, 60, "10 000");
	Button button50K( 30, 520, 160, 60, "50 000");
	Button button100K( 30, 600, 160, 60, "100 000");
	Button button500K( 30, 680, 160, 60, "500 000");
	Button buttonCofnij(220, 680, 160, 60, "Cofnij");
	//wyswietl przycisk1( 10K )
	button10K.show();
	//wyswietl przycisk2( 50K )
	button50K.show();
	//wyswietl przycisk3( 100K )
	button100K.show();
	//wyswietl przycisk4( 500K )
	button500K.show();
	//wyswietl przyciski5( cofnij do menu glownego )
	buttonCofnij.show();
	//PETLA GLOWNA FUNKCJI
	while( wyjscie == false )
	{
		//If there's events to handle
        if( SDL_PollEvent( &event ) )
        {
		
			//OBSLUGA ZDARZEN
			//jesli kliknieto przycisk1, wlacz nowaSymluacja()
			button10K.handle_events();
				//jesli kliknieto przycisk2, wlacz pokazStatystyki()
			button50K.handle_events();
				//jesli kliknieto przycisk3, wlacz creditsy()
			button100K.handle_events();
				//jesli kliknieto przycisk4, wyjscie=true
			button500K.handle_events();
			
			buttonCofnij.handle_events();

			//WYNIK OBSLUGI ZDARZEN
			if( buttonCofnij.getStatus() == true )
			{
				buttonCofnij.setStatus(false);
				return;
			}
			if( button10K.getStatus() == true )
			{
				button10K.setStatus(false);
				this->pokazStatystykiV2(10000);
			}
			if( button50K.getStatus() == true )
			{
				button50K.setStatus(false);
				this->pokazStatystyki(50000);
			}
			if( button100K.getStatus() == true )
			{
				button100K.setStatus(false);
				this->pokazStatystyki(100000);
			}
			if( button500K.getStatus() == true )
			{
				button500K.setStatus(false);
				this->pokazStatystyki(500000);
			}
			

			 //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                wyjscie = true;
            }
		}
		
			//WYSWIETLENIE TLA
			//Fill the screen white
		    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
			apply_surface(0, 0, tlo, screen, NULL);
			//WYSWIETLENIE PRZYCISKOW
			//wyswietl przycisk1(NOWA SYMULACJA)
			button10K.show();
			//wyswietl przycisk2(POKAZ STATYSTYKI)
			button50K.show();
			//wyswietl przycisk3(CREDITSY)
			button100K.show();
			//wyswietl przycisk4(WYJDZ Z PROGRAMU)
			button500K.show();
			//wysiwtl przycisk5( cofnij do menu glownego)
			buttonCofnij.show();

			updateScreen();
		
		//obsluz zdarzenia tzn:

			//jesli kliknieto przycisk1, wlacz startSymulacji(10)

			//jesli kliknieto przycisk2, wlacz startSymulacji(50)

			//jesli kliknieto przycisk3, wlacz startSymulacji(100)

			//jesli kliknieto przycisk4, wlacz startSymulacji(500)

			//jesli kliknieto przycisk5, cofnij( break; )

			//jesli kliknieto X, wyjscie=true

		
		//wyswietl przycisk1( 10K )

		//wyswietl przycisk2( 50K )

		//wyswietl przycisk3( 100K )

		//wyswietl przycisk4( 500K )

	}
}

void Symulacja::pokazStatystyki(int n)
{
	SDL_Surface* kierunki = NULL;
	SDL_Surface* liczbaElementow = NULL;
	SDL_Surface* komunikat1 = NULL;
	SDL_Surface* komunikat2 = NULL;
	SDL_Surface* komunikatDziury = NULL;
	SDL_Surface* komunikatIloscCzasteczek = NULL;
	SDL_Surface* maxEl = NULL;
	bool wyjscie = false;
	//wczytaj dane z plikow
	KolekcjaZbiorow* kolekcja = new KolekcjaZbiorow(n);
	kolekcja->stworzListeCzasteczek();
	//kolekcja->obliczLiczbeDziur();

	
	Button buttonWyjdz(850, 690, 160, 60, "Wyjdz");

	//przepisanie zbioru do tablicy
	stringstream kierunkiStatsy;
	int dol, gora, prawo, lewo;
	stringstream elementy;
	
	//wyswietl przycisk1(wyjdz)
	stringstream komunikatBledu1;
	stringstream komunikatBledu2;
	stringstream liczbaDziur;
	
	stringstream iloscCzasteczek;
	iloscCzasteczek<<"Calkowita liczba czasteczek: "<<kolekcja->getLiczbeZListyCzasteczek();
	komunikatIloscCzasteczek = TTF_RenderText_Solid(font, iloscCzasteczek.str().c_str(), textColor);

	if( kolekcja->getIloscZbiorow() <= 0 )
	{
		komunikatBledu1<<"Brak plikow do zaladowania symulacji!!!";
		komunikatBledu2<<"Najpierw przeprowadz symulacje dla "<<n<<" elementow.";
		komunikat1 = TTF_RenderText_Solid(font, komunikatBledu1.str().c_str(), textColor);
		komunikat2 = TTF_RenderText_Solid(font, komunikatBledu2.str().c_str(), textColor);
				while( wyjscie == false )
		{
			if( SDL_PollEvent( &event ) )
			{
				buttonWyjdz.handle_events();
				//jesli kliknieto WYJDZ
				if( buttonWyjdz.getStatus() == true )
				{
					buttonWyjdz.setStatus(false);
					wyjscie = true;
				}
				//jesli kliknieto X
				if( event.type == SDL_QUIT )
				{
					wyjscie = true;
				}
			}
			//wyswietlanie
			SDL_FillRect(screen, NULL, 0x000000);
			apply_surface( 30, 200, komunikat1, screen, NULL);
			apply_surface( 30, 250, komunikat2, screen, NULL);
			//apply_surface( 30, 350, komunikatDziury, screen, NULL);
			buttonWyjdz.show();
			updateScreen();
		}//koniec while
	}//koniec if
	else{
		//wyswietl statystyki
		int liczbaZbiorow = kolekcja->getIloscZbiorow();
		kolekcja->zliczKierunki();
		dol = kolekcja->getDol() / kolekcja->getIloscZbiorow();
		gora = kolekcja->getGora() / kolekcja->getIloscZbiorow();
		lewo = kolekcja->getLewo() / kolekcja->getIloscZbiorow();
		prawo = kolekcja->getPrawo() / kolekcja->getIloscZbiorow();
		int wszystkieKierunki = dol+gora+prawo+lewo;
		kierunkiStatsy<<"Gora: "<<gora<<"("<<((gora*100/wszystkieKierunki))<<"%)"
			<<" Dol: "<<dol<<"("<<((dol*100/wszystkieKierunki))<<"%)"
			<<" Prawo: "<<prawo<<"("<<((prawo*100/wszystkieKierunki))<<"%)"
			<<" Lewo: "<<lewo<<"("<<((lewo*100/wszystkieKierunki))<<"%)";
		kierunki = TTF_RenderText_Solid(font, kierunkiStatsy.str().c_str(), textColor);
		elementy<<"Liczba zbiorow branych do statystyki: "<<liczbaZbiorow;
		liczbaElementow = TTF_RenderText_Solid(font, elementy.str().c_str(), textColor);
		
		//int dziury = kolekcja->getLiczbaDziur() / kolekcja->getIloscZbiorow();
		//liczbaDziur<<"Srednia ilosc dziur: "<<dziury<<" / "<<n;
		//komunikatDziury = TTF_RenderText_Solid(font, liczbaDziur.str().c_str(), textColor);

		while( wyjscie == false )
		{
			//If there's events to handle
			if( SDL_PollEvent( &event ) )
			{			
				//OBSLUGA ZDARZEN
				//jesli kliknieto przycisk1, wlacz nowaSymluacja()
				buttonWyjdz.handle_events();


				//WYNIK OBSLUGI ZDARZEN
				if( buttonWyjdz.getStatus() == true )
				{
					buttonWyjdz.setStatus(false);
					wyjscie = true;
				}

				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
				{
				    //Quit the program
				    wyjscie = true;
				}
			}	//koniec if
			//WYSWIETLENIE TLA
			//Fill the screen white
			//SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
			SDL_FillRect(screen, NULL, 0x000000);
			//apply_surface(0, 0, tlo, screen, NULL);
			buttonWyjdz.show();
			//kolekcja->wyswietlZbiory();
			kolekcja->wyswietlNaStatystyki();
			//wrzuc powierzchnie LiczbaCzasteczek na ekran
			apply_surface( 30, 20, kierunki, screen, NULL);
			apply_surface( 30, 60, liczbaElementow, screen, NULL);
			apply_surface( 30, 100, komunikatIloscCzasteczek, screen, NULL);
			updateScreen();	
		}//koniec while
	}//koniec else
	kolekcja->usunZbiory();
	return;
}

void Symulacja::pokazStatystykiV2(int n)
{
	SDL_Surface* kierunki = NULL;
	SDL_Surface* liczbaElementow = NULL;
	SDL_Surface* komunikat1 = NULL;
	SDL_Surface* komunikat2 = NULL;
	SDL_Surface* komunikatDziury = NULL;
	SDL_Surface* komunikatIloscCzasteczek = NULL;
	SDL_Surface* maxEl = NULL;
	bool wyjscie = false;
	int zbior1;
	int zbior2;
	//wczytaj dane z plikow
	KolekcjaZbiorow* kolekcja = new KolekcjaZbiorow(n);
	kolekcja->stworzListeCzasteczek();
	//kolekcja->obliczLiczbeDziur();

	
	
	Button buttonWyjdz(850, 690, 160, 60, "Wyjdz");

	//przepisanie zbioru do tablicy
	stringstream kierunkiStatsy;
	int dol, gora, prawo, lewo;
	stringstream elementy;
	
	//wyswietl przycisk1(wyjdz)
	stringstream komunikatBledu1;
	stringstream komunikatBledu2;
	stringstream liczbaDziur;
	
	stringstream iloscCzasteczek;
	iloscCzasteczek<<"Calkowita liczba czasteczek: "<<kolekcja->getLiczbeZListyCzasteczek();
	komunikatIloscCzasteczek = TTF_RenderText_Solid(font, iloscCzasteczek.str().c_str(), textColor);

	if( kolekcja->getIloscZbiorow() <= 0 )
	{
		komunikatBledu1<<"Brak plikow do zaladowania symulacji!!!";
		komunikatBledu2<<"Najpierw przeprowadz symulacje dla "<<n<<" elementow.";
		komunikat1 = TTF_RenderText_Solid(font, komunikatBledu1.str().c_str(), textColor);
		komunikat2 = TTF_RenderText_Solid(font, komunikatBledu2.str().c_str(), textColor);
				while( wyjscie == false )
		{
			if( SDL_PollEvent( &event ) )
			{
				buttonWyjdz.handle_events();
				//jesli kliknieto WYJDZ
				if( buttonWyjdz.getStatus() == true )
				{
					buttonWyjdz.setStatus(false);
					wyjscie = true;
				}
				//jesli kliknieto X
				if( event.type == SDL_QUIT )
				{
					wyjscie = true;
				}
			}
			//wyswietlanie
			SDL_FillRect(screen, NULL, 0x000000);
			apply_surface( 30, 200, komunikat1, screen, NULL);
			apply_surface( 30, 250, komunikat2, screen, NULL);
			//apply_surface( 30, 350, komunikatDziury, screen, NULL);
			buttonWyjdz.show();
			updateScreen();
		}//koniec while
	}//koniec if
	else{
		zbior1 = losujZPrzedzialu( 0, kolekcja->getIloscZbiorow()-1 );
		do{
			zbior2 = losujZPrzedzialu( 0, kolekcja->getIloscZbiorow()-1 );
		}while( zbior2 == zbior1 );
		//wyswietl statystyki
		int liczbaZbiorow = kolekcja->getIloscZbiorow();
		kolekcja->zliczKierunki();
		dol = kolekcja->getDol() / kolekcja->getIloscZbiorow();
		gora = kolekcja->getGora() / kolekcja->getIloscZbiorow();
		lewo = kolekcja->getLewo() / kolekcja->getIloscZbiorow();
		prawo = kolekcja->getPrawo() / kolekcja->getIloscZbiorow();
		int wszystkieKierunki = dol+gora+prawo+lewo;
		kierunkiStatsy<<"Gora: "<<gora<<"("<<((gora*100/wszystkieKierunki))<<"%)"
			<<" Dol: "<<dol<<"("<<((dol*100/wszystkieKierunki))<<"%)"
			<<" Prawo: "<<prawo<<"("<<((prawo*100/wszystkieKierunki))<<"%)"
			<<" Lewo: "<<lewo<<"("<<((lewo*100/wszystkieKierunki))<<"%)";
		kierunki = TTF_RenderText_Solid(font, kierunkiStatsy.str().c_str(), textColor);
		elementy<<"Liczba zbiorow branych do statystyki: "<<liczbaZbiorow;
		liczbaElementow = TTF_RenderText_Solid(font, elementy.str().c_str(), textColor);
		
		//int dziury = kolekcja->getLiczbaDziur() / kolekcja->getIloscZbiorow();
		//liczbaDziur<<"Srednia ilosc dziur: "<<dziury<<" / "<<n;
		//komunikatDziury = TTF_RenderText_Solid(font, liczbaDziur.str().c_str(), textColor);

		while( wyjscie == false )
		{
			//If there's events to handle
			if( SDL_PollEvent( &event ) )
			{			
				//OBSLUGA ZDARZEN
				//jesli kliknieto przycisk1, wlacz nowaSymluacja()
				buttonWyjdz.handle_events();


				//WYNIK OBSLUGI ZDARZEN
				if( buttonWyjdz.getStatus() == true )
				{
					buttonWyjdz.setStatus(false);
					wyjscie = true;
				}

				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
				{
				    //Quit the program
				    wyjscie = true;
				}
			}	//koniec if
			//WYSWIETLENIE TLA
			//Fill the screen white
			//SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
			SDL_FillRect(screen, NULL, 0x000000);
			//apply_surface(0, 0, tlo, screen, NULL);
			buttonWyjdz.show();
			//kolekcja->wyswietlZbiory();
			kolekcja->wyswietlNaStatystyki();
			//wyswietlenie zbioru na lewo od glownego
			kolekcja->wyswietlZbiorNaLewo(zbior1);
			//wyswietlenie zbioru na prawo od glownego
			kolekcja->wyswietlZbiorNaPrawo(zbior2);
			//wrzuc powierzchnie LiczbaCzasteczek na ekran
			apply_surface( 30, 20, kierunki, screen, NULL);
			apply_surface( 30, 60, liczbaElementow, screen, NULL);
			apply_surface( 30, 100, komunikatIloscCzasteczek, screen, NULL);
			updateScreen();	
		}//koniec while
	}//koniec else
	kolekcja->usunZbiory();
	return;
}

void Symulacja::creditsy()
{
	SDL_Surface* uczelnia = NULL;
	SDL_Surface* projekt = NULL;
	SDL_Surface* autorzy = NULL;
	SDL_Surface* version = NULL;
	SDL_Surface* tytul = NULL;
	
	//tytul projektu
	stringstream tytulStr;
	tytulStr<<"Tytul projektu: Symulacja wzrostu balistycznego";
	tytul = TTF_RenderText_Solid(font, tytulStr.str().c_str(), textColor);
	//version
	stringstream versionStr;
	versionStr<<"Version: 1.0";
	version = TTF_RenderText_Solid(font, versionStr.str().c_str(), textColor);

	//uczelnia
	stringstream uczelniaStr;
	uczelniaStr<<"Uniwersytet Kardynala Stefana Wyszyñskiego w Warszawie";
	uczelnia = TTF_RenderText_Solid(font, uczelniaStr.str().c_str(), textColor);

	//autorzy
	stringstream autorzyStr;
	autorzyStr<<"Autorzy: Pawel Noganski, Mateusz Polec";
	autorzy = TTF_RenderText_Solid(font, autorzyStr.str().c_str(), textColor);
	
	
	//wyswietl informacje o tworcach
	Button buttonCofnij(850, 690, 160, 60, "Cofnij");
	
	while( wyjscie == false )
	{
		//obsluz zdarzenia tzn:
		if( SDL_PollEvent( &event ) )
		{
			buttonCofnij.handle_events();



			if( buttonCofnij.getStatus() == true )
			{
				buttonCofnij.setStatus(false);
				return;
			}
			if( event.type == SDL_QUIT )
			{
				wyjscie = true;
			}

		}
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
		apply_surface(0, 0, tlo, screen, NULL);
		apply_surface( 30, 20, uczelnia, screen, NULL);
		apply_surface( 30, 80, tytul, screen, NULL);
		apply_surface( 30, 150, autorzy, screen, NULL);
		apply_surface( 20, 700, version, screen, NULL);
		buttonCofnij.show();
		updateScreen();
	}
	return;
}


Button::Button(int x, int y, int w, int h, string napis)
{
	//ustawiamy atrybuty przycisku
	box.x = x;
	box.y = y;
	box.w = w;
	box.h = h;
	this->napis = napis;
	this->czyWcisniety = false;

	//wczytujemy domyslny sprite
	clip = &clips[NIEWCISNIETY];
}

bool Button::getStatus()
{
	return this->czyWcisniety;
}

void Button::setStatus( bool stan )
{
	this->czyWcisniety = stan;
}
void Button::handle_events()
{
	//offsety myszy
	int x = 0;
	int y = 0;

	//jesli poruszono kursorem
	if( event.type == SDL_MOUSEMOTION )
	{
		//pobierz offsety dla kursora
		x = event.motion.x;
		y = event.motion.y;
	
		//jesli kursor jest nad przyciskiem
		if( (x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h )  )
		{
			//wczytaj sprite kursora
			clip = &clips[NIEWCISNIETY];
		}//jesli kursor nie jest nad przyciskiem
		else
		{
			//wczytaj sprite kursora
			clip = &clips[NIEWCISNIETY];
		}
	
	}

	//jesli wcisnieto przycisk
	if( event.type == SDL_MOUSEBUTTONDOWN )
	{
		//jesli wcisnieto lewy przycisk
		if( event.button.button == SDL_BUTTON_LEFT )
		{
			//wczytaj offsety myszy
			x = event.button.x;
			y = event.button.y;

			//jesli kursor jest poza przyciskiem
			if( (x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h) )
			{
				//wczytaj sprite przycisku
				clip = &clips[WCISNIETY];
				this->czyWcisniety = true;
			}
		}
	}
	//jesli zwolniono przycisk
	if( event.type == SDL_MOUSEBUTTONUP )
	{
		//jesli zwolniono lewy przycisk myszy
		if( event.button.button == SDL_BUTTON_LEFT )
		{
			//wczytujemy offsety
			x = event.button.x;
			y = event.button.y;
			
			//jesli kursor jest poza przyciskiem
			if( (x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h) )
			{
				//wczytaj sprite przycisku
				clip = &clips[NIEWCISNIETY];
				this->czyWcisniety = false;
			}
			
		}
	}
}

void Button::show()
{
	SDL_Surface* tmpButton = NULL;
	SDL_Surface* tmpNapis = NULL;;
	tmpNapis = TTF_RenderText_Solid(font, this->napis.c_str(), textColor);
//	apply_surface( box.x, box.y, buttonSheet, screen, clip);
	apply_surface( box.x, box.y, buttonSheet, screen, clip);
	apply_surface( box.x+15, box.y+15, tmpNapis, screen, NULL);
	SDL_FreeSurface(tmpButton);
	SDL_FreeSurface(tmpNapis);
}



void set_clips()
{
	//clip the sprite sheet
	clips[NIEWCISNIETY].x = 0;
	clips[NIEWCISNIETY].y = 0;
	clips[NIEWCISNIETY].w = 160;
	clips[NIEWCISNIETY].h = 60;

	clips[WCISNIETY].x = 0;
	clips[WCISNIETY].y = 60;
	clips[WCISNIETY].w = 160;
	clips[WCISNIETY].h = 60;
}


