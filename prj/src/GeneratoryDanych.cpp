/*!
 *\file 
 *\brief Funkcje generacji danych.
 *
 * Plik zawiera funkcje generacji danych .
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
  int *dane=new int[l_danych+1];
  srand(time(NULL));

  for(int i=0;i<=l_danych;i++)
    {
      dane[i]=rand() %1000;
    }
  return dane;
}


template<>
int* generujdane2(int l_danych)
{
  int *dane=new int[l_danych*3+3];

  srand(time(NULL));

  dane[0]=rand() %2000;
  dane[1]=rand() %2000;
  dane[2]=1;


    for(int i=3;i<=l_danych*3+3;i+=3)
      {
	dane[i]=dane[i-2];
	dane[i+1]=rand() %2000;
	dane[i+2]=1;
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

