#ifndef LISTA_HH
#define LISTA_HH

/*!
 *\file 
 *\brief Definicja klasy Lista.
 *
 * Plik zawiera definicje klasy modulujacej pojecie listy jednokierunkowej.
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

/*!
 *\brief Przeciazenie operacji push. Umieszcza element domyslnie na pozycji 1.
 *       Nastepuje inkrementacja rozmiar listy.
 *\param
 * wartosc - typu int, wartosc umieszczana na liscie.
 */
  void push(int wartosc)
  {push(wartosc,1);};

/*!
 *\brief Przeciazenie operacji pop dla listy. Pobiera domyslnie
 *       element listy z pozycji 1.Nastepuje dekrementacja rozmiar listy.
 *\return
 * wartosc - typu int, wartosc zdejmowana z listy.
 */
  int pop()
  {return pop(1);};

  int size();
  
};


#endif
