//Author: Marcel Skuza
//Last modified: 03/01/2019
//This program is an C++ implementation of Binary Search Tree data structure


#include "BinarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

// **Constructors **

//Empty tree constructor
BinarySearchTree::BinarySearchTree()
{
	root = new Node;
}

//Single word tree constructor
BinarySearchTree::BinarySearchTree(string word)
{
	root = new Node;
	root->word = word;
}

//Copy tree constructor

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{
	root = new Node;
	root = treeCloner(rhs.root);
}


//Vector constructor
BinarySearchTree::BinarySearchTree(const vector<string> &words)
{
	for(int loop = 0; loop<words.size(); loop++){
		insert(words[loop]);
	}
}

// **Constructor helpers**

//Tree constructor helper
Node* BinarySearchTree::treeCloner(Node* toClone)
{	
	Node* clonedNode = nullptr;
	if(toClone != nullptr){
		clonedNode = new Node;
		clonedNode->word = toClone->word;
		clonedNode->count = toClone->count;
		clonedNode->left = treeCloner(toClone->left);
		clonedNode->right = treeCloner(toClone->right);
	}
	return clonedNode;
}

// **Destructors**
BinarySearchTree::~BinarySearchTree()
{
	destructorHelper(root);
}

// **Destructor helpers**
void BinarySearchTree::destructorHelper(Node *rem)
{
	if(rem->left != nullptr){
		destructorHelper(rem->left);
	}
	if(rem->right != nullptr){
		destructorHelper(rem->right);
	}
	delete rem;
}

// **Methods**

//Creates new node
Node* BinarySearchTree::createNode(string word)
{
	Node *node = new Node;
	node->word = word;
	
	return node;
}

//Inserts new word to tree
void BinarySearchTree::insert(string word)
{
	insertHelper(word, root);
}

//Insert helper function
void BinarySearchTree::insertHelper(string word, Node *node)
{
	if(root == nullptr || root->word == ""){
		root = createNode(word);
	}else if(word < node->word){
		if(node->left != nullptr){
			insertHelper(word, node->left);
		}else{
			node->left = createNode(word);
		}
	}else if(word > node->word){
		if(node->right != nullptr){
			insertHelper(word, node->right);
		}else{
			node->right = createNode(word);
		}
	}else{
		node->count++; //Equal, increment count for this word
	}
}

//Returns true if word exists in the tree
bool BinarySearchTree::exists(string word) 
{
	bool exist = existsHelper(word, root);
	return exist;
}

//Exists helper function
bool BinarySearchTree::existsHelper(string word, Node *node)
{
	if(node == nullptr){
		return false;
	}
	if(word != node->word){
		if(word < node->word){
			return existsHelper(word, node->left);
		}else{
			return existsHelper(word, node->right);
		}
	}else{
		return true;
	}
}

// *Printing functions*

//Prints words inorder + prints number of times word occurs
string BinarySearchTree::inorderCount() 
{
	string words = inorderCountHelper(root);
	return words;
}

//inorderCount helper function
string BinarySearchTree::inorderCountHelper(Node *root)
{
	if (root == nullptr)
	{
		return "";
	}
	else
	{
		return inorderCountHelper(root->left) + root->word + ": " + to_string(root->count) + "\n" + inorderCountHelper(root->right);
	}
}


//Prints words inorder
string BinarySearchTree::inorder()
{
	string words = inorderHelper(root);
	if(words.length() >= 1)
	{
		words.pop_back(); // Remove final space.
	}
	return words; 
}

//Inorder helper function
string BinarySearchTree::inorderHelper(Node *root)
{
	if(root == nullptr)
	{
		return "";
	}
	else
	{
		return inorderHelper(root->left) + root->word + " " + inorderHelper(root->right);	
	}
}

//Prints words preorder
string BinarySearchTree::preorder()
{
	string words = preorderHelper(root);
	if(words.length() >= 1)
	{
		words.pop_back(); // Remove final space.
	}
	return words; 
}

//Preorder helper function
string BinarySearchTree::preorderHelper(Node *root){
	
	if(root == nullptr)
	{
		return "";
	}
	else
	{
		return root->word + " " + preorderHelper(root->left) + preorderHelper(root->right);	
	}
	
}

//Prints words postorder
string BinarySearchTree::postorder()
{
	string words = postorderHelper(root);
	if(words.length() >= 1)
	{
		words.pop_back(); // Remove final space.
	}
	return words; 
}

//Postorder helper function
string BinarySearchTree::postorderHelper(Node *root){
	
	if(root == nullptr)
	{
		return "";
	}
	else
	{
		return postorderHelper(root->left) + postorderHelper(root->right) + root->word + " ";
	}
	
}

void BinarySearchTree::deleteExceptRoot(Node* rem)
{
	if (rem->left != nullptr) {
		deleteExceptRoot(rem->left);
	}
	if (rem->right != nullptr) {
		deleteExceptRoot(rem->right);
	}
	if (rem->word != root->word) {
		delete rem;
	}
}
    
// **Operator overloads**

BinarySearchTree& BinarySearchTree::operator+(string word)
{
	insert(word);
	return *this; // returns a reference to the modified tree
}


BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	if (this != &rhs) {
		destructorHelper(root);
		root = new Node;
		root = treeCloner(rhs.root);
	}

	return *this; // returns a reference to the modified tree	
}




