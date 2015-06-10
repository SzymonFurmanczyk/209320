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
  void pack();
  void save();
  void show();

};


struct node
{
  long value;
  int position; //0-left  1-right
  node *up;
  node *left;
  node *right;
};


struct choosetree
{
  node *root;
  int size;
  
  bool split(std::list<node*> &,long);
  void deleteroot();
  void deletenode(node *iter);
};


#endif
