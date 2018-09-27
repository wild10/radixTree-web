#ifndef TREE_H
#define TREE_H

#define MAX_SIZE_OPTIONS 10
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#include <algorithm>
#include <climits>
#include "node.h"
#include <random>
#include <time.h>
#include <string>
//#include <stream>



class Tree {
private:
    Node * root;
    bool shouldPrint;
public:
    Tree() {
        // string str = "";
        // root = new Node(str, false);
        root = 0;
        shouldPrint = false;
    }

    void printSons (Node * & node) {
        cout << "*** node: " << node << " ***" << endl;
        for (int i = 0; i < ALPHABET_LENGTH; i++) {
            if (node->sons[i]) {
                cout << "i: " << c(i) << " = " << node->sons[i] << endl;
            }
        }
    }

    void printSons() {
        // printSons(root->sons[p('H')]);
        printSons(root);
    }





    void getWords(Node * & node, vector<string> *dictionary){
        if(dictionary->size() < MAX_SIZE_OPTIONS){

            if(node->isWord)
                dictionary->push_back(node->str);

            vector<string> *temp = new vector<string>();

            for (size_t i = 0; i < ALPHABET_LENGTH; i++)
                if (node->sons[i])
                    getWords(node->sons[i], temp);

            int toFill = MAX_SIZE_OPTIONS - dictionary->size();
            int realTemp = temp->size() > MAX_SIZE_OPTIONS ? toFill : (temp->size() > toFill ? toFill : temp->size());

            for (size_t i = 0; i < realTemp; i++)
                dictionary->push_back(node->str+(*temp)[i]);
        }
    }



    bool find(string str, Node * & node) {
        node = root; 
        Node * next;
        string prevStr = str; //palabra a buscar
        size_t result,position = 0;

        while (node) {
          result = node->contains(str, position); // position of p
          prevStr = str;
          str = str.substr(position);
          next = node->sons[p(str[0])];
          if (str.size() && next) {
              node = next;
          } else {
              break;
          }
        }
        if ((prevStr == node->str) && node->isWord) {
        // cout<<"isword: "<<prevStr <<" ="<<node->str<<" : "<< node->isWord<<"- "<<endl;
        // if(prevStr == node->str){
            return true;
        
        }
        return false;
    }

  bool find(string word){
    Node * node;
    return find(word,node);
  }

    size_t find(
            string & str,
            Node * & node,
            Node * & parent,
            size_t & position
        ) {
        position = 0;
        parent = 0;
        node = root;
        size_t result;
        while (node) {
            result = node->contains(str, position);
            if (shouldPrint) {
                cout << "str: " << str << endl;
                cout << "result: " << result << endl;
                cout << "pos: " << position << endl;
            }
            if (result == SPLIT_1) {
                str = str.substr(position);
                Node * next = node->sons[p(str[0])];

                if (shouldPrint) {
                    printSons(node);
                    cout << "=> node: " << node->str << endl;
                    cout << "next: " << next << " ";
                }

                if (next) {
                    if (shouldPrint) {
                        cout << "[" << next->str << "]";
                    }
                    parent = node;
                    node = next;
                    if (shouldPrint) cout << endl;
                } else {
                    if (shouldPrint) cout << endl;
                    break;
                }
            } else if (result == SPLIT_2) {
                break;
            } else if ( ! result ) {
                break;
            } else if ( result == 3) {
                break;
            } else if ( result == 4 ) {
                break;
            }
        }
        return result;
    }

    void graphviz(Node * & node, string & tree) {
        if ( ! node) {
            return;
        }
        string name;
        char ss[100];
        sprintf(ss, "\"%p\"", node);
        name = ss;
        if (node->parent) {
            string parentStr = "\"\"";

            if (node->parent->str != "") {
                char sp[100];
                sprintf(sp, "\"%p\"", node->parent);
                parentStr = sp;
            }

            tree += parentStr + " -> " + name + "\n";
        }
        if (node->isWord) {
            tree += name + " [" + "color = cyan style = filled label = " + node->str + "]\n";
        } else if(node->str != "") {
            tree += name + " [" + "label = " + node->str + "]\n";
        }

        for (size_t i = 0; i < ALPHABET_LENGTH; i += 1) {
            graphviz(node->sons[i], tree);
        }
    }

    string graphviz(){
        //Node * node;
        string str = "digraph G {\n";
        string tree = "";
        graphviz(root, tree);
        str += tree + "}";
        return str;
    }

