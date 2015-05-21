/*!
 *\file 
 *\brief Metody klasy Algorytm3.
 *
 * Plik zawiera metody klasy Algorytm3.
 */

#include "Algorytm3.hh"

void Algorytm3::alokujdane(Zasobnik<string>* Tab,string* dane,int liczba_danych)
{
  string testowy_klucz;
  string wartosc,klucz;
  for(int i=0;i<liczba_danych;i++)
    {
      istringstream strumien(dane[i]);
      strumien>>wartosc;
      strumien>>klucz;
      
      if(i==liczba_danych/2 || i==1)
	{
	  testowy_klucz=klucz;
	}

      Tab->push(wartosc);
    } 
}

void Algorytm3::wykonajalgorytm(Zasobnik<string>* Tab,string* dane,int liczba_danych)
{
  string otrzymana;
  otrzymana=Tab->pop();
}


