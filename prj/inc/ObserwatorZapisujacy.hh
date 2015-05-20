#ifndef OBSERWATORZAPISUJACY_HH
#define OBSERWATORZAPISUJACY_HH

/*!
 *\file 
 *\brief Definicja klasy ObserwatorZapisujacy.
 *
 * Plik zawiera definicje klasy ObserwatorZapisujacy.
 */

#include "Interfaces/Obserwator.hh"

using namespace std;

/*!
 *\brief Klasa ObserwatorZapisujacy.
 */
class ObserwatorZapisujacy : public Obserwator
{ 
public:
  //~ObserwatorZapisujacy(){};
  void odswiez(int, long int);
};


#endif
