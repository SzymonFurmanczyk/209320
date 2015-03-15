/*!
 *\file 
 *\brief Metody klasy Kolejka.
 *
 * Plik zawiera metody klasy Kolejka.
 */

#include "Kolejka.hh"

#include <cstdlib>
#include <iostream>

/*!
 *\brief Konstruktor bezparametryczny.
 *       Konstruktor inicjalizujacy straznika 
 *       listy wartoscia NULL.
 */
Kolejka::Kolejka()
{
  straznik_glowa=NULL;
  straznik_ogon=NULL;
  rozmiar=0;
}

/*!
 *\brief Destruktor bezparametryczny.
 */
Kolejka::~Kolejka()
{
  while(straznik_ogon!=NULL)
    {
      straznik_glowa=NULL;
      element * tmp= straznik_ogon->nastepny;
      delete straznik_ogon;
      straznik_ogon=tmp;
    }
}

/*!
 *\brief 
 */
void Kolejka::push(int wartosc)
{
  element * nowy = new element;
  nowy->kontener = wartosc;
  if(rozmiar==0)
    {
      nowy->nastepny = straznik_glowa;
      straznik_glowa=nowy;
      straznik_ogon=nowy;
    }
  else
    {
      nowy->nastepny=NULL;
      straznik_glowa->nastepny=nowy;
      straznik_glowa=nowy;
    }
  rozmiar++;
}

/*!
 *\brief 
 */
int Kolejka::pop()
{
  if(rozmiar!=0)
    {
      int wartosc;
      wartosc=straznik_ogon->kontener;
      element *tmp=straznik_ogon;
      straznik_ogon=straznik_ogon->nastepny;
      if(rozmiar==1)
	{
	  straznik_glowa=straznik_glowa->nastepny;
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

/*!
 *\brief 
 */
int Kolejka::size()
{
  return rozmiar;
}







