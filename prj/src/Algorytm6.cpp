/*!
 *\file 
 *\brief Metody klasy Algorytm6.
 *
 * Plik zawiera metody klasy Algorytm6.
 */

#include "Algorytm6.hh"

void Algorytm6::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  for(int i=0;i<=liczba_danych;i++)
    {
      Tab->push(dane[i]);
    }
}

void Algorytm6::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  srand(time(NULL));
  int indeks=rand() % 1 + (liczba_danych-1);
  int szukana=dane[indeks];
  Tab->pop(szukana);
}
