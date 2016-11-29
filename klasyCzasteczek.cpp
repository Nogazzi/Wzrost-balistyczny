#include "klasyCzasteczek.h"

Czasteczka::Czasteczka()
{
}

Czasteczka::Czasteczka(int x, int y)
{
	this->x = x;
	this->y = y;
	this->kierunek = 0;
	this->ilosc = 1;
	//this->obrazek = pixel;
}
Czasteczka::Czasteczka(int x, int y, int kierunek)
{
	this->x = x;
	this->y = y;
	this->kierunek = kierunek;
	this->ilosc = 1;
}
void Czasteczka::zwiekszIlosc()
{
	this->ilosc++;
}
void Czasteczka::wyswietlCzasteczke()
{
	apply_surface(this->x, this->y, pixel, screen, NULL);
}

void Czasteczka::wyswietlCzasteczkeNaLewo()
{
	apply_surface(this->x-300, this->y, pixel, screen, NULL);
}

void Czasteczka::wyswietlCzasteczkeNaPrawo()
{
	apply_surface(this->x+300, this->y, pixel, screen, NULL);
}

void Czasteczka::wyswietlNaStatystyki()
{
	if( this->ilosc == 1 )
	{
		apply_surface(this->x, this->y, pixel, screen, NULL);
	}
	else if( this->ilosc == 2 )
	{
		apply_surface(this->x, this->y, pixel_niebieski, screen, NULL);
	}
	else if( this->ilosc == 3 )
	{
		apply_surface(this->x, this->y, pixel_zielony, screen, NULL);
	}
	else
	{
		apply_surface(this->x, this->y, pixel_czerwony, screen, NULL);
	}

}
int Czasteczka::getX()
{
	return this->x;
}
int Czasteczka::getY()
{
	return this->y;
}
int Czasteczka::getKierunek(){
	return this->kierunek;
}
void Czasteczka::lec()
{
	if( this->kierunek == 1 )
	{
	//	y++;
		y+= vCzasteczki;
	}
	else if( this->kierunek == 2 )
	{
	//	y--;
		y-=vCzasteczki;
	}
	else if( this->kierunek == 3 )
	{
	//	x--;
		x-=vCzasteczki;
	}
	else if( this->kierunek == 4 )
	{
	//	x++;
		x+=vCzasteczki;
	}
}
void Czasteczka::cofnijCzasteczke()
{
	if( this->kierunek == 1 )
	{
	//	y--;
		y-=vCzasteczki;
	}
	else if( this->kierunek == 2 )
	{
	//	y++;
		y+=vCzasteczki;
	}
	else if( this->kierunek == 3 )
	{
	//	x++;
		x+=vCzasteczki;
	}
	else if( this->kierunek == 4 )
	{
	//	x--;
		x-=vCzasteczki;
	}
}

Czasteczka::~Czasteczka()
{
}


//KONSTRUKTOR DOMYSLNY KLASY ZBIOR(czasteczek)
//tworzy pierwsze cztery czasteczki na srodku ekranu i dodaje je do zbioru
//ustawia liczbe aktualnie przechowywanych czasteczek na wartosc=4
Zbior::Zbior(int n)
{
	this->docelowaIloscCzasteczek = n;
	this->tablicaCzasteczek.push_back( new Czasteczka(SZEROKOSC_EKRANU/2, WYSOKOSC_EKRANU/2) );
	this->tablicaCzasteczek.push_back( new Czasteczka(SZEROKOSC_EKRANU/2 + 1, WYSOKOSC_EKRANU/2) );
	this->tablicaCzasteczek.push_back( new Czasteczka(SZEROKOSC_EKRANU/2, WYSOKOSC_EKRANU/2 + 1) );
	this->tablicaCzasteczek.push_back( new Czasteczka(SZEROKOSC_EKRANU/2 + 1, WYSOKOSC_EKRANU/2 + 1) );	
	this->iloscCzasteczek = 4;
	delty[0] = 0.1;
	delty[1] = 0.2;
	delty[2] = 0.3;
	delty[3] = 0.4;
	delty[4] = 0.5;
	delty[5] = 0.6;
	delty[6] = 0.7;
	delty[7] = 0.8;
	delty[8] = 0.9;
}

