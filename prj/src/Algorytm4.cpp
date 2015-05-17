/*!
 *\file 
 *\brief Metody klasy .
 *
 * Plik zawiera metody klasy .
 */

#include "Algorytm4.hh"

void Algorytm4::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  for(int i=0;i<=liczba_danych;i++)
    {
      Tab->push(dane[i]);
    } 
}
void Algorytm4::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  //mergesort(Tab);
}

/*
void Algorytm4::mergesort(Zasobnik<int> Tab*)
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


void Algorytm4::scal(ArrayLista* tab_l,ArrayLista* tab_p)
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
*/
//Alokacja na kolejce n danych
