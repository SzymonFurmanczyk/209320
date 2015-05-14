/*!
 *\file 
 *\brief Metody klasy .
 *
 * Plik zawiera metody klasy .
 */

#include "DrzewoBinarne.hh"

#include <cstdlib>
#include <iostream>

DrzewoBinarne::DrzewoBinarne()
{
  korzen=NULL;
  rozmiar=0;
}


DrzewoBinarne::~DrzewoBinarne()
{
  /*
  while(straznik!=NULL)
    {
      element * tmp = straznik->nastepny;
      delete straznik;
      straznik=tmp;
    }
  */
}

void DrzewoBinarne::push(int wartosc)
{
  if(korzen==NULL)
    {
      element *nowy=new element;
      nowy->kontener=wartosc;
      nowy->lewe_subdrzewo=NULL;
      nowy->prawe_subdrzewo=NULL;
      nowy->up=NULL;
      korzen=nowy;
      rozmiar++;
    }
  else
    {
      element *iter;
      iter=korzen;
      
      if(wartos >= iter->kontener)
	{
	  if(wartosc == iter->kontener)
	    {
	      iter->kontener=wartosc;
	    }
	  else
	    {
	      if(iter->prawe_subdrzewo!=NULL)
		{
		  iter=prawe_subdrzewo;
		}
	      else
		{
		  element *nowy=new element;
		  nowy->kontener=wartosc;
		  nowy->lewe_subdrzewo=NULL;
		  nowy->prawe_subdrzewo=NULL;
		  nowy->up=iter;
		  iter->prawe_subdrzewo=nowy;
		  rozmiar++;
		}
	    }
	}
      else
	{
	  if(iter->lewe_subdrzewo!=NULL)
	    {
	      iter=lewe_subdrzewo;
	    }
	  else
	    {
	      element *nowy=new element;
	      nowy->kontener=wartosc;
	      nowy->lewe_subdrzewo=NULL;
	      nowy->prawe_subdrzewo=NULL;
	      nowy->up=iter;
	      iter->lewe_subdrzewo=nowy;
	      rozmiar++;
	    }
	}
    }
}


int DrzewoBinarne::pop(int)
{
  /*
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
  */
}



int DrzewoBinarne::size()
{
  return rozmiar;
}







