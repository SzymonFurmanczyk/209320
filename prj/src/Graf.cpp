/*!
 *\file 
 *\brief Metody klasy Graf.
 *
 * Plik zawiera metody klasy Graf.
 */

#include "Graf.hh"

Graf::Graf()
{
  sasiedztwo=NULL;
  wierzcholki=NULL;
  rozmiar=0;
}


Graf::~Graf()
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

void Graf::push(int wartosc)
{
  pushwierzcholek(wartosc);
}

void Graf::push(int wierzch_1,int wierzch_2,int waga)
{
  pushwierzcholek(wierzch_1);
  pushwierzcholek(wierzch_2);
  pushkrawedz(wierzch_1,wierzch_2,waga);
}

void Graf::pushwierzcholek(int wierzch)
{
  if(wierzcholki==NULL)
    {
      wierzcholki=new int[1];
      wierzcholki[0]=wierzch;
      sasiedztwo=new int*[1];
      sasiedztwo[0]=new int [1];
      sasiedztwo[0][0]=0;
      rozmiar++;
    }
  else
    {
      wierzcholki=new int[rozmiar+1];
      wierzcholki[rozmiar]=wierzch;
      int **nowe_sasiedztwo;

      nowe_sasiedztwo=new int*[rozmiar+1];
      for(int i=0;i<rozmiar;i++)
	{
	  nowe_sasiedztwo[i]=new int[i+1];
	  for(int j=0;j<rozmiar;j++)
	    {
	      nowe_sasiedztwo[i][j]=sasiedztwo[i][j];
	    }
	}
      //delete sasiedztwo;
      sasiedztwo=nowe_sasiedztwo;
      rozmiar++;
    }

}

void Graf::pushkrawedz(int wierzch_1,int wierzch_2,int waga)
{
  int indeks_1=0;
  int indeks_2=0;
  int znaleziono_1=0;
  int znaleziono_2=0;
  
  for(int k=0;k<rozmiar;k++)
    {
      if(wierzcholki[k]==wierzch_1 || wierzcholki[k]==wierzch_2)
	{
	  if(wierzcholki[k]==wierzch_1)
	    {
	      if( wierzcholki[k]==wierzch_2)
		{
		  indeks_2=k;
		  znaleziono_2=1;
		}
	      indeks_1=k;
	      znaleziono_1=1;
	    } 
	  else
	    {
	      indeks_2=k;
	    }
	}
    } 





  
}

int Graf::pop()
{
  int zwracana=0;
  return zwracana;
}

int Graf::pop(int szukana)
{
  int zwracana=0;
  return zwracana;
}


int Graf::size()
{
  return rozmiar;
}