Zbior::Zbior( string nazwaPliku, int n )
{
	delty[0] = 0.1;
	delty[1] = 0.2;
	delty[2] = 0.3;
	delty[3] = 0.4;
	delty[4] = 0.5;
	delty[5] = 0.6;
	delty[6] = 0.7;
	delty[7] = 0.8;
	delty[8] = 0.9;
	//otworz plik nazwaPliku
	ifstream plik;
	int x;
	int y;
	int kierunek;
	plik.open(nazwaPliku.c_str());
	plik>>this->docelowaIloscCzasteczek;
	if( n != this->getDocelowaIloscCzasteczek() ){
		perror("Zly plik");
		plik.close();
		;
	}
	for(int i=0 ; i<4 ; i++ ){
		//pierwsze 4 czasteczki
		plik>>x;
		plik>>y;
		this->tablicaCzasteczek.push_back(new Czasteczka(x, y));
	}
	for(int i=0 ; i<this->getDocelowaIloscCzasteczek()-4 && !plik.eof(); i++ ){
		plik>>kierunek;
		plik>>x;
		plik>>y;
		this->tablicaCzasteczek.push_back(new Czasteczka(x, y, kierunek));
	}

	//wczytaj pierwsza wartosc i sprawdz czy jest rowna n
		//jesli nierowna to zamknij plik i anuluj tworzenie obiektu
		//jesli rowna to kontynuuj tworzenie obiektu
			//docelowailoscczasteczek = n
			//wczytaj informacje o ilosci kierunkow czasteczek
			//w petli wczytaj n czasteczek o wspolrzednych x, y
			//

	plik.close();
}
//funkcja zwracajaca ilosc aktualnie przechowywanych czasteczek w zbiorze
int Zbior::getIloscCzasteczek()
{
	return this->iloscCzasteczek;
}
int Zbior::getDocelowaIloscCzasteczek()
{
	return this->docelowaIloscCzasteczek;
}

//FUNKCJA DODAJACA NOWA CZASTECZKE DO ZBIORU
//1.sprawdza ilosc aktualnie przechowywanych czasteczek
//2.zapisuje nowa czasteczke w pierwszym wolnym elemencie tablicy
//3.zwieksza ilosc aktualnie przechowywanych czasteczek o 1
void Zbior::dodajCzasteczke(int xStartu, int yStartu, int kierunek)
{
	Czasteczka* nowaCzasteczka = new Czasteczka( xStartu, yStartu, kierunek );
	//rozpoczecie lotu czasteczki do momentu napotkania kolizji z jednym z obiektow zbioru
	while( !sprawdzKolizje( *nowaCzasteczka ) )
	{
		nowaCzasteczka->lec();
	}
	nowaCzasteczka->cofnijCzasteczke();
	
	int count = this->getIloscCzasteczek();			//getIloscCzasteczek zwraca ilosc aktualnie przechowywanych czasteczek a za razem wartosc odpowiadajaca indeksowi najblizszego pustego pola w tablicy
	this->tablicaCzasteczek.push_back( nowaCzasteczka );
	this->iloscCzasteczek++;		//zwiekszamy o 1 liczbe czasteczek aktualnie przechowywanych w zbiorze
}

