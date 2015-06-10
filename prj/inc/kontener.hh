#ifndef KONTENER_HH
#define KONTENER_HH

#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "boost/tuple/tuple.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

struct disk
{
  std::list<std::string> files;
  long size = 0;
};

struct container
{
  std::vector<boost::tuple<long ,std::string>> files_test;
  std::list<disk*> disks;
  std::list<std::string> litter;

  std::string execute_cmd(const std::string& _string);
  void load();
  void sort();
  void partition();
  void save();
  void show();

};


#endif
