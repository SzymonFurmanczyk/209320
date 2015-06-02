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
  for(int i=0;i<rozmiar;i++)
    {
      delete[] sasiedztwo[i];
    }
  delete[] sasiedztwo;
}


void Graf::push(int wierzch)
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
      int istnieje=0;
      int *tmp=wierzcholki;

      for(int i=0;i<rozmiar;i++)
	{
	  if(wierzch==wierzcholki[i])
	    {
	      istnieje=1;
	    }
	}

      if(istnieje==0)
	{
	  rozmiar++;

	  wierzcholki=new int[rozmiar];
	  for(int i=0;i<rozmiar-1;i++)
	    {
	      wierzcholki[i]=tmp[i];
	    }

	  wierzcholki[rozmiar-1]=wierzch;


	  int **nowe_sasiedztwo=new int*[rozmiar];

	  for(int i=0;i<rozmiar;i++)
	    {
	      nowe_sasiedztwo[i]=new int[rozmiar];
	      for(int j=0;j<rozmiar;j++)
		{
		  nowe_sasiedztwo[i][j]=0;
		}
	    }

	  for(int i=0;i<rozmiar-1;i++)
	    {
	      for(int j=0;j<rozmiar-1;j++)
		{
		  nowe_sasiedztwo[i][j]=sasiedztwo[i][j];
		}
	    }

	  for (int i = 0; i <rozmiar-1; i++)
	    {
	      delete[] sasiedztwo[i];
	    } 
	  delete [] sasiedztwo;

	  sasiedztwo=nowe_sasiedztwo;	  
	}
    }

}

void Graf::push(int wierzch_1,int wierzch_2,int waga)
{
  int indeks_1=0;
  int indeks_2=0;
  int znaleziono_1=0;
  int znaleziono_2=0;
  
  push(wierzch_1);
  push(wierzch_2);

  for(int k=0;k<rozmiar || (znaleziono_1!=1 && znaleziono_2!=1);k++)
    {
      if(wierzcholki[k]==wierzch_1 || wierzcholki[k]==wierzch_2)
	{
	  if(wierzcholki[k]==wierzch_1)
	    {
	      indeks_1=k;
	      znaleziono_1=1;
	    }
	  if( wierzcholki[k]==wierzch_2)
	    {
	      indeks_2=k;
	      znaleziono_2=1;
	    }
	} 
    }
  if(znaleziono_1==1 && znaleziono_2==1)
    {
      sasiedztwo[indeks_1][indeks_2]=waga;
      sasiedztwo[indeks_2][indeks_1]=waga;
    }
} 

int Graf::pop()
{
  int zwracana=0;
  return zwracana;
}

int Graf::pop(int indeks)
{
  return wierzcholki[indeks];
}

int Graf::pop(int indeks1,int indeks2)
{
  if(sasiedztwo!=NULL)
    {
      return sasiedztwo[indeks1][indeks2];
    }
  return 0;
}


int Graf::size()
{
  return rozmiar;
}







