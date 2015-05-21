/*!
 *\file 
 *\brief Metody klasy Algorytm6.
 *
 * Plik zawiera metody klasy Algorytm6.
 */

#include "Algorytm6.hh"

void Algorytm6::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  for(int i=0;i<=liczba_danych;i=i+2)
    {
      Tab->push(dane[i]);
      Tab->push(dane[i+1]);
    }
}

void Algorytm6::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
}
