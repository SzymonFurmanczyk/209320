/*!
 *\file 
 *\brief Metody klasy Kolejka.
 *
 * Plik zawiera metody klasy Kolejka.
 */

#include "Kolejka.hh"

#include <cstdlib>
#include <iostream>


Kolejka::Kolejka()
{
  straznik_koniec=NULL;
  straznik_poczatek=NULL;
  rozmiar=0;
}


Kolejka::~Kolejka()
{
  while(straznik_poczatek!=NULL)
    {
      straznik_koniec=NULL;
      element * tmp= straznik_poczatek->nastepny;
      delete straznik_poczatek;
      straznik_poczatek=tmp;
    }
}


void Kolejka::push(int wartosc)
{
  element * nowy = new element;
  nowy->kontener = wartosc;
  if(rozmiar==0)
    {
      nowy->nastepny = straznik_koniec;
      straznik_koniec=nowy;
      straznik_poczatek=nowy;
    }
  else
    {
      nowy->nastepny=NULL;
      straznik_koniec->nastepny=nowy;
      straznik_koniec=nowy;
    }
  rozmiar++;
}


int Kolejka::pop()
{
  if(rozmiar!=0)
    {
      int wartosc;
      wartosc=straznik_poczatek->kontener;
      element *tmp=straznik_poczatek;
      straznik_poczatek=straznik_poczatek->nastepny;
      if(rozmiar==1)
	{
	  straznik_koniec=straznik_koniec->nastepny;
	}
      delete tmp;
      rozmiar--;
      return wartosc;
    }
  else
    {
      cout<<"Kolejka jest pusta"<<endl;
      return 0;
    }

}


int Kolejka::size()
{
  return rozmiar;
}







