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
  int wielkosc=Tab->size();
  int srodek=Tab->size()/2;
  int size_l=wielkosc-srodek;
  int size_p=srodek;


  if(srodek>0)
    {
      int* tab_p=new int[size_p];
      int* tab_l=new int[size_l];
      
      for(int k=size_p-1;k>=0;k--)
	{
	  tab_p[k]=Tab->pop();
	}
      
      for(int j=size_l-1;j>=0;j--)
	{
	  tab_l[j]=Tab->pop();
	}
      
      tab_p=mergesort(tab_p,size_p);
      tab_l=mergesort(tab_l,size_l);

      int* koncowa=new int[wielkosc];
      scal(koncowa,tab_l,size_l,tab_p,size_p);
      
      for(int i=0;i<wielkosc;i++)
	{
	  Tab->push(koncowa[i]);
	}     
    }
}

int* Algorytm4::mergesort(int *Tab,int wielkosc)
{
  int srodek=wielkosc/2;
  int size_l=wielkosc-srodek;
  int size_p=srodek;

  if(srodek>0)
    {
      int* tab_p=new int[size_p];
      int* tab_l=new int[size_l];

      int i=0;

      for(int k=0;k<size_l;k++)
	{
	  tab_l[k]=Tab[i];
	  i++;
	}
      for(int j=0;j<size_p;j++)
	{
	  tab_p[j]=Tab[i];
	  i++;
	}

      tab_l=mergesort(tab_l,size_l);
      tab_p=mergesort(tab_p,size_p);
      scal(Tab,tab_l,size_l,tab_p,size_p);
    }
  return Tab;
}


int* Algorytm4::scal(int* Tab,int* tab_l,int size_l,int* tab_p,int size_p)
{
  int l=0;
  int p=0;
  int i=0;

  while(l<size_l || p<size_p)
    {
      if(l<size_l && p<size_p)
	{
	  if(tab_l[l]<=tab_p[p])
	    {
	      Tab[i]=tab_l[l];
	      l++;
	      i++;
	    }
	  else
	    {
	      Tab[i]=tab_p[p];
	      p++;
	      i++;
	    }	  
	}
      else
	{
	  if(l<size_l)
	    {
	      Tab[i]=tab_l[l];
	      l++;
	      i++;
	    }
	  else
	    {
	      Tab[i]=tab_p[p];
	      p++;
	      i++;
	    }  
	}
    }
  return Tab;
}

