#ifndef OBSERWATORABS_HH
#define OBSERWATORABS_HH

/*!
 *\file 
 *\brief Definicja klasy .
 *
 * Plik zawiera definicje klasy .
 */

using namespace std;

/*!
 *\brief Klasa .
 */
class Obserwator
{ 
public:
  Obserwator();
  virtual void odswiez()=0;
};


#endif
