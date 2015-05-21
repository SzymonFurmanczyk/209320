#ifndef HASZTAB_HH
#define HASZTAB_HH

/*!
 *\file 
 *\brief Definicja klasy HaszTab.
 *
 * Plik zawiera definicje klasy modulujacej pojecie tablicy haszującej. 
 */

#include "Interfaces/Zasobnik.hh"

using namespace std;

/*!
 *\brief Klasa HaszTab.
 */
class HaszTab : public Zasobnik<string>
{
  
  struct element
  {
    string wartosc;
    string klucz;

    element()
    {wartosc=".";klucz=".";};

    element(string a,string b)
    {wartosc=a;klucz=b;};
  };
  
  int rozmiar_k1;
  int rozmiar_k2;
  element *array[100][310];
 

public:
  
  /*!
   *\brief Konstruktor bezparametryczny.
   * Konstruktor inicjalizujacy tablice haszującą.
   * rozmiar_k1  - wielkosc tablicy pierwszej.
   * rozmiar_k2  - wielkosc tablicy drugiej.
   * Tworzona jest maciecz elementow (string wartosc,string klucz) o zadanej wielkości.
   */
  HaszTab();
  
  
  /*!
   *\brief Destruktor bezparametryczny tablicy haszującej.
   */
  ~HaszTab();
  
  
  /*!
   *\brief Przeciazenie operacji push.
   * Metoda umieszczająca element o zadanej wartości i kluczu na
   * tablicy haszującej.
   *\param
   * wartosc - typu string,zadana wartość.
   *\param
   * klucz - typu string, zadany klucz.
   */
  void push(string wartosc,string klucz);

  string pop(string klucz_szukany);

  void push(string wartosc);
  string pop();	  
  int size();
  
  /*!
   *\brief Metoda mieszająca klucz tablicy haszującej.
   *       Metoda zmienia zadany klucz na indeksy tablic.
   *\param
   * klucz_umieszczany - typu string, zadany klucz.
   *\param
   * modulacja - typu int, wielkość tablicy która moduluje klucz.
   *\return
   * indeks - typu int, zmodulowany indeks elementu.
   */
  int mieszaj(string klucz_umieszczany,int modulacja);
  
  
  /*!
   *\brief Metoda zczytująca element z tablicy haszującej.
   *       Metoda zczytuje element o określonym kluczu.
   *       Wartości oraz klucze nie są usuwane podczas zczytywania
   *\param
   * klucz_szukany - typu string, szukany klucz.
   *\return
   * wartosc - typu int, wartosc zdejmowana ze stosu.
   */
  string odczytaj(string klucz_szukany);
  
  
  /*!
   *\brief Metoda zwracajaca rozmiar tablicy pierwszej na ktorej oparta jest tablica haszująca.
   *\return
   * rozmiar - typu int,rozmiar tablicy pierwszej.
   */
  int size_k1();
  
  
  /*!
   *\brief Metoda zwracajaca rozmiar tablicy drugiej na ktorej oparta jest tablica haszująca.
   *\return
   * rozmiar - typu int,rozmiar tablicy drugiej.
   */
  int size_k2();
};


#endif
