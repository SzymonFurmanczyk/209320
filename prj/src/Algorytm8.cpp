/*!
 *\file 
 *\brief Metody klasy Algorytm8.
 *
 * Plik zawiera metody klasy Algorytm8.
 */

#include "Algorytm8.hh"

void Algorytm8::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  for(int i=0;i<liczba_danych;i=i+3)
    {
      Tab->push(dane[i],dane[i+1],dane[i+2]);
    }
}


//BFS
void Algorytm8::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych)
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
  int* rodzic = new int[Tab->size()];
  int* wystapienie = new int[Tab->size()];


  wystapienie[poczatkowa]=1;
  rodzic[poczatkowa]=poczatkowa;
  wynikowa.push_back(poczatkowa);

  list<int>::iterator iter=wynikowa.begin();
  int k=poczatkowa;
  int l=1;

  while(l<Tab->size() && iter!=wynikowa.end() && znaleziono!=1)
    {
      k=*iter;
      for(int i=0;i<Tab->size() && znaleziono!=1;i++)
	{
	  if(Tab->pop(k,i)==1)
	    {
	      if(wystapienie[i]!=1)
		{
		  wynikowa.push_back(i);
		  wystapienie[i]=1;
		  rodzic[i]=k;
		  l++;
		  if(i==koncowa)
		    {
		      znaleziono=1;
		    }
		}
	    }
	}
      if(iter!=wynikowa.end())
	{
	  iter++;
	}
    }

  list<int> droga;
  if(liczba_danych==1000)
    {
      int temp=koncowa;
      droga.push_front(koncowa);
      while(temp!=poczatkowa)
	{
	  temp=rodzic[temp];
	  droga.push_front(temp);
	}
    }


  // //Wyswietlanie wyniku
  // for (list<int>::iterator tmp=droga.begin();tmp!=droga.end();tmp++)
  //   {
  //     cout<<*tmp<<" ";
  //   }
  // cout<<endl<<endl<<poczatkowa<<endl;
  // cout<<koncowa<<endl;

}
