#include <iostream>
#include <sstream>
#include "tree.h"

using namespace std;

int main(int argc, char *argv[]) {

      int *word;
      int *start;
      Tree *t=new Tree();
      int a,b,c,d;
      t->add("test",a,b);
      t->add("toast",a,b);
      t->add("toasting",a,b);
      t->add("slow",a,b);
      t->add("slowly",a,b);
      // t->add("BANANA",a,b);
    cout << "arbol " << t->graphviz()<<endl;
    // cout << t->printjson()<<endl;

    return 0;
}
