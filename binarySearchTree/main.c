#include "binarySearchTree.h"



int main()
{
    BinarySearchTree BST;
    binarySearchTreeInit(&BST);

    binarySearchTreeInsert(&BST, 5);
    binarySearchTreeInsert(&BST, 1);
    binarySearchTreeInsert(&BST, 7);
    binarySearchTreeInsert(&BST, 4);
    binarySearchTreeInsert(&BST, 8);
    

    binarySearchTreeRemove(&BST, 7);

    binarySearchTreePreOrderTravel(&BST);

    return 0;
    
}