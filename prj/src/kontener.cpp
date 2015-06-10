/*!
 *\file 
 *\brief Metody klasy.
 *
 * Plik zawiera metody klasy .
 */

#include "kontener.hh"

#define DVD_SIZE 4707319808 //B

std::string container::execute_cmd(const std::string& _string)
{
  std::string result, file;
  FILE* pipe{popen(_string.c_str(), "r")};
  char buffer[256];

  while(fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
      file = buffer;
      result += file.substr(0, file.size() - 1);
    }

  pclose(pipe);
  return result;
}

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


void container::show()
{
  
  sf::RenderWindow window(sf::VideoMode(1024, 800), "Ulozenie plikow:",sf::Style::Close);

  sf::RectangleShape shape(sf::Vector2f(0, 50));
  shape.setFillColor(sf::Color(0, 150, 0));
  shape.setPosition(0,0);
  shape.setOutlineThickness(1);
  shape.setOutlineColor(sf::Color(250, 250, 250));

  sf::Font font;
  font.loadFromFile("DejaVuSans.ttf");
  sf::Text text("", font, 30);
  sf::Text text2("", font, 20);

  sf::View view(sf::FloatRect(0, 0, 1024, 800));
  window.setView(view);
  window.display();

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
	{
	  switch(event.type)
	    {
	    case  sf::Event::Closed:
	      window.close();
	      break;

	    default:
	    case sf::Event::MouseWheelMoved:
	      if(view.getCenter().y+event.mouseWheel.delta*-20 >= 400)
		{
		  view.move(0,event.mouseWheel.delta*-20);

		  if(view.getCenter().y>=400)
		    {
		      window.setView(view);
		      window.clear();
		      std::list<disk*>::iterator it;
		      int i=0;
		      int koniec=0;
		      for (it=disks.begin();koniec!=1; it++)
			{
			  if(it==disks.end())
			    {
			      text.setString("Nieumieszczone:");
			      text.setPosition(sf::Vector2f(0,i*55));
			      window.draw(text);
			      std::list<std::string>::iterator iter=litter.begin();
			      int j=i;
			      while(iter!=litter.end())
				{
				  text2.setString(*iter);
				  text2.setPosition(sf::Vector2f(0,i*55+j*25));
				  window.draw(text2);
				  iter++;
				  j++;
				}
			      
			      koniec=1;
			    }
			  else
			    {
			      shape.setPosition(0,i*55);
			      shape.setSize(sf::Vector2f(((*it)->size*1024)/DVD_SIZE, 50));

			      if((*it)->size>=DVD_SIZE-19)
				{
				  shape.setFillColor(sf::Color(0, 150, 0));
				}
			      else
				{
				  shape.setFillColor(sf::Color(150, 0, 0));
				}
			      window.draw(shape);

			      std::stringstream ss;
			      ss<<"Dysk: " <<i<<" pozostalo miejsca: "<<DVD_SIZE-(*it)->size << "B";
			      std::string str = ss.str();
			      text.setString(str);
			      text.setPosition(sf::Vector2f(0,i*55));
			      window.draw(text);
			    }
			  i++;
			}
		    }
		}
	      break; 
	    }
        }
      window.display();
    }   
}


void container::pack()
{
  disks.clear();

  //wyrzucenie zbyt duzych plikow
  while (boost::get<0>(files_test.front()) > DVD_SIZE)
    { //jesli sie nie zmiesci to do kosza
      litter.push_back(boost::get<1>(files_test.front())); //nazwa
      files_test.erase(files_test.begin());
    }

  while (boost::get<0>(files_test.back()) ==0)
    { //jesli sie nie zmiesci to do kosza
      litter.push_back(boost::get<1>(files_test.back())); //nazwa
      files_test.erase(files_test.end());
    }

  std::list<node*> decision;
  std::vector<boost::tuple<long,std::string>>::iterator it=files_test.begin();
  long f_value=0;
  int found=0;
  
  while(!files_test.empty())
    {
      choosetree tree;
      tree.root=NULL;
      tree.size=0;
      
      it=files_test.begin();

      node *tmp=new node;
      tmp->value=boost::get<0>(*it);
      tmp->position=1;
      tmp->left=NULL;
      tmp->right=NULL;
      tmp->up=NULL;
      tree.root=tmp;
      tree.size++;
     
      decision.push_back(tree.root);
      it++;
      while(found!=1 && it!=files_test.end())
	{
	  f_value=boost::get<0>(*it);
	  found=tree.split(decision,f_value);
	  it++;
	}
      std::list<node*>::iterator it3=decision.begin();
      if(found!=1)
      	{
      	  std::list<node*>::iterator it2=decision.begin();
      	  if(decision.size()!=1)
      	    {
      	      it2++;
      	      while(it2!=decision.end())
      		{
      		  if((*it2)->value > (*it3)->value)
      		    {
      		      it3=it2;
      		    }
      		  it2++;
      		}
      	    }
      	}

      disk *label = new disk();
      disks.push_back(label);

      std::list<node*>::iterator road=it3;
      it--;
      while(*road!=NULL)
	{
	  if((*road)->position==1)
	    {
	      label -> size += boost::get<0>(*it); //rozmiar
	      label -> files.push_back(boost::get<1>(*it)); //nazwa
	      files_test.erase(it);
	    }
	  it--;
	  *road=(*road)->up;
	}
      decision.clear();
      tree.deleteroot();      
    }
  std::cerr << "Wykonano partycjonowanie drugie." << std::endl;
}

void choosetree::deleteroot()
{
  if(root!=NULL)
    {
      if(root->right!=NULL || root->left!=NULL)
	{
	  if(root->left!=NULL)
	    {deletenode(root->left);}
	  if(root->right!=NULL)
	    {deletenode(root->right);}
	}
      delete[] root;
      root=NULL;
      size=0;
    }
}


void choosetree::deletenode(node *iter)
{
  if(iter->right!=NULL || iter->left!=NULL)
    {
      if(iter->left!=NULL)
	{deletenode(iter->left);}
      if(iter->right!=NULL)
	{deletenode(iter->right);}
    }
  node* tmp;
  tmp=iter;
  delete[] tmp;
}



bool choosetree::split(std::list<node*> &decision,long f_value)
{
  std::list<node*>::iterator it=decision.begin();
  std::list<node*>::iterator it2=decision.end();
  std::list<node*> choices;
  while(it!=decision.end())
    {
      //lewe
      node *tmp=new node;
      tmp->value=(*it)->value;
      tmp->position=0;
      (*it)->left=tmp;
      tmp->up=*it;
      tmp->left=NULL;
      tmp->right=NULL;
      size++;
      if((*it)->value+f_value > (DVD_SIZE-150))
	choices.push_back(tmp);
      //prawe
      node *tmp2=new node;
      if((*it)->value+f_value <= DVD_SIZE)
	{
	  tmp2->value=(*it)->value+f_value;
	  tmp2->position=1;
	  (*it)->right=tmp2;
	  tmp2->up=*it;
	  tmp2->left=NULL;
	  tmp2->right=NULL;
	  tmp2->up=*it;
	  size++;
	  choices.push_back(tmp2);
	}
      else if((*it)->value+f_value == DVD_SIZE)
	{
	  choices.clear();
	  decision=choices;
	  decision.push_front(tmp2);
	  return 1;
	}
      it++;
    }
  decision.clear();
  decision=choices;
  return 0;
}
