/*!
 *\file 
 *\brief Metody klasy Algorytm5.
 *
 * Plik zawiera metody klasy Algorytm5.
 */

#include "Algorytm5.hh"

void Algorytm5::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  for(int i=0;i<=liczba_danych;i++)
    {
      Tab->push(dane[i]);
    }
}

void Algorytm5::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  Tab->pop();
}

