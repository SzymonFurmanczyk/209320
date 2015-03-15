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
 *       listy wartoscia NULL.
 */
Stos::Stos()
{
  straznik=NULL;
  rozmiar=0;
}

/*!
 *\brief Destruktor bezparametryczny.
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
 *\brief 
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
 *\brief 
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
 *\brief 
 */
int Stos::size()
{
  return rozmiar;
}







