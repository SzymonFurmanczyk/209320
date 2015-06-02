#ifndef KONTENER_HH
#define KONTENER_HH

#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

#include "boost/tuple/tuple.hpp"

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


#endif