//FUNKCJA SPRAWDZA WARTOSC WSPOLRZEDNEJ X CZASTECZKI WYSUNIETEJ NAJBARDZIEJ NA LEWO
int Zbior::getXSkrajnieLewejCzasteczki()
{
	int xTemp;		//zmienna przechowuje wartosc wspolrzednej X czasteczki sprawdzanej przy obecnym przebiegu petli
//	int xMin = xTemp = this->czasteczki[0]->getX();
	int xMin = xTemp = this->tablicaCzasteczek[0]->getX();
	Czasteczka* wskTmp = NULL;
	for( int i=0 ; ( (i<this->getDocelowaIloscCzasteczek()) && (i<this->tablicaCzasteczek.size() ) ) ; i++ )	//w zbiorze czasteczek szukamy tej lezacej najbardziej na lewo(majacej najmniejsza wartosc wspolrzednej X)
	{
		if( (xTemp = /*this->czasteczki[i]->getX()*/ this->tablicaCzasteczek[i]->getX()) < xMin )	//jesli wartosc wspolrzednej X aktualnie sprawdzanej czasteczki jest mniejsza od aktualnego minimalnego X to przypisujemy xMin nowa wartosc(wartosc wspolrzednej X aktualnie sprawdzanej czasteczki)
		{
			xMin = xTemp;	
		}
	}
	//cout<<"X skrajnie lewej czasteczki = "<<xMin<<endl<<endl;
	return xMin;
}

//FUNKCJA SPRAWDZA WARTOSC WSPOLRZEDNEJ X CZASTECZKI WYSUNIETEJ NAJBARDZIEJ NA PRAWO
int Zbior::getXSkrajniePrawejCzasteczki()
{
	int xTemp;		//zmienna przechowuje wartosc wspolrzednej X czasteczki sprawdzanej przy obecnym przebiegu petli
//	int xMax = xTemp = this->czasteczki[0]->getX();
	int xMax = xTemp = this->tablicaCzasteczek[0]->getX();
	for( int i=0 ; ( (i<this->getDocelowaIloscCzasteczek()) && ( i < this->tablicaCzasteczek.size() ) ) ; i++ )	//w zbiorze czasteczek szukamy tej lezacej najbardziej na prawo(majacej najwieksza wartosc wspolrzednej X)
	{
		if( ( xTemp = /*this->czasteczki[i]->getX()*/this->tablicaCzasteczek[i]->getX()) > xMax )		//jesli wartosc wspolrzednej X aktualnie sprawdzanej czasteczki jest wieksza od aktualnego maxymalnego X to przypisujemy xMax nowa wartosc(wartosc wspolrzednej X aktualnie sprawdzanej czasteczki)
		{
			xMax = xTemp;
		}
	}
	//cout<<"X skrajnie prawej czasteczki = "<<xMax<<endl<<endl;
	return xMax;
}

//FUNKCJA SPRAWDZA WARTOSC WSPOLRZEDNEJ Y CZASTECZKI WYSUNIETEJ NAJBARDZIEJ W GORE
int Zbior::getYSkrajnieGornejCzasteczki()
{
	int yTemp;		//zmienna przechowuje wartosc wspolrzednej Y czasteczki sprawdzanej przy obecnym przebiegu petli
//	int yMin = yTemp = this->czasteczki[0]->getY();
	int yMin = yTemp = this->tablicaCzasteczek[0]->getY();
	for( int i=0 ; ( (i<this->getDocelowaIloscCzasteczek()) && ( i< this->tablicaCzasteczek.size() ) ) ; i++ )	//w zbiorze czasteczek szukamy tej lezacej najwyzej na ekranie(majacej najmniejsza wartosc wspolrzednej Y)
	{
		if( ( yTemp = /*this->czasteczki[i]->getY()*/this->tablicaCzasteczek[i]->getY() ) < yMin )		//jesli wartosc wspolrzednej Y aktualnie sprawdzanej czasteczki jest mniejsza od aktualnego minimalnego Y to przypisujemy yMin nowa wartosc(wartosc wspolrzednej Y aktualnie sprawdzanej czasteczki)
		{
			yMin = yTemp;
		}
	}
		//cout<<"Y skrajnie gornej czasteczki = "<<yMin<<endl<<endl;
	return yMin;
}

