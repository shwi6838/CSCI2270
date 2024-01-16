#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10



int main()
{
    int arr[]= {50,12,21,10,60,30,5,100,22,55};
    int len = 10;
    

    BST tree;
    for(int i=0;i<len;i++)
    {
        tree.addNode(arr[i]);
    }
    cout<< "inorder traversal:"<<endl;
    tree.printTree();
    Node* kth = tree.findKthSmallest(5);
    if(kth && kth->key == 22)
    {
        cout<< "Pass:"<<kth->key<<endl;
        //cout<< "Pass"<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }
    
    
    kth = tree.findKthSmallest(10);
    //cout<< kth->key<<endl;
    if(kth && kth->key == 100)
    {
        cout<< "Pass:"<< kth->key<<endl;
        //cout<< "Pass"<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }
    
    
    kth = tree.findKthSmallest(12);
    //cout<< kth->key<<endl;
    if(kth==NULL)
    {
        cout<< "Pass: Tree does not have 12 elements"<<endl;
        //cout<< "Pass"<<endl;
    }
    else{
        cout<<"Fail"<<endl;
    }

    
    cout<<"printing within range 5 and 20"<<endl;
    tree.rangePrint(5,20);
    cout<<endl;
  return 0;
}
