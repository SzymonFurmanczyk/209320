/*!
 *\file 
 *\brief Metody klasy .
 *
 * Plik zawiera metody klasy .
 */

#include "Algorytm2.hh"

void Algorytm2::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
}
void Algorytm2::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{
  for(int i=0;i<=liczba_danych;i++)
    {
      Tab->push(dane[i]);
    } 
}


//Alokacja na stosie n danych
