#ifndef GENERATORYDANYCH_HH
#define GENERATORYDANYCH_HH

using namespace std;

/*!
 *\brief Metoda generujaca wartosci losowe z przedzialu A-Z + a-z.
 *\param
 * l_danych - typu int, liczba generowanych danych.
 *\return
 * *dane - typu string*, tablica z wygenerowanymi danymi(np.: Axb CtQ).
 */
template<typename T>
T* generujdane(int l_danych);

#endif
