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

  /*!
   *\brief Metoda odswiezajaca obserwatora.
   *\param
   * k -typu int, ilosc danych na obserwowany obiekcie
   *\param
   * sredni_czas - typu long int, sredni czas wykonania operacji  
   */
  virtual void odswiez(int k,long int sredni_czas)=0;
};


#endif
