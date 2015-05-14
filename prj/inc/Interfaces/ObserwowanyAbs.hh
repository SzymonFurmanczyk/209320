#ifndef OBSERWOWANYABS_HH
#define OBSERWOWANYABS_HH

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
class Obserwowany
{ 
public:
  Obserwowany();
  virtual void dodaj(Obserwator *Obs);
  virtual void usun(Obserwator *Obs);
  virtual void powiadom();
};


#endif
