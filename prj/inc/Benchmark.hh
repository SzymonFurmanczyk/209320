#ifndef BENCHMARK_HH
#define BENCHMARK_HH

/*!
 *\file 
 *\brief Definicja klasy Benchmark.
 *
 * Plik zawiera definicje klasy Benchmark.
 */

using namespace std;

/*!
 *\brief Klasa benchmarku.
 */
class Benchmarker
{
public:
  long int testuj(int*,int*,int,int);
  int* generuj_dane(int);
};


#endif
