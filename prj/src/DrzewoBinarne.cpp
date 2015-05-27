/*!
 *\file 
 *\brief Metody klasy DrzewoBinarne.
 *
 * Plik zawiera metody klasy DrzewoBinarne.
 */

#include "DrzewoBinarne.hh"

DrzewoBinarne::DrzewoBinarne()
{
  korzen=NULL;
  rozmiar=0;
}


DrzewoBinarne::~DrzewoBinarne()
{
  element* iter;
  element* tmp;
 
  iter=korzen;
  while(iter!=NULL)
    {
      while(iter->lewe_subdrzewo!=NULL)
      {
	iter=obroc_p(iter);
      }
      iter=iter->prawe_subdrzewo;
    }

  iter=korzen;
  while(iter!=NULL)
    {
      tmp=iter;
      delete[] tmp->kontener;
      iter=iter->prawe_subdrzewo;
    }
}


void DrzewoBinarne::push(int wartosc)
{
  int wrzucono=0;

  if(korzen==NULL)
    {
      element *nowy=new element;
      nowy->kontener=new int[1];
      nowy->kontener[0]=wartosc;
      nowy->il_elem=1;
      nowy->lewe_subdrzewo=NULL;
      nowy->prawe_subdrzewo=NULL;
      nowy->up=NULL;
      korzen=nowy;
      rozmiar++;
      wrzucono=1;
    }
  else
    {
      element *iter;
      iter=korzen;

      while(wrzucono==0)
	{
	  if(wartosc >= iter->kontener[0])
	    {
	      if(wartosc == iter->kontener[0])
		{
		  int *tmp=new int[iter->il_elem+1];
		  for(int i=0;i<iter->il_elem;i++)
		    {
		      tmp[i]=iter->kontener[i];
		    }
		  tmp[iter->il_elem]=wartosc;
		  delete[] iter->kontener;
		  iter->kontener=tmp;
		  iter->il_elem++;
		  wrzucono=1;
		}
	      else
		{
		  if(iter->prawe_subdrzewo!=NULL)
		    {
		      iter=iter->prawe_subdrzewo;
		    }
		  else
		    {
		      element *nowy=new element;
		      nowy->kontener=new int[1];
		      nowy->kontener[0]=wartosc;
		      nowy->il_elem=1;
		      nowy->up=iter;
		      nowy->lewe_subdrzewo=NULL;
		      nowy->prawe_subdrzewo=NULL;
		      iter->prawe_subdrzewo=nowy;
		      rozmiar++;
		      wrzucono=1;
		    }
		}
	    }
	  else
	    {
	      if(iter->lewe_subdrzewo!=NULL)
		{
		  iter=iter->lewe_subdrzewo;
		}
	      else
		{
		  element *nowy=new element;
		  nowy->kontener=new int[1];
		  nowy->kontener[0]=wartosc;
		  nowy->il_elem=1;
		  nowy->up=iter;
		  nowy->lewe_subdrzewo=NULL;
		  nowy->prawe_subdrzewo=NULL;
		  iter->lewe_subdrzewo=nowy;
		  rozmiar++;
		  wrzucono=1;
		}
	    }
	}
    }
  if(rozmiar % 1000==500)
    {
      korzen=rownowaz(korzen);
    }
}



int DrzewoBinarne::pop()
{
  int zwracana=0;
  srand(time(NULL));
  int szukana=rand() % 1000;
  zwracana=pop(szukana);
  return zwracana;
}


int DrzewoBinarne::pop(int szukana)
{
  element *iterator;
  iterator=korzen;
  int zwracana=0;
  int znaleziono=0;
  
  while(iterator!=NULL && znaleziono!=1)
    {
      if(szukana == iterator->kontener[0])
	{
	  zwracana=iterator->kontener[0];
	  znaleziono=1;
	}
      else
	{
	  if(szukana>iterator->kontener[0])
	    {
	      iterator=iterator->prawe_subdrzewo;
	    }
	  else
	    {
	      iterator=iterator->lewe_subdrzewo;
	    }
	}
    }
  
  if(znaleziono!=1)
    {
      cout<<"nie znaleziono"<<endl;
    }

  return zwracana;
}


int DrzewoBinarne::size()
{
  return rozmiar;
}



void DrzewoBinarne::wypisz_pelne()
{
  int a=0;

  cout<<endl<<korzen->kontener[0]<<" K"<<endl;
  if(korzen->lewe_subdrzewo!=NULL)
    {wypisz(korzen->lewe_subdrzewo,a);cout<<"L"<<endl;}

  if(korzen->prawe_subdrzewo!=NULL)
    {wypisz(korzen->prawe_subdrzewo,a);cout<<"P"<<endl;}

}


void DrzewoBinarne::wypisz(element *iter,int a)
{
  cout<<iter->kontener[0]<<" "<<a<<endl;
  a++;
  if(iter->lewe_subdrzewo!=NULL)
    {wypisz(iter->lewe_subdrzewo,a);}

  if(iter->prawe_subdrzewo!=NULL)
    {wypisz(iter->prawe_subdrzewo,a);}
}


DrzewoBinarne::element* DrzewoBinarne::obroc_l(element *pivot)
{
  element *tmp;
  tmp=pivot;

  if(tmp->prawe_subdrzewo!=NULL)
    {
      pivot=tmp->prawe_subdrzewo;

      tmp->prawe_subdrzewo=pivot->lewe_subdrzewo;
      pivot->lewe_subdrzewo=tmp;

      if(tmp->prawe_subdrzewo!=NULL)
	{
	  tmp->prawe_subdrzewo->up=tmp;
	}

      pivot->up=tmp->up;

      if(pivot->up==NULL)
	{
	  korzen=pivot;
	}
      else
	{
	  pivot->up->prawe_subdrzewo=pivot;
	}
      tmp->up=pivot;
    }

  return pivot;
}


DrzewoBinarne::element* DrzewoBinarne::obroc_p(element *pivot)
{
  element *tmp;
  tmp=pivot;
  
  if(tmp->lewe_subdrzewo!=NULL)
    {
      pivot=tmp->lewe_subdrzewo;
      
      tmp->lewe_subdrzewo=pivot->prawe_subdrzewo;
      pivot->prawe_subdrzewo=tmp;
      
      if(pivot->lewe_subdrzewo!=NULL)
	{
	  pivot->lewe_subdrzewo->up=tmp;
	}
      
      pivot->up=tmp->up;

      if(pivot->up==NULL)
	{
	  korzen=pivot;
	}
      else
	{
	  pivot->up->prawe_subdrzewo=pivot;
	}
      tmp->up=pivot;
    }

  return pivot;
}



DrzewoBinarne::element* DrzewoBinarne::rownowaz(element *tmp)
{
  
  element *iter;
  iter=tmp;
  
  while(iter!=NULL)
    {
      while(iter->lewe_subdrzewo!=NULL)
      {
	iter=obroc_p(iter);
      }
      iter=iter->prawe_subdrzewo;
    }

  int wykonania=1;
  do
    {
      wykonania=wykonania*2;
    }
  while(wykonania<rozmiar+1);
  wykonania=wykonania/2;
  wykonania--;

  iter=korzen;
  for(int i=0;i<rozmiar-wykonania;i++)
    {
      iter=obroc_l(iter);
      iter=iter->prawe_subdrzewo;
    }

  while(wykonania>1)
    {
      iter=korzen;
      wykonania=wykonania/2;
      for(int a=0;a<wykonania;a++)
	{
	  iter=obroc_l(iter);
	  iter=iter->prawe_subdrzewo;
	}
    }
  
  tmp=korzen;
  return tmp;
}