//FUNKCJA SPRAWDZA WARTOSC WSPOLRZEDNEJ Y CZASTECZKI WYSUNIETEJ NAJBARDZIEJ W DOL
int Zbior::getYSkrajnieDolnejCzasteczki()
{
	int yTemp;		//zmienna przechowuje wartosc wspolrzednej Y czasteczki sprawdzanej przy obecnym przebiegu petli
//	int yMax = yTemp = this->czasteczki[0]->getY();
	int yMax = yTemp = this->tablicaCzasteczek[0]->getY();
	for( int i=0 ; ( (i<this->getDocelowaIloscCzasteczek()) && ( i< this->tablicaCzasteczek.size() ) ) ; i++ )	//w zbiorze czasteczek szukamy tej lezacej najnizej na ekranie(majacej najwieksza wartosc wspolrzednej Y)
	{
		if( ( yTemp = /*this->czasteczki[i]->getY()*/this->tablicaCzasteczek[i]->getY() ) > yMax )		//jesli wartosc wspolrzednej Y aktualnie sprawdzanej czasteczki jest wieksza od aktualnego maxymalnego Y to przypisujemy yMax nowa wartosc(wartosc wspolrzednej Y aktualnie sprawdzanej czasteczki)
		{
			yMax = yTemp;
		}
	}
	//cout<<"Y skrajnie dolnej czasteczki = "<<yMax<<endl<<endl;
	return yMax;
}

