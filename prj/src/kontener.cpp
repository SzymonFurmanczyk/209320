/*!
 *\file 
 *\brief Metody klasy.
 *
 * Plik zawiera metody klasy .
 */

#include "kontener.hh"
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

#define DVD_SIZE 4707319808
 
// #include "boost/config.hpp"
// #include "boost/tuple/tuple.hpp"

// #define BOOST_USER_CONFIG <boost/config/user.hpp>

// template<int M, template<typename> class F = std::less>
// struct TupleCompare
// {
//     template<typename T>
//     bool operator()(T const &t1, T const &t2)
//     {
//         return F<typename tuple_element<M, T>::type>()(std::get<M>(t1), std::get<M>(t2));
//     }
// };

// std::sort(begin(files),end(files),
// 	  [](files<int,std::string> const &t1, files<int,std::string> const &t2) {
// 	    return get<0>(t1) < get<0>(t2);
// 	  };



struct plyta
{
  std::list<std::string> pliki;
  int rozmiar=0;
};



struct kontener {


  //std::vector<boost::tuple<int ,std::string>> files;
  std::list<int> files;
  std::list<plyta*> discs; 


  void sort();
  void splitter();
  void load();
  void save();


};

// void kontener::sort()
// {

//   std::sort(files.begin(), files.end(), TupleCompare<0>());

// }


void kontener::splitter()
{
  std::list<plyta*>::iterator it;

  if(discs.empty())
    {
      plyta *tmp=new plyta();
      discs.push_back(tmp);
    }

  while(!files.empty())
    {
      
      for(it=discs.begin();it!=discs.end();it++)
	{
	  if(files.front()>DVD_SIZE)
	    {
	      files.pop_front();
	    }
	  else if((*it)->rozmiar+files.front()<DVD_SIZE)
	    {
	      (*it)->rozmiar+=files.front();
	      (*it)->pliki.push_back("string"); //wrzucanie nazwy pliku
	      files.pop_front();
	    }
	  else
	    {
	      plyta *tmp=new plyta();
	      discs.push_back(tmp);
	    }
	}
    }
  
}

void kontener::load()
{
  std::ifstream plik;
  plik.open("zbior_danych.txt", std::ifstream::in);
  while(!plik.eof())
    {
      int tmp;
      plik>>tmp;
      files.push_back(tmp);
    }

  plik.close();
}



void kontener::save()
{
  std::ofstream plik;
  plik.open("ulozenie.txt", std::ofstream::out | std::ofstream::trunc);
  while(!discs.empty())
    {
      plyta *tmp=discs.front();
      while(!(tmp->pliki.empty()))
	{
	  // plik<<(tmp->pliki.pop_front());

	}
      discs.pop_front();
    }

  plik.close();


}
