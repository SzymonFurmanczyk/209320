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
 *\brief Klasa Kolejka.
 */
class Kolejka
{
  struct element
  {
    int kontener;
    element *nastepny;
  };
  
  element *straznik_glowa;
  element *straznik_ogon;
  int rozmiar;

public:
  Kolejka();
  ~Kolejka();
  void push(int);
  int pop();
  int size();

};


#endif
