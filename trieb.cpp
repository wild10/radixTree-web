#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
	int prefix_count;
	bool isEnd;
	node *child[26];
}*head;

void init()
{
	head = new node();
	head->isEnd = false;
	head->prefix_count = 0;
}

void insert(string word)
{
	node *current = head;
	current->prefix_count++;

	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';	//extrae el primer caracter de la palabra
		if(current->child[letter] == NULL){
			current->child[letter] = new node();		
			print(current->child[letter]);
		}
		current->child[letter]->prefix_count++;
		current = current->child[letter];		
	}
	current->isEnd = true;
	
}

void print(node * charact){
		printf("	caracter:	\n", );			
}


bool search(string word)
{
	node *current = head;
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';
		if(current->child[letter] == NULL)
			return false;		//not found
		current = current->child[letter];
	}
	return current->isEnd;
}

int words_with_prefix(string prefix)
{
	node *current = head;
	for(int i = 0; i < prefix.length() ; ++i)
	{
		int letter = (int)prefix[i] - (int)'a';
		if(current->child[letter] == NULL)
			return 0;
		else
			current = current->child[letter];
	}
	return current->prefix_count;
}


int main()
{
	init();
	string s = "test";
	insert(s);
	s = "toaster";
	insert(s);
	s = "toasting";
	insert(s);
	s = "slow";
	insert(s);
	s = "slowly";
	/*insert(s);
	s = "arun";
	insert(s);
	s = "abhishek";
	insert(s);*/	
	

	if(search("slow"))
		printf("found slow\n");
	if(search("s"))
		printf("s\n");
	if(search("test"))
		printf("found test\n");
	else
		printf("not found test\n");
	
	printf("no of words with prefix to are %d\n",words_with_prefix("to"));
	printf("no of words with prefix toasting are %d\n",words_with_prefix("toasting"));
	printf("no of words with prefix k are %d\n ",words_with_prefix("k"));
	
	

	return 0;
}