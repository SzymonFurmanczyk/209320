#ifndef GENERATORYDANYCH_HH
#define GENERATORYDANYCH_HH

using namespace std;

/*!
 *\brief Metoda generujaca wartosci losowe z przedzialu 0 10000.
 *\param
 * l_danych - typu int, liczba generowanych danych.
 *\return
 * *dane - typu long int*, tablica z wygenerowanymi danymi.
 */
//int* generujdane(int l_danych);

template<typename T>
class Generatory
{
public:

/*!
 *\brief Metoda generujaca wartosci losowe z przedzialu A-Z + a-z.
 *\param
 * l_danych - typu int, liczba generowanych danych.
 *\return
 * *dane - typu string*, tablica z wygenerowanymi danymi(np.: Axb CtQ).
 */
T* generujdane(int l_danych);

};

#endif
