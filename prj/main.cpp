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
  Test.load();
  Test.sort();
  Test.partition();
  Test.save();
    
  
  
  return 0;
}
