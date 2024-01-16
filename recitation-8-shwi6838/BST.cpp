#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10
/**
Create a node with key as data
**/

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{
    root= NULL;
}

/**
parameterized constructor. It will create the root and put the data in the root.
**/

BST::BST(int data)
{
    root = createNode(data);
    cout<< "New tree created with "<<data<<endl;
}

/**
Destructor
**/

BST::~BST(){
     destroyNode(root);
}


Node* BST::getRoot(){
    return root;
}

 /**
 This function will destroy the subtree rooted at currNode.
 
 Correct Code for the destroyNode function is the following:
 **/
void BST:: destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}



//---------------------------- INSERT NODE IN THE TREE --------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
**/

Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}


void BST:: addNode(int data)
{
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

//---------------------------- TODO: DELETE NODE FROM THE TREE --------------------------------------

/**
This function will delete the data from the tree rooted at currNode.
We will call this function from deleteNode.
**/

Node* BST::minValueNode(Node* node)
{
    Node* current = node;
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}

Node* BST::deleteNodeHelper(Node* currNode, int data)
{
    // TODO: Recitation 8 
    // HINT: You might have to use the minValueNode function for one of the cases.
    if(currNode == NULL)
    {
        return currNode;
    }

    if(data < currNode->key)
    {
        currNode->left = deleteNodeHelper(currNode->left, data);
    }
    else if(currNode->key < data)
    {
        currNode->right = deleteNodeHelper(currNode->right, data);
    }
    else if(currNode->key == data) //found node
    {
        //Case 1: Leaf node - delete
        if(currNode->left == NULL && currNode->right == NULL) //isLeaf()
        {
            delete currNode;
            currNode = nullptr;
            //**
            //return currNode;
        }
        //Case 2: One child - meet grandparent
        else if(currNode->left == NULL && currNode->right != NULL) //Right Child
        {
            Node* temp = currNode->right;
            delete currNode;
            currNode = temp;
            //**
            //return temp;
        }
        else if (currNode->right == NULL && currNode->left != NULL) //Left Child
        {
            Node* temp = currNode->left;
            delete currNode;
            currNode = temp;
            //return temp;
        }
        //Case 3: Two children - replace with lowest value in right child subtree (Next greater element)
        else
        {
            Node* next = minValueNode(currNode->right);
            currNode->key = next->key;                                 //replace curr with next node
            currNode->right = deleteNodeHelper(currNode->right, currNode->key);   //delete the next node from bottom
            //return currNode;
        }
        //return currNode;
    }
    return currNode;
}


void BST:: deleteNode(int data)
{
    root = deleteNodeHelper(root, data);
}





//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void BST:: printTreeHelper(Node* currNode, string *inorder){
     if(currNode)
     {
        printTreeHelper( currNode->left, inorder);
        (*inorder) += " " + to_string(currNode->key);
        printTreeHelper( currNode->right, inorder);
     }
 }

string BST:: printTree(){
    string inorder = "";
    printTreeHelper(root, &inorder);
    return inorder;
}

 //------------------------------------------------SEARCH A KEY------------------------------------------
 /** This function will search the data in a tree
     We will call this function from searchKey.
 **/

Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}

// This function will return whether a key is in the tree
bool BST::searchKey(int key){
    Node* tree = searchKeyHelper(root, key);
    if(tree != NULL) {
        return true;
    }
    cout<<"Key not present in the tree"<<endl;
    return false;
}

