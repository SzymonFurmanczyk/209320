#ifndef DRZEWOBINARNE_HH
#define DRZEWOBINARNE_HH

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
class DrzewoBinarne : public Zasobnik<int>
{
  struct element
  {
    int kontener;
    
    element *up;
    element *lewe_subdrzewo;
    element *prawe_subdrzewo;
  };
 
  element *korzen;
  int rozmiar;
  
public:
  
  DrzewoBinarne();
  
  ~DrzewoBinarne();
  
  

  void push(int);
  

  int pop();
  

  int size();
  
};


#endif
