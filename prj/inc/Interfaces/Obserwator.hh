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
  virtual ~Obserwator(){};
  virtual void odswiez(int,long int)=0;
};


#endif
