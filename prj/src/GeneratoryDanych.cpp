/*!
 *\file 
 *\brief Metody klasy .
 *
 * Plik zawiera metody klasy .
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

#include "GeneratoryDanych.hh"

template<>
int* generujdane(int l_danych)
{
  int *dane=new int[l_danych];
  srand(time(NULL));
  for(int i=0;i<=l_danych;i++)
    {
      dane[i]=rand() %10;
    }
  return dane;
}

template<>
string* generujdane(int l_danych)
{
  int l_liter=52;
  string litery[]={"A","a","B","b","C","c","D","d","E","e","F","f","G","g",
		   "H","h","I","i","J","j","K","k","L","l","M","m","N","n",
		   "O","o","P","p","Q","q","R","r","S","s","T","t","U","u",
		   "V","v","W","w","X","x","Y","y","Z","z"};

  string *dane=new string[l_danych];

  srand(time(NULL));

  for(int i=0;i<l_danych;i++)
    {
      for(int j=0;j<6;j++)
	{
	  dane[i]=dane[i]+litery[rand() % l_liter];
	}
      
      dane[i]=dane[i]+" ";
      
      for(int j=0;j<6;j++)
	{
	  dane[i]=dane[i]+litery[rand() % l_liter];
	}
    }

  return dane;
}

