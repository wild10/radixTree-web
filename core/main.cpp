#include <iostream>
#include <sstream>
#include "tree.h"

using namespace std;

int main(int argc, char *argv[]) {

      int *word;
      int *start;
      Tree *t=new Tree();
      int a,b,c,d;
      t->add("AB",a,b);
      t->add("CAMA",a,b);
      t->add("CASA",a,b);
      // t->add("SLOW",a,b);
      // t->add("SLOWLY",a,b);
      // t->add("BANANA",a,b);
    cout << "arbol " << t->graphviz()<<endl;
    // cout<<"AB"<<endl;
    // t->find("AB");
    // cout<<"CA"<<endl;
    // t->find("CA");
    // cout<<"SA"<<endl;
    // t->find("SA");
    // cout<<"MA"<<endl;
    // t->find("MA");
    cout<< "FIND :" <<t->find("AC")<<endl;

    // if(!t->find("TEST"))
    //   cout<<"WORD NOT FOUND"<<endl;
    // else
    //   cout <<"WORD FOUND :"<<"BANANA"<<endl;

    return 0;
}
