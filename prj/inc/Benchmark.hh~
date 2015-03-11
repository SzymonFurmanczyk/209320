#ifndef BENCHMARKER_HH
#define BENCHMARKER_HH

/*!
 *\file 
 *\brief Definicja klasy Benchmark.
 *
 * Plik zawiera definicje klasy Benchmark.
 */


using namespace std;

/*!
 *\brief Modeluje pojecie manipulatora.
 */
class Manipulator:public Przeszkoda
{
  

public:
  Manipulator(Punkt ,string);
  ~Manipulator();

  double SumujKaty(int ile);
  void WyliczPrzeguby();

  void InicjalizujOgniwa();

  void ZapoczatkujGlowny(string);

  void WykonujPrzemieszczenia(string);

  istream& WczytajKonfiguracje(istream&);
  ostream& WypiszKonfiguracje(ostream&);

  istream& WczytajPosture(istream&);
  ostream& WypiszPosture(ostream&);

  ostream& WypiszPrzeguby(ostream&);
  ostream& WypiszPrzegubyCzysto(ostream&);

  void Inicjalizuj(vector<Punkt>& c){};
  void Inicjalizuj(string,string);
  void WypiszCzysto(string);
  bool SprawdzPrzecinaniePrzeszkody(Manipulator*);
  bool SprawdzZOdcinkiem(Odcinek);
};

#endif