//funkcja oblicza ilosc dziur w danym zbiorze i zwraca ja
int Zbior::obliczIloscDziur()
{
	vector<Dziura>tmpListaDziur;
	vector<Dziura>dziuryPion;
	vector<Dziura>dziuryPoziom;
	vector<Dziura>finalListaDziur;
	bool spotkanoCzasteczke;
	bool liczDziury;
	int x;
	int y;
	//skanowanie poziome
	for( y = this->getYSkrajnieGornejCzasteczki() ; y <= this->getYSkrajnieDolnejCzasteczki() ; y++ )
	{
		spotkanoCzasteczke = false;
		liczDziury = false;
		for( x = this->getXSkrajnieLewejCzasteczki() ; x <= this->getXSkrajniePrawejCzasteczki() ; x++ )
		{
			if( this->spotkanoCzasteczke(x, y) == true  )
			{
				if( liczDziury )	//spotkano czasteczke, liczono dziury
				{
					liczDziury = false;
					//przepisz tmplistadziur do dziury poziom
					for( int i=0 ; i<tmpListaDziur.size() ; i++ ){
						dziuryPoziom.push_back(tmpListaDziur[i]);
					}
					tmpListaDziur.clear();	//wyczysc liste tymczasowych dziur
				}else	//spotkano czasteczke, nie liczono dziur
				{
					;	//nic nie rob
				}
			}else	//nie spotkano czasteczki
			{
				if( liczDziury )	//spotkano dziure, liczono dziury
				{
					tmpListaDziur.push_back(Dziura(x, y));	//dodaj dziure do listy tymczasowej
				}else	//spotkano dziure, nie liczono dziur
				{
					liczDziury = true;
					tmpListaDziur.push_back(Dziura(x, y));
				}
			}//koniec if(spotkanoCzasteczke)
		}//koniec for(x)
		tmpListaDziur.clear();
	}//koniec for(y)
	//skanowanie pionowe
	for( int x = this->getXSkrajnieLewejCzasteczki() ; x <= this->getXSkrajniePrawejCzasteczki() ; x++ )
	{
		spotkanoCzasteczke = false;
		liczDziury = false;
		for( int y = this->getYSkrajnieGornejCzasteczki() ; y <= this->getYSkrajnieDolnejCzasteczki() ; y++ )
		{
			if( spotkanoCzasteczke )
			{
				if( liczDziury )
				{
					liczDziury = false;
					//przepisz tmpListaDziur do dziury pion
					for( int i=0 ; i<tmpListaDziur.size() ; i++ )
					{
						dziuryPion.push_back(tmpListaDziur[i]);
					}
					tmpListaDziur.clear();//wczysysc liste tymczasowych dziur
				}
				else	//spotkano czasteczke, nie liczono dziur
				{
					;
				}
			}else	//nie spotkano czasteczki
			{
				if( liczDziury )	//spotkano dziure, liczono dziury
				{
					tmpListaDziur.push_back(Dziura(x,y));	//dodaj dziure do listy tymczasowej
				}else	//spotkano dziure, nie liczono dziur
				{	
					liczDziury = true;
					tmpListaDziur.push_back(Dziura(x, y));
				}
			}
		}//koniec for(y)
		tmpListaDziur.clear();
	}//koniec for(x)
	//zliczanie czesci wspolnej obu skanow
	//liczba czasteczek z czesci wspolnej obu skanow
	int ileDziur = finalListaDziur.size();
	this->iloscDziur = ileDziur;
	return ileDziur;
}
bool Zbior::spotkanoCzasteczke(int x, int y)
{
	for( int i=0 ; i<this->docelowaIloscCzasteczek ; i++ )
	{
		if( (this->tablicaCzasteczek[i]->getX() == x ) && (this->tablicaCzasteczek[i]->getY() == y) )
		{
			return true;
		}
	}
	return false;
}
int Zbior::getSzerokoscZbioru()
{
	int szerokosc;
	szerokosc = this->getXSkrajniePrawejCzasteczki() - this->getXSkrajnieLewejCzasteczki();
	return szerokosc;
}
int Zbior::getWysokoscZbioru()
{
	int wysokosc;
	wysokosc = this->getYSkrajnieDolnejCzasteczki() - this->getYSkrajnieGornejCzasteczki();
	return wysokosc;
}
void Zbior::obliczXSrodka()
{
	this->xSrodka = (( this->getXSkrajnieLewejCzasteczki() + this->getXSkrajniePrawejCzasteczki() ) / 2);
}
void Zbior::obliczYSrodka()
{
	this->ySrodka = (( this->getYSkrajnieGornejCzasteczki() + this->getYSkrajnieDolnejCzasteczki() ) / 2);
}
void Zbior::obliczPolePowierzchni()
{
	int x;
	int y;
	x = this->getSzerokoscZbioru();
	y = this->getWysokoscZbioru();
	this->polePowierzchni = x*y;
}
void Zbior::obliczGestoscCalkowita()
{
	double gestosc;
	gestosc = (double)this->docelowaIloscCzasteczek/(double)this->polePowierzchni;
	this->gestoscCalkowita = gestosc;
}

void Zbior::liczGestosciObszarowe()
{
	this->obliczXSrodka();
	this->obliczYSrodka();
	int liczbaCzasteczek=0;
	double delta;
	double gestosc=0;
	int ogrGorneY;
	int ogrDolneY;
	int ogrLeweX;
	int ogrPraweX;
	int polePowierzchni;
	for( int i=0 ; i<9 ; i++ )
	{
		liczbaCzasteczek = 0;
		delta = this->delty[i];
		ogrGorneY = this->ySrodka - (double)this->getWysokoscZbioru()*delta*0.5;
		ogrDolneY = this->ySrodka + (double)this->getWysokoscZbioru()*delta*0.5;
		ogrLeweX = this->xSrodka - (double)this->getSzerokoscZbioru()*delta*0.5;
		ogrPraweX = this->xSrodka + (double)this->getSzerokoscZbioru()*delta*0.5;
		polePowierzchni = (ogrDolneY-ogrGorneY)*(ogrPraweX-ogrLeweX);
		for( int j=0; j<this->tablicaCzasteczek.size() ; j++ )
		{
			if( (this->tablicaCzasteczek[j]->getX() > ogrLeweX) && (this->tablicaCzasteczek[j]->getX() < ogrPraweX) )
			{
				if( (this->tablicaCzasteczek[j]->getY() > ogrGorneY) && (this->tablicaCzasteczek[j]->getY() < ogrDolneY) )
				{
					liczbaCzasteczek++;
				}
			}
		}
		gestosc = (double)liczbaCzasteczek / (double)polePowierzchni;
		this->gestosci[i] = gestosc;
	}
}