    void printjson(Node * & node, string & tree) {
        if ( ! node) {
            return ;
        }
        string name;
        char ss[100];
        sprintf(ss, "\"%p\"", node);
        name = ss;
        string parentStr;

        if (node->parent) {
            parentStr = "\"\"";
            //if (node->parent->str != "") {
                char sp[100];
                sprintf(sp, "\"%p\"", node->parent);
                parentStr = sp;
            //}
        }
        if (node->isWord) {

            // cout<<" --> "<<parentStr<<endl;
            if(parentStr == "") parentStr = "\"\"";
            tree +="{\"valor\":\"" +node->str + "\",\"id\":"+name + ",\"padre\":"+parentStr+"},";
        }else{
             // cout<<" --> "<<parentStr<<endl;
            if(parentStr == "") parentStr = "\"\"";
            tree +="{\"valor\":\"" +node->str + "\",\"id\":"+name + ",\"padre\":"+parentStr+"},";
        }

        for (size_t i = 0; i < ALPHABET_LENGTH; i += 1) {
            printjson(node->sons[i], tree);
        }
    }

    string printjson(){
      string str = "{";
      string temp = "\"tree\":[";
      printjson(root, temp);
      size_t tam=temp.length();
      temp.pop_back();
      str += temp + "]}";
      
      return str;
    }

    void print (Node * & node) {
        if ( ! node) {
            return;
        }
        cout << '"' << node->str << '"' << "(" << node->isWord << ")";

        if (node->parent) {
            cout << " >- (" << node->parent->str << ")";
        } else {
            cout <<  " >- root";
        }
        cout << endl;

        for (size_t i = 0; i < ALPHABET_LENGTH; i += 1) {
            print(node->sons[i]);
        }
    }

    void print () {
        print(root);
    }


    /*string wordrandom(){
      rand(NULL);

    }*/

    void add(string str, int & word, int & start) {
        // string str;
        //cout<<"word "<<&word<<endl;
        if ( ! root) {
            root = new Node(word, str, true, start);
            //cout << "root: " << str << endl;
            return;
        }
        Node * node;
        Node * parent;
        size_t position;

        size_t kase = find(str, node, parent, position);
        if (shouldPrint) {
            cout << "+++: " << str << endl;
            cout << "kase: " << kase << endl;
            cout << "node: " << node->str << " - " << node << endl;
            cout << "parent: " << parent << endl;
        }
        if (kase == NOT_FOUND) {
            createEmptyRoot(word, str, start);
        } else if (kase == SPLIT_2) {
            splitNode(word, node, str, position, start);
        } else if (kase == SPLIT_1) {
            // cout << "split 1" << endl;
            createNode(word, node, str, start);
        } else if (kase == INSIDE) {
            createNode(word, node, str, position, start);
        } else if (kase == FOUND) {
            node->isWord = true;
            //node->directory[word].pagerank += 1;
            //if (node->directory[word].start == 0) {
              //  node->directory[word].start = start;
            //}
        }

    }

private:
    void createEmptyRoot(int & word, string & str, int & start) {
        if (root->str != "") {
            Node * tmp = root;
            root = new Node();
            root->sons[p(tmp->str[0])] = tmp;
            tmp->parent = root;
        }

        Node * newNode = new Node(word, str, true, start);
        root->sons[p(str[0])] = newNode;
        newNode->parent = root;
    }
    void createNode(
            int & word,
            Node * & node,
            string & str,
            size_t position,
            int & start
        ) {
        string res = node->reverseCut(position);
        Node * newParent = new Node(word, res, true, start);
        Node * grandparent = node->parent;
        if (node == root) {
            root = newParent;
        } else {
            grandparent->sons[p(node->str[0])] = 0;
            grandparent->sons[p(newParent->str[0])] = newParent;
        }
        newParent->parent = grandparent;
        newParent->sons[p(node->str[0])] = node;
        node->parent = newParent;
    }

    void createNode(int & word, Node * & node, string & str, int & start) {
        Node * newNode = new Node(word, str, true, start);
        node->sons[p(str[0])] = newNode;
        newNode->parent = node;
    }

    void splitNode(
            int & word,
            Node * & node,
            string & str,
            size_t position,
            int & start
        ) {
        if (shouldPrint) cout << "splitting: " << (node == root) << endl;
        if (shouldPrint) cout << "node: " << node->parent->str << endl;
        char nodeIndex = node->str[0];
        string res = node->reverseCut(position);
        Node * newParent = new Node(word, res, false, start);
        Node * parent = node->parent;
        if (node == root) {
            root = newParent;
        } else {
            parent->sons[p(nodeIndex)] = 0;
            parent->sons[p(newParent->str[0])] = newParent;
        }
        newParent->parent = node->parent;

        if (shouldPrint) {
            cout << "node->parent: " << node->parent->str << endl;
            cout << "newParent->parent: " << newParent->parent->str << endl;
        }
        newParent->sons[p(node->str[0])] = node;
        node->parent = newParent;


        string substr = str.substr(position, str.size());
        Node * second = new Node(word, substr, true, start);
        newParent->sons[p(substr[0])] = second;
        second->parent = newParent;

        // node->isWord = false;
    }

};

#endif // TREE_H
