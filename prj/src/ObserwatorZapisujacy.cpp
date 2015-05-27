/*!
 *\file 
 *\brief Metody klasy ObserwatorZapisujacy.
 *
 * Plik zawiera metody klasy ObserwatorZapisujacy.
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <fstream>

#include "ObserwatorZapisujacy.hh"

void ObserwatorZapisujacy::odswiez(int k,long int sredni_czas)
{
  ofstream plik;
  plik.open("benchmark.csv",ios::app);
  //cout<<k<<" "<<sredni_czas<<endl;    
  plik<<k<<","<<sredni_czas<<"\n";
  plik.close();
}

