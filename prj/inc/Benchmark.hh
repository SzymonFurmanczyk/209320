#ifndef BENCHMARK_HH
#define BENCHMARK_HH

/*!
 *\file 
 *\brief Definicja klasy Benchmarker.
 *
 * Plik zawiera definicje klasy Benchmarker.
 */

using namespace std;

/*!
 *\brief Klasa Benchmarker.
 */
class Benchmarker
{
public:

  template <class T>  long int testuj(T*,int*,int,int);
  int *generujdane(int);
};


#endif
