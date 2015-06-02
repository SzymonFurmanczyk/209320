/*!
 *\file 
 *\brief Metody klasy Algorytm7.
 *
 * Plik zawiera metody klasy Algorytm7.
 */

#include "Algorytm7.hh"

void Algorytm7::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  for(int i=0;i<liczba_danych;i=i+3)
    {
      Tab->push(dane[i],dane[i+1],dane[i+2]);
    }
}


//DFS
void Algorytm7::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  int a=Tab->size();
  int koncowa=0;
  int poczatkowa=0;
  int znaleziono=0;  

  srand(time(NULL));

  if(a!=0)
    {
      poczatkowa=rand() % a;
      koncowa=rand() % a;
    }

  list<int> wynikowa;
  int* wystapienie = new int[Tab->size()];

  wystapienie[poczatkowa]=1;


  DFS(poczatkowa,koncowa,znaleziono,wystapienie,Tab,wynikowa);
  wynikowa.push_front(poczatkowa);

  // //Wyswietlanie wyniku
  // for (list<int>::iterator tmp=wynikowa.begin();tmp!=wynikowa.end();tmp++)
  //   {
  //     cout<<*tmp<<" ";
  //   }
  // cout<<endl<<endl<<poczatkowa<<endl;
  // cout<<koncowa<<endl;
}


void Algorytm7::DFS(int pozycja,int koncowa,int &znaleziono,int *wystapienie,Zasobnik<int>* Tab,list<int> &wynikowa)
{
  int temp=-1;
  for(int i=0;(i<Tab->size()) && (znaleziono!=1);i++)
    {
      if(Tab->pop(pozycja,i)!=0)
	{
	  if(wystapienie[i]!=1)
	    {
	      wystapienie[i]=1;

	      temp=i;
	      if(i==koncowa)
		{
		  znaleziono=1;
		}

	      if(znaleziono!=1)
		{
		  DFS(i,koncowa,znaleziono,wystapienie,Tab,wynikowa);
		}
	      if(znaleziono==1)
		{
		wynikowa.push_front(temp);
		}
	    }
	}
    }
}