void Zbior::wypiszDane()
{
	for( int i=0 ; (i<this->getDocelowaIloscCzasteczek()) && ( i < this->tablicaCzasteczek.size() ) ; i++ )
	{
		//cout<<"Czasteczka"<<i<<" x="<<this->czasteczki[i]->getX()<<" y="<<this->czasteczki[i]->getY()<<" kierunek="<<this->czasteczki[i]->kierunek<<endl;
	}
}
void Zbior::wyswietlZbior()
{
	for( int i=0; (i<this->getDocelowaIloscCzasteczek()) && ( i < this->tablicaCzasteczek.size() ) ; i++ )
	{
//		this->czasteczki[i]->wyswietlCzasteczke();
		this->tablicaCzasteczek[i]->wyswietlCzasteczke();
	}
}
void Zbior::wyswietlZbiorNaLewo()
{
	for( int i=0 ; (i<this->getDocelowaIloscCzasteczek()) && (i<this->tablicaCzasteczek.size()) ; i++ )
	{
		this->tablicaCzasteczek[i]->wyswietlCzasteczkeNaLewo();
	}
}

void Zbior::wyswietlZbiorNaPrawo()
{
	for( int i=0 ; (i<this->getDocelowaIloscCzasteczek()) && (i<this->tablicaCzasteczek.size()) ; i++ )
	{
		this->tablicaCzasteczek[i]->wyswietlCzasteczkeNaPrawo();
	}
}

//zapis do pliku
void Zbior::zapisdopliku(){ 
	//**************ZAPIS DO PLIKU********************
    //
	//tworzenie folderu o nazwie [ilosc_czasteczek]
	//CreateDirectoryA(s.c_str(), NULL);
   

	this->obliczPolePowierzchni();
	this->obliczGestoscCalkowita();
  DIR *dp;
  int ilosc_plikow=0; //ilosc plikow w folderze 
  struct dirent *ep;     
  dp = opendir ("./");

  if (dp != NULL)
  {
    while (ep = readdir (dp))
      ilosc_plikow++;

    (void) closedir (dp);
  }
  else{
	  perror ("Couldn't open the directory");}

	 ofstream myfile;
     string format = ".txt"; //rozszerzenie pliku
     int numer = ilosc_plikow-35; //35 - pliki projektowe na sztywno
	 stringstream sstm;
     sstm <<  docelowaIloscCzasteczek << "_" << numer << format; //konkatenacja stringa i inta
     string result = sstm.str(); //efekt konkatenacji
	 myfile.open(result.c_str());
	
	
	 if(myfile.is_open()){
		myfile << docelowaIloscCzasteczek <<endl;
		myfile << SZEROKOSC_EKRANU/2 << " "<< WYSOKOSC_EKRANU/2 <<endl; 
		myfile << SZEROKOSC_EKRANU/2 + 1 << " " << WYSOKOSC_EKRANU/2 <<endl;
		myfile << SZEROKOSC_EKRANU/2 << " " << WYSOKOSC_EKRANU/2 + 1 <<endl;
		myfile << SZEROKOSC_EKRANU/2 + 1 << " " << WYSOKOSC_EKRANU/2 + 1 <<endl;
	 
		for( int i=4 ; (i<docelowaIloscCzasteczek)  ; i++ )
			{
				myfile << tablicaCzasteczek[i]->kierunek << " ";
				myfile << tablicaCzasteczek[i]->x<<" ";
				myfile << tablicaCzasteczek[i]->y<<endl;
			
			}
		myfile<<"gestosc calkowita "<<this->gestoscCalkowita<<endl;
		//zapis gestosci obszarowych
		myfile<<"gestosci obszarowe: "<<endl;
		for( int i=0 ; i<9 ; i++ )
		{
			myfile<<this->delty[i]<<" "<<this->gestosci[i]<<endl;
		}
	 }
	 myfile.close();
}
///////////


