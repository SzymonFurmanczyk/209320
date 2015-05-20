/*!
 *\file 
 *\brief Metody klasy Algorytm1.
 *
 * Plik zawiera metody klasy Algorytm1.
 */

#include "Algorytm1.hh"

void Algorytm1::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{

}

void Algorytm1::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych )
{
  for(int i=0;i<liczba_danych;i++)
    {
      dane[i]=dane[i]*2;
    }
}
