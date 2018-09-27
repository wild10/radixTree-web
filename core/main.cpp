#include <iostream>
#include <sstream>
//#include <boost/property_tree/json_parser.hpp>
#include "tree.h"

using namespace std;

int main(int argc, char *argv[]) {
      int *word;
      int *start;
      Tree *t=new Tree();
      int a,b,c,d;

      t->add("AB",a,b);
      t->add("CA",a,b);
      t->add("CASA",a,b);
      t->add("CAMA",a,b);
      t->add("CASAS",a,b);
      //t->add("CAPITAN",a,b);
      //t->add("CASA",a,b);
      //t->add("CASA",a,b);
      //t->add("CAMA",a,b);
      //t->add("CANTO",a,b);
      //t->add("CASADO",a,b);
      //cout<<t->find("CAMAS")<<endl;
      cout << t->printjson()<<endl;
      t->erase("CA");
      t->erase("CAMA");
      t->erase("CASA");
      cout <<t->graphviz() << '\n';
      cout << t->printjson()<<endl;
    return 0;
}
