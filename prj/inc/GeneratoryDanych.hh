#ifndef GENERATORYDANYCH_HH
#define GENERATORYDANYCH_HH

/*!
 *\file 
 *\brief Szablon funkcji generacji danych.
 *
 * Plik zawiera szablon funkcji generacji danych.
 */

using namespace std;

/*!
 *\brief Szablon metody generujacej wartosci losowe danego typu.
 *\param
 * l_danych - typu int, liczba generowanych danych.
 *\return
 * T* -wskaznik na dany typ, wskaznik na tablice z wygenerowanymi danymi.
 */
template<typename T>
T* generujdane(int l_danych);

#endif

/*!
 *\brief Metoda generujaca wartosci losowe danego typu.
 *\param
 * l_danych - typu int, liczba generowanych danych.
 *\return
 * *dane - typu string*, tablica z wygenerowanymi danymi(np.: Axb CtQ).
 */
