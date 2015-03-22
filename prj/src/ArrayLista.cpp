/*!
 *\file 
 *\brief Metody klasy ArrayLista.
 *
 * Plik zawiera metody klasy ArrayLista.
 */

#include "ArrayLista.hh"

#include <cstdlib>
#include <iostream>

/*!
 *\brief Konstruktor bezparametryczny.
 * Konstruktor inicjalizujacy tablice listy.
 * rozmiar  - rozmiar tablicy dla listy, inicjalizowane wartoscia 1.
 * ilosc_elementow - ilosc elementow listy,inicjalizowane wartoscia 0.
 * Tworzona jest tablica dynamiczna o jednym elemencie.
 */
ArrayLista::ArrayLista()
{
  rozmiar=1;
  ilosc_elementow=0;
  array=new int[1]; 
}

/*!
 *\brief Destruktor bezparametryczny stosu.
 */
ArrayLista::~ArrayLista()
{
  delete array;
}

/*!
 *\brief Metoda umieszczajaca element na liscie
 *       Metoda inkrementuje rozmiar podczas umieszczania elementu na liscie.
 *\param
 * zwiekszanie - typu int, mnoznik rozszerzania tablicy
 *               podczas dodawania elementow listy .
 *\param
 * wartosc - typu int, wartosc umieszczana na stosie.
 */
void ArrayLista::push(int wartosc,int zwiekszanie)
{
  if(zwiekszanie<=0)
    {
      cout<<"Nieprawidlowa wartosc zwiekszania"<<endl;
    }
  else
    {
      if(ilosc_elementow<rozmiar)
	{
	  ilosc_elementow++;
	  array[ilosc_elementow]=wartosc;
	}
      else
	{
	  rozmiar=rozmiar+zwiekszanie;
	  int *tmp=new int[rozmiar+1];
	  for(int i=0;i<ilosc_elementow;i++)
	    {
	      tmp[i]=array[i];
	    }
	  ilosc_elementow++;
	  tmp[ilosc_elementow]=wartosc;
	  delete array;
	  array=tmp;
	}
    }

}

/*!
 *\brief Metoda zdejmujaca element z listy.
 *       Metoda dekrementuje ilosc_elementow przy zdejmowaniu z listy.
 *       Tablica listy jest zmniejszana podczas zdejmowania elementu o
 *       polowe gdy ilosc elementow znajdujacych sie na niej jest rowna
 *       polowie jej rozmiaru.
 *\return
 * wartosc - typu int, wartosc zdejmowana ze stosu.
 */
int ArrayLista::pop()
{
  int wartosc;
  wartosc=array[ilosc_elementow];
  ilosc_elementow--;

  if(ilosc_elementow*2==rozmiar)
    {
      int *tmp=new int[rozmiar/2];
      for(int i=0;i<ilosc_elementow;i++)
	{
	  tmp[i]=array[i];
	}
      rozmiar=rozmiar/2;
      delete array;
      array=tmp;
    }

  return wartosc;
}

/*!
 *\brief Metoda zwracajaca rozmiar tablicy na ktorej oparta jest lista.
 *\return
 * rozmiar - typu int,rozmiar tablicy listy.
 */
int ArrayLista::size()
{
  return rozmiar;
}

/*!
 *\brief Metoda zwracajaca ilosc elementow jaka znajduje sie na liscie.
 *\return
 * ilosc_elementow - typu int,ilosc elementow jaka znajduje sie na liscie.
 */
int ArrayLista::ile_elementow()
{
  return ilosc_elementow;
}








