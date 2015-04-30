/*!
 *\file 
 *\brief Modul glowny.
 *
 * Plik zawiera funkcje main.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Benchmark.hh"
#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "ArrayLista.hh"
#include "HaszTab.hh"

using namespace std;


/*!
 *\brief Funkcja glowna programu.
 */
int main(int argc, char *argv[])
{
  ofstream plik;

  int l_przejsc;
  int l_danych;

  long int sredni_czas_hasztab=0;

  string *dane;

  Benchmarker Test;

  if(argc!=3 and argc!=1)
    {
      cout<<"Nieprawidlowe wywolanie"<<endl;
      return 0;
    }
  if(argc==3)
    {
      l_przejsc=atoi(argv[1]);
      l_danych=atoi(argv[2]);
    }
  if(argc==1)
    {
      l_przejsc=10;
      l_danych=5000;
    }

  
  dane=Test.generujdane(l_danych);
  dane=Test.generujdane_string(l_danych);
  


/*
  plik.open("benchmark_hasz_tab.csv");


  for(int k=0;k<=l_danych;k+=50)
    {
      HaszTab *implem_hasztab=new HaszTab;

      sredni_czas_hasztab=Test.testuj(implem_hasztab,dane,l_przejsc,k);

      implem_hasztab->~HaszTab();
     
      //cout<<k<<" "<<sredni_czas_hasztab<<endl;    
      plik<<k<<","<<sredni_czas_hasztab<<"\n";
    }
 

  plik.close();

  //http://www.codeproject.com/Articles/328365/Understanding-and-Implementing-Observer-Pattern

  */

//notify benchmarku
/*
aktualizuj(int,int)
 */


  //Przenieść do aktualizuj Observatora
  /*
  plik.open("benchmark_....csv");
  plik<<k<<","<<sredni_czas_...<<"\n";
  plik.close()
   */
  
  Lista *implem_lista=new Lista;
  Stos *implem_stos=new Stos;
  Kolejka *implem_kolejka=new Kolejka;
  ArrayLista *implem_array_lista=new ArrayLista;
  HaszTab *implem_hasztab=new HaszTab;
  
  Test.podlacz_obs(&implem_lista); 
  Test.testuj();
  Test.odlacz_obs();

  Test.podlacz_obs(...);
  Test.testuj();
  Test.odlacz_obs();

  Test.podlacz_obs(...);
  Test.podlacz_obs(...);
  Test.podlacz_obs(...);

  
  
  return 0;
}
