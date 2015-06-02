/*!
 *\file 
 *\brief Metody klasy DrzewoRB.
 *
 * Plik zawiera metody klasy DrzewoRB.
 */

#include "DrzewoRB.hh"

DrzewoRB::DrzewoRB()
{
  korzen=NULL;
  rozmiar=0;
}


DrzewoRB::~DrzewoRB()
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


void DrzewoRB::push(int wartosc)
{
  int wrzucono=0;

  if(korzen==NULL)
    {
      element *nowy=new element;
      nowy->kontener=new int[1];
      nowy->kontener[0]=wartosc;
      nowy->il_elem=1;
      nowy->kolor=B;
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
		      nowy->kolor=R;
		      nowy->lewe_subdrzewo=NULL;
		      nowy->prawe_subdrzewo=NULL;
		      iter->prawe_subdrzewo=nowy;
		      rozmiar++;
		      wrzucono=1;
		      ukladaj(iter->prawe_subdrzewo);
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
		  nowy->kolor=R;
		  nowy->lewe_subdrzewo=NULL;
		  nowy->prawe_subdrzewo=NULL;
		  iter->lewe_subdrzewo=nowy;
		  rozmiar++;
		  wrzucono=1;
		  ukladaj(iter->lewe_subdrzewo);
		}
	    }
	}
    }
}



int DrzewoRB::pop()
{
  int zwracana=0;
  srand(time(NULL));
  int szukana=rand() % 1000;
  zwracana=pop(szukana);
  return zwracana;
}

int DrzewoRB::pop(int szukana)
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



int DrzewoRB::size()
{
  return rozmiar;
}



void DrzewoRB::wypisz_pelne()
{
  int a=0;

  cout<<endl<<korzen->kontener[0]<<" "<<korzen->kolor<<" K"<<endl;
  if(korzen->lewe_subdrzewo!=NULL)
    {wypisz(korzen->lewe_subdrzewo,a);cout<<"L"<<endl;}

  if(korzen->prawe_subdrzewo!=NULL)
    {wypisz(korzen->prawe_subdrzewo,a);cout<<"P"<<endl;}

}


void DrzewoRB::wypisz(element *iter,int a)
{
  cout<<iter->kontener[0]<<" "<<iter->kolor<<" "<<a<<endl;
  a++;
  if(iter->lewe_subdrzewo!=NULL)
    {wypisz(iter->lewe_subdrzewo,a);}

  if(iter->prawe_subdrzewo!=NULL)
    {wypisz(iter->prawe_subdrzewo,a);}
}


DrzewoRB::element* DrzewoRB::obroc_l(element *pivot)
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
      tmp->up=pivot;

      if(pivot->up==NULL)
	{
	  korzen=pivot;
	}
      else
	{
	  if(pivot->up->lewe_subdrzewo==tmp)
	    {
	      pivot->up->lewe_subdrzewo=pivot;
	    }
	  else
	    {
	      pivot->up->prawe_subdrzewo=pivot;
	    }

	}
    }

  return pivot;
}

DrzewoRB::element* DrzewoRB::obroc_p(element *pivot)
{
  element *tmp;
  tmp=pivot;
  
  if(tmp->lewe_subdrzewo!=NULL)
    {
      pivot=tmp->lewe_subdrzewo;
      
      tmp->lewe_subdrzewo=pivot->prawe_subdrzewo;
      pivot->prawe_subdrzewo=tmp;
      
      if(tmp->lewe_subdrzewo!=NULL)
	{
	  tmp->lewe_subdrzewo->up=tmp;
	}
      
      pivot->up=tmp->up;
      tmp->up=pivot;

      if(pivot->up==NULL)
	{
	  korzen=pivot;
	}
      else
	{
	  if(pivot->up->lewe_subdrzewo==tmp)
	    {
	      pivot->up->lewe_subdrzewo=pivot;
	    }
	  else
	    {
	      pivot->up->prawe_subdrzewo=pivot;
	    }
	}
    }

  return pivot;
}



DrzewoRB::element* DrzewoRB::ukladaj(element* pivot)
{
  element* iter;
  element* tmp;
  int stop=0;
  
  iter=pivot;
  if(iter==NULL)
    {
      stop=1;
    }
  else
    {
      if(iter->up==NULL)
	{
	  stop=1;
	}
      else
	{
	  if(iter->up->up==NULL)
	    {
	      stop=1;
	    }
	}
    }
  
  while( stop==0)
    {
      tmp=iter->up->up;
      
      if(iter->kolor==R && iter->up->kolor==R)
	{
	  if(tmp->prawe_subdrzewo!=NULL && tmp->lewe_subdrzewo!=NULL)
	    {
	      if(tmp->lewe_subdrzewo->kolor==R && tmp->prawe_subdrzewo->kolor==R && iter->kolor==R)
		{
		  // przypadek 1;
		  tmp->lewe_subdrzewo->kolor=B;
		  tmp->prawe_subdrzewo->kolor=B;
		  tmp->kolor=R;
		  tmp=iter->up;
		}
	      else
		{
		  // przypadek 2 lub 3 z czarnym;
		  if(tmp->prawe_subdrzewo->kolor==B)
		    {
		      if(tmp->lewe_subdrzewo->prawe_subdrzewo==iter)
			{
			  //przypadek 2;
			  tmp->lewe_subdrzewo=obroc_l(tmp->lewe_subdrzewo);
			  iter=iter->lewe_subdrzewo;
			}
		      //przypadek 3;
		      tmp=obroc_p(tmp);
		      tmp->kolor=B;
		      tmp->prawe_subdrzewo->kolor=R;
		    }
		  else
		    {
		      if(tmp->prawe_subdrzewo->lewe_subdrzewo==iter)
			{
			  // przypadek 2 ;
			  tmp->prawe_subdrzewo=obroc_p(tmp->prawe_subdrzewo);
			  iter=iter->prawe_subdrzewo;
			}
		      //przypadek 3;
		      tmp=obroc_l(tmp);
		      tmp->kolor=B;
		      tmp->lewe_subdrzewo->kolor=R;
		    }
		}
	    }
	  else
	    {
	      // przypadek 2 lub 3 z nullem;
	      if(tmp->prawe_subdrzewo==NULL)
		{
		  
		  if(tmp->lewe_subdrzewo->prawe_subdrzewo==iter)
		    {
		      // przypadek 2
		      tmp->lewe_subdrzewo=obroc_l(tmp->lewe_subdrzewo);
		      iter=iter->lewe_subdrzewo;
		    }
		  // przypadek 3;
		  tmp=obroc_p(tmp);
		  tmp->kolor=B;
		  tmp->prawe_subdrzewo->kolor=R;
		}
	      else
		{
		  if(tmp->prawe_subdrzewo->lewe_subdrzewo==iter)
		    {
		      //przypadek 2
		      tmp->prawe_subdrzewo=obroc_p(tmp->prawe_subdrzewo);
		      iter=iter->prawe_subdrzewo;
		    }
		  //przypadek 3;
		  tmp=obroc_l(tmp);
		  tmp->kolor=B;
		  tmp->lewe_subdrzewo->kolor=R;
		}
	    }
	  korzen->kolor=B;
	}
      iter=tmp->up;
      if(iter==NULL)
	{
	  stop=1;
	}
      else
	{
	  if(iter->up==NULL)
	    {
	      stop=1;
	    }
	  else
	    {
	      if(iter->up->up==NULL)
		{
		  stop=1;
		}
	    }
	}
    }
  
  return pivot;
}
