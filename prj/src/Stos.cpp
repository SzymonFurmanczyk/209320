/*!
 *\file 
 *\brief Metody klasy Stos.
 *
 * Plik zawiera metody klasy Stos.
 */

#include "Stos.hh"

#include <cstdlib>
#include <iostream>

/*!
 *\brief Konstruktor bezparametryczny.
 *       Konstruktor inicjalizujacy straznika 
 *       stosu wartoscia NULL ,oraz rozmiar wartoscia 0.
 */
Stos::Stos()
{
  straznik=NULL;
  rozmiar=0;
}

/*!
 *\brief Destruktor bezparametryczny stosu.
 */
Stos::~Stos()
{
  while(straznik!=NULL)
    {
      element * tmp = straznik->nastepny;
      delete straznik;
      straznik=tmp;
    }
}

/*!
 *\brief Metoda umieszczajaca element na stosie
 *       Metoda inkrementuje rozmiar podczas umieszczania elementu na stosie.
 *\param
 * wartosc - typu int, wartosc umieszczana na stosie.
 */
void Stos::push(int wartosc)
{
  element * nowy = new element;
  nowy->kontener = wartosc;
  nowy->nastepny = straznik;
  rozmiar++;
  straznik=nowy;
}

/*!
 *\brief Metoda zdejmujaca element ze stosu.
 *       Metoda dekrementuje rozmiar przy zdejmowaniu ze stosu.
 *\return
 * wartosc - typu int, wartosc zdejmowana ze stosu.
 */
int Stos::pop()
{
  if(rozmiar!=0)
    {
      int wartosc;
      wartosc=straznik->kontener;
      element *tmp=straznik;
      straznik=straznik->nastepny;
      delete tmp;
      rozmiar--;
      return wartosc;
    }
  else
    {
      cout<<"Stos jest pusty"<<endl;
      return 0;
    }
}


/*!
 *\brief Metoda zwracajaca wielkosc stosu.
 *\return
 * rozmiar - typu int,rozmiar stosu.
 */
int Stos::size()
{
  return rozmiar;
}







