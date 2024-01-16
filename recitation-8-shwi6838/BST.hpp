#ifndef BST_HPP
#define BST_HPP

using namespace std;

struct Node{
    int key;
    Node* left ;
    Node* right;
};

class BST{
    private:
        Node* root;
        Node* createNode(int data);
        /** since root is a private member we need helper functions
         to access root for insertion, searching and printing.
         These helper functions is used for performing recursion **/

        Node* addNodeHelper(Node*, int);
        Node* minValueNode(Node* node);
        Node* deleteNodeHelper(Node*, int);
        void printTreeHelper(Node*, string*);
        void print2DUtilHelper(Node *, int);

        Node* searchKeyHelper(Node*, int);

        Node* kthSmallestHelper(Node* currNode, int* counter, int k);
        void destroyNode(Node *root);

       


    public:
        Node* getRoot();                // Returns the root of the tree;
        void addNode(int);              // function to insert a node in the tree.
        void deleteNode(int);           // function to delete a node from the tree.
        bool searchKey(int);            // function to search a data in the tree
        string printTree();               //function to print the tree
        BST();                          // default constructor
        BST(int data);                  // parameterized constructor
        ~BST();                         // destructor
        
        void print2DUtil(int);
        
        Node* findKthSmallest(int k);
        void rangePrint(int k1,int k2);

};
#endif
