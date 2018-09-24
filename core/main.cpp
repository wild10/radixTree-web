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
      t->add("A",a,b);
      t->add("NA",a,b);
      t->add("ANA",a,b);
      t->add("NANA",a,b);
      t->add("ANANA",a,b);
      t->add("BANANA",a,b);
    cout << "arbol " << t->graphviz()<<endl;
    cout << t->printjson()<<endl;


    cout << "encontro: "<< t->find("A")<<endl;
    cout << "encontro: "<< t->find("Z")<<endl;
    cout << "encontro: "<< t->find("ANANA")<<endl;

    cout << t->printjson()<<endl;
      //t->print();
      //stringstream  str;
      //str<<new Tree();
      //cout << ": " <<str<<'\n';
      //printf("ok: %i\n",&c);

    /*Parse *parse = new Parse("../../files/", 0);
    parse->processFile();

    int prev, next, total;
    double time;

    cout << "... Load index done! " << endl;
    cout << "====================================" << endl;
    cout << "   (⌐■_■)  ** ALTAVISTA ** (⌐■_■)" << endl;
    cout << "====================================" << endl;

    while(true) {
        string word;
        string result;
        prev = 0;
        next = 0;
        total = 0;
        time = 0;
        int start = 0;
        cout << "Enter your query: ";
        getline(cin, word);
        vector <Result> results;
        parse->find(word, results, total, next, prev, time, start, 30);

        while (true) {
            for (int i = 0; i < results.size(); i++) {
                cout << "[" << i + 1 << "] " << results[i].title << " | " << results[i].preview << endl;
                if (i > 5) {
                    break;
                }
            }
            if (results.size() > 5) {
                cout << "..." << endl;
            }
            cout << endl << "About: " << total << " results (" << time << " seconds)" << endl << endl;

            cout << "Do you want to open any result [n or result number]? Type 0 to go back to search  ";
            getline(cin, result);
            if (result == "0") {
                break;
            } else if (all_of(result.begin(), result.end(), ::isdigit)) {
                int index = atoi(result.c_str());
                if (index < 1 || index > total) {
                    cout << "**ERROR** Invalid result number " << endl;
                } else {
                    int docIdInt = results[index - 1].docNumber;
                    Document * doc = parse->getDocument(docIdInt);
                    cout << doc->title << endl;
                    cout << parse->getText(docIdInt, doc->start, doc->end) << endl << endl;
                }

            } else {
                cout << "**ERROR** not a valid number" << endl;
            }
            cout << endl;
        }


    }*/

    return 0;
}
