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
 *\brief klasa benchmarku.
 */
class Benchmarker
{
  int * czasy;

public:
  Benchmarker();
  ~Benchmarker();

  int testuj(int*,int*,int,int);
  int* generuj_dane(int);

};


#endif
