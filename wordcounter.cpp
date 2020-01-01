//Author: Marcel Skuza
//Last modified: 06/04/2019
//This program counts words in the input file (case sensitive) and outputs the results to console

#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	BinarySearchTree* tree = new BinarySearchTree();
	
	ifstream file;
	file.open(argv[1]);
	stringstream buffer;
	buffer << file.rdbuf();
	string file_buffer = buffer.str();
	
	//Remove punctuation from the text
	for (int i = 0, len = file_buffer.size(); i < len; i++) 
    { 
        if (ispunct(file_buffer[i])) 
        { 
            file_buffer.erase(i--, 1); 
            len = file_buffer.size(); 
        } 
    } 
	
	//	!C code!
	
	//Tokenise the text by spaces and newline characters
	char* file_buffer_c = new char [file_buffer.size() + 1];
	strcpy(file_buffer_c, file_buffer.c_str());
	
	char *token = strtok(file_buffer_c, "\n ");
	
	//Insert tokens (words) into the tree
	do{
		//string s(token);
		tree->insert(token);
		token = strtok(NULL, "\n ");
	}while (token != NULL);
	
	//Print words + count to command line
	cout << tree->inorderCount() << endl;
	
	delete file_buffer_c;
	delete tree;
	
	return 0;
}
