/*!
 *\file 
 *\brief Metody klasy Stos.
 *
 * Plik zawiera metody klasy Stos.
 */

#include "Stos.hh"

#include <cstdlib>
#include <iostream>

Stos::Stos()
{
  straznik=NULL;
  rozmiar=0;
}


Stos::~Stos()
{
  while(straznik!=NULL)
    {
      element * tmp = straznik->nastepny;
      delete straznik;
      straznik=tmp;
    }
}

void Stos::push(int wartosc)
{
  element * nowy = new element;
  nowy->kontener = wartosc;
  nowy->nastepny = straznik;
  rozmiar++;
  straznik=nowy;
}


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



int Stos::size()
{
  return rozmiar;
}







