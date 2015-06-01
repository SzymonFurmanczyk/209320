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

#include "boost/tuple/tuple.hpp"

#define DVD_SIZE 4707319808


struct disk {
  std::list<std::string> files;
  long size = 0;
};



struct container {
  std::vector<boost::tuple<long ,std::string>> files_test;
  std::list<disk*> disks; 


  void sort();
  void partition();
  void load();
  void save();

};

void container::sort() {

std::sort(files_test.begin(), files_test.end(),
	    [](const boost::tuple<long, std::string>& a,
		 const boost::tuple<long, std::string>& b) -> bool
{
return boost::get<0>(a) > boost::get<0>(b);
});
}


void container::partition() {
  std::list<disk*>::iterator it;

  if (disks.empty()) {
    disk *tmp = new disk();
    disks.push_back(tmp);
  }

  while (!files_test.empty()) {
    for (it=disks.begin(); it!=disks.end(); ++it) {
      if (boost::get<0>(files_test.front()) > DVD_SIZE) {
        files_test.erase(files_test.begin());
      }
      else if ((*it)->size + boost::get<0>(files_test.front()) < DVD_SIZE) {
	(*it) -> size += boost::get<0>(files_test.front());
	(*it) -> files.push_back(boost::get<1>(files_test.front())); //wrzucanie nazwy pliku
        files_test.erase(files_test.begin());
      }
      else {
	disk *tmp = new disk();
	disks.push_back(tmp);
      }
    }
  }
}

void container::load() {
  std::ifstream file_in;
  file_in.open("zbior_danych.txt", std::ifstream::in);
  while (!file_in.eof()) {
      long tmp1;
      std::string tmp2;
      file_in >> tmp1;
      file_in >> tmp2;
      boost::tuple<long, std::string> tmp(tmp1, tmp2);
      
      files_test.push_back(tmp);
    }
  file_in.close();
}



void container::save() {
  std::ofstream file_out;
  file_out.open("rozklad.txt", std::ofstream::out | std::ofstream::trunc);
  while (!disks.empty()) {
    file_out << "Plyta nr " << disks.size() << std::endl;
    disk *tmp = disks.front();
    while (!(tmp -> files.empty())) {
      std::string tmpp = (tmp -> files.front());
      file_out << (tmpp);
      file_out << std::endl;
    }
    disks.pop_front();
  }
  file_out.close();
}
