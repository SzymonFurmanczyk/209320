#ifndef STOS_HH
#define STOS_HH

/*!
 *\file 
 *\brief Definicja klasy Stos.
 *
 * Plik zawiera definicje klasy Stos.
 */

using namespace std;

/*!
 *\class Klasa Stos.
 */
class Stos
{
  struct element
  {
    int kontener;
    element *nastepny;
  };
  
  element *straznik;
  int rozmiar;
  
public:
  Stos();
  ~Stos();
  void push(int);
  int pop();
  int size();

};


#endif
