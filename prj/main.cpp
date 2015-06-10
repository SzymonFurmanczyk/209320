/*!
 *\file 
 *\brief Modul glowny.
 *
 * Plik zawiera funkcje main.
 */


#include "kontener.hh"


/*!	
*\brief Funkcja glowna programu.
 */
int main(int argc, char *argv[])
{

  container Test;
  Test.execute_cmd(R"( du > zbior_danych_test.txt )");
  Test.load();
  Test.sort();
  Test.partition();
  Test.show();
  Test.save();
  
  return 0;
}
