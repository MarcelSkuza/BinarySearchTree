#pragma once

#include <string>
#include <vector>
#include "Node.h"
class BinarySearchTree
{
public:
	// **Constructors and destructors**
	
	// Creates an empty binary tree
    BinarySearchTree();
    // Creates a binary search tree with an initial word to store
    BinarySearchTree(std::string word);
    // Creates a binary search tree by copying an existing tree
    BinarySearchTree(const BinarySearchTree &rhs);
    // Creates a binary search tree from a collection of existing words
	BinarySearchTree(const std::vector<std::string> &words);
    // Destroys (cleans up) the tree
    ~BinarySearchTree();
    

	// **Methods that can be called on a BinarySearchTree object**
    
	// Adds a word to the tree
    void insert(std::string word);
	// Checks if a word is in the tree
    bool exists(std::string word);
    // Creates a string representing the tree in alphabetical order
    std::string inorder();
    // Creates a string representing the tree in pre-order
    std::string preorder();
    // Creates a string representing the tree in post-order
    std::string postorder();
	//Returns words inorder + word occurrence	
	std::string inorderCount();
	
    // **Operator overloads**
    
    // Inserts a new word into the binary tree
    BinarySearchTree& operator+(std::string word);

    
    // Copy assignment operator
    BinarySearchTree& operator=(const BinarySearchTree &rhs);
	
private:
   
    // **Methods that can be called on a BinarySearchTree object**
   
	//Creates deep copy of a tree
	Node* treeCloner(Node* toClone);
	//Creates new node
	Node* createNode(std::string word);
	//Deletes all nodes except of root
	void BinarySearchTree::deleteExceptRoot(Node *rem);
	
	//Helper functions
	void destructorHelper(Node *rem);
	void insertHelper(std::string word, Node *node);
	bool existsHelper(std::string word, Node *node);
	std::string inorderHelper(Node *root);
	std::string preorderHelper(Node *root);
	std::string postorderHelper(Node *root);
	std::string inorderCountHelper(Node *root);

	
	Node* root = nullptr; // Pointer to the root Node of the tree
	
};

