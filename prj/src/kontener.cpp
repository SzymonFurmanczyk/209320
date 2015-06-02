/*!
 *\file 
 *\brief Metody klasy.
 *
 * Plik zawiera metody klasy .
 */

#include "kontener.hh"

#define DVD_SIZE 4596992

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
    disk *tmp = new disk;
    disks.push_back(tmp);
  }
  
  while (!files_test.empty()) {
    bool added=false;
    for (it=disks.begin(); added==false ; ++it) {
      if (boost::get<0>(files_test.front()) > DVD_SIZE) {
        files_test.erase(files_test.begin());
	added=true;
      }
      else if ((*it)->size + boost::get<0>(files_test.front()) < DVD_SIZE) {
	(*it) -> size += boost::get<0>(files_test.front());
	(*it) -> files.push_back(boost::get<1>(files_test.front())); //wrzucanie nazwy pliku
	files_test.erase(files_test.begin());
	added=true;
      }
      else if ((*it)==disks.back()){
	disk *tmp = new disk();
	disks.push_back(tmp);
      }
    }
  }
  std::cout<<"Ulozono dane."<<std::endl;
}

void container::load() {
  std::fstream file_in;
  file_in.open("zbior_danych.txt", std::ifstream::in);
  while (file_in.peek()!=EOF) {
      long tmp1;
      std::string tmp2;
      file_in >> tmp1;
      getline(file_in,tmp2);
      tmp2.erase(0,1);
      boost::tuple<long, std::string> tmp(tmp1, tmp2);
      files_test.push_back(tmp);
    }
  file_in.close();
  std::cout<<"Wczytano rozmiary plikow."<<std::endl;
}



void container::save() {
  std::ofstream file_out;
  file_out.open("rozklad.txt", std::ofstream::out | std::ofstream::trunc);
  while (!disks.empty()) {
    file_out << "Plyta nr " << disks.size() << std::endl;
    disk *tmp = disks.front();
    file_out << DVD_SIZE-tmp->size << std::endl;
    while (!(tmp -> files.empty())) {
      std::string tmpp = (tmp -> files.front());
      file_out << (tmpp)<<std::endl;
      tmp->files.pop_front();
    }
    file_out << std::endl;
    disks.pop_front();
  }
  file_out.close();
  std::cout<<"Zapisano konfiguracje ulozenia danych na dyski."<<std::endl;
}
