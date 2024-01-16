#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10

#define EXPECTED_OUT_AFTER_ADD " 5 10 12 21 22 30 50 55 60 100"
#define EXPECTED_OUT_AFTER_DEL_50 " 5 10 12 21 22 30 55 60 100"
#define EXPECTED_OUT_AFTER_DEL_5 " 10 12 21 22 30 55 60 100"
#define EXPECTED_OUT_AFTER_DEL_100 " 10 12 21 22 30 55 60"


void test(string out, string outAfterDel50, string outAfterDel5, string outAfterDel100) {
    cout << ((out == EXPECTED_OUT_AFTER_ADD) ? "Pass\n" : "Fail\n");
    cout << ((outAfterDel50 == EXPECTED_OUT_AFTER_DEL_50) ? "Pass\n" : "Fail\n");
    cout << ((outAfterDel100 == EXPECTED_OUT_AFTER_DEL_100) ? "Pass\n" : "Fail\n");
    cout << ((outAfterDel5 == EXPECTED_OUT_AFTER_DEL_5) ? "Pass\n" : "Fail\n");
}


int main()
{
    int arr[]= {50,12,21,10,60,30,5,100,22,55};
    int len = 10;
    

    BST tree;
    for(int i=0;i<len;i++)
    {
        tree.addNode(arr[i]);
    }
    cout<< "inorder traversal before deleting anything:"<<endl;
    string out = tree.printTree();
    cout << out << "\n";

    tree.deleteNode(50);
    string outAfterDel50 = tree.printTree();


    tree.deleteNode(5);
    string outAfterDel5 = tree.printTree();


    tree.deleteNode(100);
    string outAfterDel100 = tree.printTree();

    test(out, outAfterDel50, outAfterDel5, outAfterDel100);
    
  return 0;
}