void Zbior::usunCzasteczki()
{
	for( int i=0 ; i<this->tablicaCzasteczek.size() ; i++ )
	{
		delete this->tablicaCzasteczek[i];
	}
}

Zbior::~Zbior()
{
	/*
	for( int i=0; i<this->getDocelowaIloscCzasteczek() ; i++ )
	{
		this->czasteczki[i]->~Czasteczka();
	}*/
}



bool Zbior::sprawdzKolizje(Czasteczka czasteczka)
{
	for( int i=0 ; (i < this->tablicaCzasteczek.size()) && (i < this->getIloscCzasteczek()) ; i++ )
	{
		if( ( czasteczka.getX() == this->tablicaCzasteczek[i]->getX() ) && ( czasteczka.getY() == this->tablicaCzasteczek[i]->getY() ) )
		{
			return true;
		}
	}
	return false;
}

KolekcjaZbiorow::KolekcjaZbiorow(int n){
	this->liczbaDziur = 0;
	this->iloscZbiorow = 0;
	this->dol=0;
	this->gora=0;
	this->lewo=0;
	this->prawo=0;
	this->liczbaCzasteczek = n;
	this->zrobListePlikow();
	string plik;
	fstream nazwaPliku;
	int x;
	
	for( int i=0 ; i<listaPlikow.size() ; i++ ){
		plik = listaPlikow[i].c_str();
		nazwaPliku.open(plik.c_str());
		nazwaPliku>>x;	
		nazwaPliku.close();
		if( x == n ){
			this->tablicaZbiorow.push_back( new Zbior(plik, this->getLiczbaCzasteczek()) );
			this->iloscZbiorow++;
		}
	}

}
int KolekcjaZbiorow::getIloscZbiorow(){
	return this->iloscZbiorow;
}

int KolekcjaZbiorow::getLiczbaDziur(){
	return this->liczbaDziur;
}

void KolekcjaZbiorow::stworzListeCzasteczek(){
	for( int i=0 ; i<this->getIloscZbiorow() ; i++ )
	{
		for( int j=0 ; j<this->tablicaZbiorow[i]->getDocelowaIloscCzasteczek() ; j++ )
		{
			int x = this->tablicaZbiorow[i]->tablicaCzasteczek[j]->getX();
			int y = this->tablicaZbiorow[i]->tablicaCzasteczek[j]->getY();
			if( this->sprawdzCzyIstniejeNaLiscie(x,y) == false )
			{
				this->listaCzasteczekDoStatystyk.push_back(tablicaZbiorow[i]->tablicaCzasteczek[j]);
				
			}
		}
	}
}

bool KolekcjaZbiorow::sprawdzCzyIstniejeNaLiscie(int x, int y)
{
	for( int i=0 ; i<this->listaCzasteczekDoStatystyk.size() ; i++ )
	{
		if( (this->listaCzasteczekDoStatystyk[i]->getX() == x ) && ( this->listaCzasteczekDoStatystyk[i]->getY() == y ) )
		{
			//inkrementuj ilosc tej czasteczki
			this->listaCzasteczekDoStatystyk[i]->zwiekszIlosc();
			return true;
		}
	}
	return false;
}

int KolekcjaZbiorow::getLiczbeZListyCzasteczek()
{
	return this->listaCzasteczekDoStatystyk.size();
}

