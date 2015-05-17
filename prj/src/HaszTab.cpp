/*!
 *\file 
 *\brief Metody klasy HaszTab.
 *
 * Plik zawiera metody klasy HaszTab.
 */

#include "HaszTab.hh"

HaszTab::HaszTab()
{
  rozmiar_k1=100;
  rozmiar_k2=310;

  for(int i=0;i<rozmiar_k1;i++)
    {
      for(int j=0;j<rozmiar_k2;j++)
	{
	  array[i][j]=new element;
	}
    }
}


HaszTab::~HaszTab()
{

  for(int a=0;a<rozmiar_k1;a++)
    {
      for(int b=0;b<rozmiar_k2;b++)
	{
	  delete array[a][b];
	}    
    }
}

void HaszTab::push(string wartosc)
{
}

void HaszTab::push(string wartosc,string klucz)
{
  int indeks,indeks2;
  indeks=mieszaj(klucz,rozmiar_k1);
  indeks2=mieszaj(klucz,rozmiar_k2);

  int l=0;
  int k=0;
  
  while(l<rozmiar_k2 && array[indeks][indeks2+k]->wartosc!="." && array[indeks][indeks2+k]->klucz!=".")
    {
      if(k+indeks2==rozmiar_k2-1)
	{
	  k=-indeks2-1;
	}
      k++;
      l++;
    }
  
  if(array[indeks][indeks2+k]->wartosc=="." && array[indeks][indeks2+k]->klucz==".")
    {
      delete array[indeks][indeks2+k];
      array[indeks][indeks2+k]=new element(wartosc,klucz);
       }
  else
    {
      cout<<"Tablica jest pełna na pozycji"<<indeks<<endl;
    }
}


string HaszTab::odczytaj(string klucz_szukany)
{
  string odczyt="";
  int indeks,indeks2;

  indeks=mieszaj(klucz_szukany,rozmiar_k1);
  indeks2=mieszaj(klucz_szukany,rozmiar_k2);

  int k=0;
  int l=0;
  while(array[indeks][indeks2+k]->klucz!=klucz_szukany && l<rozmiar_k2)
    {
      if((array[indeks][indeks2+k]->wartosc!=".") || (array[indeks][indeks2+k]->klucz!="."))
	{
	  if(k+indeks2==rozmiar_k2-1)
	    {
	      k=-indeks2-1;
	    }
	  k++;
	  l++;
	}
      else
	{
	  cout<<"Nie znaleziono ";
	  return odczyt;
	}
    }

  odczyt=array[indeks][indeks2+k]->wartosc;

  return odczyt;
}

string HaszTab::pop()
{
  string dana;
  return dana;
}

int HaszTab::size()
{
  return rozmiar_k1*rozmiar_k2;
}

int HaszTab::mieszaj(string klucz_umieszczany,int modulacja)
{
  int indeks=0;
  int tmp=0;

  int i=0;
  while(klucz_umieszczany[i]!='\0')
    { 
      tmp=tmp+(int)klucz_umieszczany[i];
      i++;
    }  
  indeks=tmp % modulacja;

  return indeks;
}


int HaszTab::size_k1()
{
  return rozmiar_k1;
}

int HaszTab::size_k2()
{
  return rozmiar_k2;
}





