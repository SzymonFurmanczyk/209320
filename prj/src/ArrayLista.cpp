/*!
 *\file 
 *\brief Metody klasy ArrayLista.
 *
 * Plik zawiera metody klasy ArrayLista.
 */

#include "ArrayLista.hh"

#include <cstdlib>
#include <iostream>
#include <cstring>


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
  if(zwiekszanie<=0)
    {
      cout<<"Nieprawidlowa wartosc zwiekszania"<<endl;
    }
  else
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



ArrayLista* ArrayLista::mergesort(ArrayLista* sortowana)
{

	ArrayLista *po_sortowana=new ArrayLista(size());

	dziel(this);

	return po_sortowana;
}



ArrayLista* ArrayLista::dziel(ArrayLista* dzielona)
{
cout<<"lol";
	int srodek=dzielona->ilosc_elementow/2;
	
	ArrayLista *tablica_l=new ArrayLista(srodek+1);
	for(int j=0;j<srodek+1;j++)
	{
	tablica_l->array[j]=dzielona->array[j];
	}
	//memcpy(tablica_l->array,dzielona->array,srodek-1);

	ArrayLista *tablica_p=new  ArrayLista(ile_elementow()-srodek+1);
	for(int j=0;j<srodek+1;j++)
	{
	tablica_p->array[j]=dzielona->array[j];
	}
	//memcpy(dzielona->array,tablica_p->array,ile_elementow()-srodek+1);
	
	if(srodek!=1)
	{
	dziel(tablica_l);
	}
	dziel(tablica_p);

	
	return tablica_l;
}


ArrayLista* scal(ArrayLista* scalana1 , ArrayLista* scalana2)
{
	ArrayLista* scalona=new ArrayLista(scalana1->ile_elementow()+scalana2->ile_elementow()+1);
	
	
	//układanie danych

	int i=0;
	while(i < scalona->ile_elementow())
	{
	}

	//memcpy(scalana1->array,scalona,1);
	
	return scalona;
}
	
	

