void KolekcjaZbiorow::zrobListePlikow(){
	vector<string>listaTmp;
	DIR *dir;
    struct dirent *ent;
    dir = opendir("./");
    if (dir != NULL)
    {
        while ((ent = readdir (dir)) != NULL)
        {
			listaTmp.push_back( ent->d_name );
		}
        closedir(dir);
    }
    else
    {
        printf("Failed to read directory %i", EXIT_FAILURE);
    }
	//wczytano wszystkie pliki/foldery do listy
	//wyberamy dobre pliki
	stringstream sstm;
	sstm<<this->getLiczbaCzasteczek()<<"_";
	string konkatenacja;
	konkatenacja=sstm.str();
	string elementListy;
	for( int i=0 ; i<listaTmp.size() ; i++ ){
		//elementListy=listaTmp[i].c_str();
		if( porownajNapisy(listaTmp[i].c_str(), konkatenacja, konkatenacja.length()-1 ) == true ){
			listaPlikow.push_back(listaTmp[i].c_str());
		}
	}//mamy gotowa liste plikow
	
}

int KolekcjaZbiorow::getLiczbaCzasteczek(){
	return this->liczbaCzasteczek;
}

void KolekcjaZbiorow::wyswietlZbiory(){
	for( int i=0 ; i<this->tablicaZbiorow.size() ; i++ ){
		tablicaZbiorow[i]->wyswietlZbior();
	}
}
void KolekcjaZbiorow::wyswietlZbiorNaLewo(int n)
{
	this->tablicaZbiorow.at(n)->wyswietlZbiorNaLewo();
}
void KolekcjaZbiorow::wyswietlZbiorNaPrawo(int n)
{
	this->tablicaZbiorow.at(n)->wyswietlZbiorNaPrawo();
}

void KolekcjaZbiorow::usunZbiory(){
	for( int i=0 ; i<this->tablicaZbiorow.size() ; i++ ){
		tablicaZbiorow[i]->usunCzasteczki();
	}
	this->tablicaZbiorow.clear();
}

void KolekcjaZbiorow::zliczKierunki(){
	for(int i=0 ; i<this->tablicaZbiorow.size() ; i++ ){
		for( int j=0 ; j<this->tablicaZbiorow[i]->getDocelowaIloscCzasteczek() ; j++ ){
			if( this->tablicaZbiorow[i]->tablicaCzasteczek[j]->getKierunek() == 1 ){	//kierunek == 1 == w dol
				this->dol++;
			}
			else if( this->tablicaZbiorow[i]->tablicaCzasteczek[j]->getKierunek() == 2 ){	//kierunek == 2 == gora
				this->gora++;
			}
			else if( this->tablicaZbiorow[i]->tablicaCzasteczek[j]->getKierunek() == 3 ){//kierunek == 3== lewo
				this->lewo++;
			}
			else if( this->tablicaZbiorow[i]->tablicaCzasteczek[j]->getKierunek() == 4 ){//kierunek == 4 == prawo
				this->prawo++;
			}
		}
	}
}
int KolekcjaZbiorow::getDol(){
	return this->dol;
}
int KolekcjaZbiorow::getGora(){
	return this->gora;
}
int KolekcjaZbiorow::getLewo(){
	return this->lewo;
}
int KolekcjaZbiorow::getPrawo(){
	return this->prawo;
}

void KolekcjaZbiorow::obliczLiczbeDziur(){
	for( int i=0 ; i<this->tablicaZbiorow.size() ; i++ )
	{
		this->liczbaDziur += this->tablicaZbiorow[i]->obliczIloscDziur();
	}
}

void KolekcjaZbiorow::wyswietlNaStatystyki()
{
	for( int i=0 ; i<this->listaCzasteczekDoStatystyk.size() ; i++ )
	{
		this->listaCzasteczekDoStatystyk[i]->wyswietlNaStatystyki();
	}
}



Dziura::Dziura(int x, int y)
{
	this->x = x;
	this->y = y;
}

