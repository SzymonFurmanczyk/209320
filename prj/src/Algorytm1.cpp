/*!
 *\file 
 *\brief Metody klasy .
 *
 * Plik zawiera metody klasy .
 */

#include "Algorytm1.hh"

void Algorytm1::alokujdane(Zasobnik<int>* Tab,int* dane,int liczba_danych)
{

}
inline void Algorytm1::wykonajalgorytm(Zasobnik<int>* Tab,int* dane,int liczba_danych )
{
  for(int i=0;i<=liczba_danych;i++)
    {
      Tab->push(dane[i]);
    } 
}



//Alokacja na zasobniku n danych
