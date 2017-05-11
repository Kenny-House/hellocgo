#ifndef _C_LIBLIB_HPP
#define _C_LIBLIB_HPP

#include <string>
using namespace std;

class Person
{
  public:
    void Speak();
    Person(string name);
  private:
    string name;
    int goId;
};

#endif //_C_LIBLIB_H