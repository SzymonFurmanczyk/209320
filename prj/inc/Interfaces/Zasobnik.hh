#ifndef ZASOBNIK_HH
#define ZASOBNIK_HH

using namespace std;

template<typename T>
class Zasobnik
{ 
public:
  virtual ~Zasobnik();
  virtual void push(T)=0;
  virtual T pop()=0;
  virtual int size()=0;
};


#endif
