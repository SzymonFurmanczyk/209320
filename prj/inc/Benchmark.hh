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
  long long int * czasy;

public:
  Benchmarker();
  ~Benchmarker();

  long long int testuj(int*,int*,int,int);
  int* generuj_dane(int);

};


#endif
