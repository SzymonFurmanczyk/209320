/*!
 *\file 
 *\brief Metody klasy .
 *
 * Plik zawiera metody klasy .
 */

#include "Obserwator.hh"

void odswiez()
{
  ofstream plik;
  plik.open("benchmark.csv" , ios::out , ios::app);
  //cout<<k<<" "<<sredni_czas_arraylista_mergesort<<endl;    
  plik<<k<<","<<sredni_czas_arraylista_mergesort<<"\n";
  plik.close();
}

