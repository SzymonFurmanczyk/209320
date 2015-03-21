#ifndef ARRAYLISTA_HH
#define ARRAYLISTA_HH

/*!
 *\file 
 *\brief Definicja klasy ArrayLista.
 *
 * Plik zawiera definicje klasy modulujacej pojecie listy jednokierunkowej opartej na tablicy dynamicznej.
 */

using namespace std;

/*!
 *\brief Klasa ArrayLista.
 */
class ArrayLista
{
  int rozmiar;
  int ilosc_elementow;
  int *array;
  
public:
  ArrayLista();
  ~ArrayLista();

  void push(int);
  int pop();
  int size();
  int ile_elementow();
  
};


#endif
