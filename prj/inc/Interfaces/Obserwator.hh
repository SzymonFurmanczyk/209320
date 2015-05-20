#ifndef OBSERWATORABS_HH
#define OBSERWATORABS_HH

/*!
 *\file 
 *\brief Definicja klasy Obserwator.
 *
 * Plik zawiera definicje klasy Obserwator.
 */

using namespace std;

/*!
 *\brief Klasa Obserwator.
 */
class Obserwator
{ 

public:
  //virtual ~Obserwator(){};
  virtual void odswiez(int,long int)=0;
};


#endif
