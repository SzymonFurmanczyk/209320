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



void ArrayLista::mergesort()
{
  int srodek=ile_elementow()/2;

  if(srodek>0)
    {
      ArrayLista* tab_l=new ArrayLista(srodek);
      ArrayLista* tab_p=new ArrayLista(ilosc_elementow-srodek);
      
      tab_l->rozmiar=srodek;
      tab_l->ilosc_elementow=srodek;
      for(int k=0;k<srodek;k++)
	{
	  tab_l->array[k]=array[k];
	}
      
      tab_p->rozmiar=ilosc_elementow-srodek;
      tab_p->ilosc_elementow=ilosc_elementow-srodek;
      int g=0;
      for(int j=srodek;j<ilosc_elementow;j++)
	{
	  tab_p->array[g]=array[j];
	  g++;
	}

      tab_l->mergesort();
      tab_p->mergesort();
      scal(tab_l,tab_p);
      delete tab_l;
      delete tab_p;
    }
}


void ArrayLista::scal(ArrayLista* tab_l,ArrayLista* tab_p)
{
  int l=0;
  int p=0;
  int i=0;

  while(i<ilosc_elementow)
    {
      if(l!=tab_l->ilosc_elementow && p!=tab_p->ilosc_elementow)
	{
	  if(tab_l->array[l]<=tab_p->array[p])
	    {
	      array[i]=tab_l->array[l];
	      l++;
	      i++;
	    }
	  else
	    {
	      array[i]=tab_p->array[p];
	      p++;
	      i++;
	    }	  
	}
      else
	{
	  if(l!=tab_l->ilosc_elementow)
	    {
	      array[i]=tab_l->array[l];
	      l++;
	      i++;
	    }
	  else
	    {
	      array[i]=tab_p->array[p];
	      p++;
	      i++;
	    }  
	}
    }
}




