#ifndef KOLEJKA_HH
#define KOLEJKA_HH

/*!
 *\file 
 *\brief Definicja klasy Kolejka.
 *
 * Plik zawiera definicje klasy Kolejka.
 */

using namespace std;

/*!
 *\class Klasa Kolejka.
 */
class Kolejka
{
  struct element
  {
    int kontener;
    element *nastepny;
  };
  
  element *straznik_koniec;
  element *straznik_poczatek;
  int rozmiar;

public:
  Kolejka();
  ~Kolejka();
  void push(int);
  int pop();
  int size();

};


#endif
