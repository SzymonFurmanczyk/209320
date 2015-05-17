/*!
 *\file 
 *\brief Metody klasy Lista.
 *
 * Plik zawiera metody klasy Lista.
 */

#include "Lista.hh"

Lista::Lista()
{
  straznik=NULL;
  rozmiar=0;
}


Lista::~Lista()
{
  while(straznik!=NULL)
    {
      element *tmp= straznik->nastepny;
      delete straznik;
      straznik=tmp;
    }
}


void Lista::push(int wartosc,int pozycja)
{
  
  if(pozycja>=1)
    {
      element *nowy= new element;
      element *iter= straznik;
      nowy->kontener = wartosc;
      
      if(pozycja<=rozmiar+1)
	{
	  if(pozycja!=1)
	    {
	      for(int i=2;i<pozycja;i++)
		{
		  iter=iter->nastepny;
		}
	      nowy->nastepny = iter->nastepny;
	      iter->nastepny = nowy;
	      rozmiar++;
	    }
	  else
	    {
	      nowy->nastepny = straznik;
	      straznik=nowy;
	      rozmiar++;
	    }
	}
      else
	{
	  cout<<"Pozycja przekracza rozmiar listy";
	}
    }
  else
    {
      cout<<"Nieprawidlowa pozycja";
    }
}


int Lista::pop(int pozycja)
{
  int wartosc;


  if(pozycja>=1 and 0<rozmiar and pozycja<=rozmiar)
    {
      element *iter= straznik;
      element *temp= straznik;
      
      
      if(pozycja==1)
	{
	  straznik=straznik->nastepny;
	}
      else
	{
	  for(int i=1;i<pozycja;i++)
	    {
	      temp=iter;
	      iter=iter->nastepny;
	    }
	  temp->nastepny=iter->nastepny;
	}
      
      wartosc=iter->kontener;
      delete iter;
      rozmiar--;
    }
  else
    {
      cout<<"Lista jest pusta lub nieprawidlowa pozycja"<<endl;
      return 0;
    }
  
  return wartosc;
}


int Lista::size()
{
  return rozmiar;
}







