/*!
 *\file 
 *\brief Metody klasy.
 *
 * Plik zawiera metody klasy .
 */

#include "kontener.hh"

#define DVD_SIZE 4707319808

void container::sort()
{
  std::sort(files_test.begin(), files_test.end(),
	    [](const boost::tuple<long, std::string>& a,
	       const boost::tuple<long, std::string>& b) -> bool
	    {
	      return boost::get<0>(a) > boost::get<0>(b);
	    });
  std::cerr << "Wykonano sortowanie." << std::endl;
}


void container::partition()
{
  std::list<disk*>::iterator it;

  if (disks.empty())
    { //jesli nie mamy zadnej plyty
      disk *tmp = new disk();
      disks.push_back(tmp);
    }

  while (true)
    {
      if (files_test.empty()) break;
      bool added = false;
      for (it=disks.begin(); added == false; ++it)
	{
	  if (boost::get<0>(files_test.front()) > DVD_SIZE)
	    { //jesli sie nie zmiesci to do kosza
	      litter.push_back(boost::get<1>(files_test.front())); //nazwa
	      files_test.erase(files_test.begin());
	      added = true;
	    }
	  else if ((*it) -> size + boost::get<0>(files_test.front()) < DVD_SIZE)
	    { //jesli sie zmiesci to zapisujemy
	      (*it) -> size += boost::get<0>(files_test.front()); //rozmiar
	      (*it) -> files.push_back(boost::get<1>(files_test.front())); //nazwa
	      files_test.erase(files_test.begin());
	      added = true;
	    }
	  else if ((*it) == disks.back())
	    { //tworzymy nowa plyte i probujemy jeszcze raz
	      disk *tmp = new disk();
	      disks.push_back(tmp);
	    }
	}
    }
  std::cerr << "Wykonano partycjonowanie." << std::endl;
}

void container::load()
{
  std::fstream file_in;
  file_in.open("zbior_danych.txt", std::ifstream::in);
  while (true)
    {
      if (file_in.eof()) break;
      long tmp1;
      std::string tmp2;
      file_in >> tmp1;
      getline(file_in, tmp2);
      tmp2.erase(0,1);
      boost::tuple<long, std::string> tmp(tmp1, tmp2);
      files_test.push_back(tmp);
    }
  file_in.close();
  std::cerr << "Wczytano rozmiary plikow." << std::endl;
}



void container::save()
{
  std::ofstream file_out;
  file_out.open("rozklad.txt", std::ofstream::out | std::ofstream::trunc);
  while (!disks.empty())
    {
      file_out << "Plyta nr " << disks.size() << std::endl;
      disk *tmp1 = disks.front();
      file_out << "Zajety rozmiar: " << tmp1 -> size << " B" << std::endl;
      while (!(tmp1 -> files.empty()))
	{ //dopoki nie oproznimy plyty
	  std::string tmp2 = (tmp1 -> files.front());
	  tmp1 -> files.pop_front();
	  file_out << (tmp2);
	  file_out << std::endl;
	}
      //po oproznieniu wywalamy plyte
      disks.pop_front();
      file_out << std::endl;
    }
  //jesli jest cos w koszu
  if (!litter.empty()) file_out << "Nierozmieszczone:" << std::endl;
  while (!litter.empty())
    { //dopoki kosz nie jest pusty
      std::string tmp3 = litter.front();
      litter.pop_front();
      file_out << tmp3;
      file_out << std::endl;
    }
  file_out.close();
  std::cerr << "Zapisano konfiguracje ulozenia danych na dyski." << std::endl;
}
