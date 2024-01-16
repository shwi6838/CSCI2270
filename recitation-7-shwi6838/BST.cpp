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

BST::~BST()
{
     destroyNode(root);
}


Node* BST::getRoot(){
    return root;
}

 /**
 This function will destroy the subtree rooted at currNode.
 Think about in what order should you destroy?
 **/
//TODO:1
void BST:: destroyNode(Node *currNode)
{
 // check for empty tree
    //else traverse and delete
    if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
     return currNode;
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

void BST::print2DUtil(int space)
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

//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void BST:: printTreeHelper(Node* currNode){
     if(currNode)
     {
        printTreeHelper( currNode->left);
        cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }

void BST:: printTree(){
     printTreeHelper(root);
     cout<<endl;
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

//----------------Silver Problem ---------------------------

Node*  BST::kthSmallestHelper(Node* currNode, int* counter, int k)
{
    // base case
    if (currNode == NULL) 
    {
        return NULL;
    }
 
    // recur for the left subtree
    Node* Smallest;
    Smallest = kthSmallestHelper(currNode->left, counter, k);

    // if k'th smallest node is found in left return
    ++(*counter);
    if(*counter == k)
    {
        return currNode;
    }

    //for current node increment counter
    // if the root is k'th smallest node

   // kthSmallestHelper(currNode, counter, k);
 
    // recur for the right subtree only if k'th smallest node is not found
    // in the left subtree
    //++(*counter);

    Smallest = kthSmallestHelper(currNode->right, counter, k);
     
     return Smallest;
}
// Function to find the k'th smallest node in a BST

Node*  BST::findKthSmallest(int k)
{
    // counter to keep track of the total number of the visited nodes
    int counter = 0;
 
    // recursively find the k'th smallest node
    return kthSmallestHelper(root, &counter, k);
}

//----------------Gold Problem Optional ---------------------------


void rangePrintH(Node *currNode, int k1, int k2)
{
    /* base case */
    if ( NULL == currNode)
        return;
     
    
   
}

void BST::rangePrint(int k1,int k2)
{
    rangePrintH(root, k1,k2);
}