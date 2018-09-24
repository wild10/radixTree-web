#ifndef radixset_hpp
#define radixset_hpp

#include <string>
#include <iostream>
#include <string>

using namespace std;

class clasTest{
  public:
    string str;
  public:

    clasTest(){
      this -> str = "Mundo ";
    }

    clasTest(string pstr){
      this -> str = pstr;
    }
    void prueba(string pstr){
      this -> str += pstr;
    }
    string test(string ptexto){

      string text = "{\"tree\":[{\"0x558018a962a0\":\"A\"},{\"0x558018a96830\":\"NA\"},{\"0x558018a96c10\":\"NA\"},{\"0x558018a96e00\":\"BANANA\"},{\"0x558018a96640\":\"NA\"},{\"0x558018a96a20\":\"NA\"}]}";
      string texto = "{\"tree\": {\"0\": {\"valor\": \"A\"},\"1\": {\"valor\": \"NA\"},\"2\": {\"valor\": \"NA\"},\"3\": {\"valor\": \"BANANA\" }} }";
      string json = "{\"tree\": [{\"valor\": \"A\",\"id\": \"1234kljdfioa\",\"padre\": \"12341234089123\",\"hijo\": [{\"id\": \"212fdjalfj\",\"valor\": \"PEPE\"}] }, {\"valor\": \"NA\", \"id\": \"1234kljdfioa\", \"padre\": \"12341234089123\" }]}";
      return json;
   }
};

/*class radixset {
public:
   string text;

  radixset(string ptext){
      this->text = ptext+" hola";
  }
   radixset() : isword(false), children(nullptr) { }

   ~radixset() {
      if (children != nullptr) {
         for(auto i = 0; i < 256; i++) {
            delete children[i];
         }
         delete children;
      }
   }

   int prueba(string str){
      this-> text += str;
   }

   void insert(std::string str) {
      radixset* node = this;
      for (unsigned char c : str) {
         if (node->children == nullptr) {
            node->children = new radixset*[256];
         }
         node->children[c] = new radixset;
         node = node->children[c];
      }
      node->isword = true;
   }


   bool contains(std::string str) {
      radixset* node = this;
      for (unsigned char c : str) {
         if (node == nullptr || node->children == nullptr) {
            return false;
         }
         node = node->children[c];
      }
      return node->isword;
   }

private:
   bool isword;
   radixset** children;

};*/

#endif
