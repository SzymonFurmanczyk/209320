#ifndef LISTA_HH
#define LISTA_HH

/*!
 *\file 
 *\brief Definicja klasy Lista.
 *
 * Plik zawiera definicje klasy Lista.
 */

using namespace std;

/*!
 *\brief Klasa Lista.
 */
class Lista
{

  struct element
  {
    int kontener;
    element * nastepny;
  };
  
  element * straznik;
  int rozmiar;
  
  
public:
  Lista();
  ~Lista();

  void push(int,int);
  int pop(int);

  void push(int wartosc)
  {push(wartosc,1);};
  int pop()
  {return pop(1);};

  int size();
  
};


#endif
