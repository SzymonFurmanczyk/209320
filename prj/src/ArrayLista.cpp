/*!
 *\file 
 *\brief Metody klasy ArrayLista.
 *
 * Plik zawiera metody klasy ArrayLista.
 */

#include "ArrayLista.hh"

#include <cstdlib>
#include <iostream>


ArrayLista::ArrayLista()
{
  rozmiar=1;
  ilosc_elementow=0;
  array=new int[1]; 
}


ArrayLista::~ArrayLista()
{
  delete array;
}


void ArrayLista::push(int wartosc)
{
  if(ilosc_elementow<rozmiar)
    {
      ilosc_elementow++;
      array[ilosc_elementow]=wartosc;
    }
  else
    {
      rozmiar=rozmiar*2;
      cout<<rozmiar<<endl;
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


int ArrayLista::size()
{
  return rozmiar;
}

int ArrayLista::ile_elementow()
{
  return ilosc_elementow;
}








