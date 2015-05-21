/*!
 *\file 
 *\brief Metody klasy ArrayLista.
 *
 * Plik zawiera metody klasy ArrayLista.
 */

#include "ArrayLista.hh"


ArrayLista::ArrayLista()
{
  rozmiar=1;
  ilosc_elementow=0;
  array=new int[1]; 
}

ArrayLista::ArrayLista(int wielkosc)
{
  rozmiar=wielkosc;
  ilosc_elementow=0;
  array=new int[wielkosc]; 
}

ArrayLista::~ArrayLista()
{
  delete array;
}


void ArrayLista::push(int wartosc,int zwiekszanie)
{
  if(zwiekszanie>0)
    {
      if(ilosc_elementow<rozmiar)
	{
	  array[ilosc_elementow]=wartosc;
	  ilosc_elementow++;
	}
      else
	{
	  rozmiar=rozmiar+zwiekszanie;
	  int *tmp=new int[rozmiar];

	  for(int i=0;i<ilosc_elementow;i++)
	    {
	      tmp[i]=array[i];
	    }

	  tmp[ilosc_elementow]=wartosc;
	  ilosc_elementow++;
	  delete array;
	  array=tmp;
	}
    }
  else
    {
      cout<<"Nieprawidlowa wartosc zwiekszania"<<endl;
    }

}


int ArrayLista::pop()
{
  int wartosc;
  ilosc_elementow--;
  wartosc=array[ilosc_elementow];

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
  return ilosc_elementow;
}




