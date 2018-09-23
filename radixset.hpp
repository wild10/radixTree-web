#ifndef radixset_hpp
#define radixset_hpp

#include <string>
#include <iostream>

using namespace std;

// class radixset{
//   public:
//     string str;
//   public:
//
//     void respuestaHola(string str){
//       this -> str += " Mundo";
//     }
// };

class radixset {
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

};

#endif
