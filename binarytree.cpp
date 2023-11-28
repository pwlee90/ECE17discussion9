//
// Created by 李芃瑋 on 11/27/23.
//
#include "binarytree.h"
#include <iostream>
BinaryTree::Node::Node(int aVal, BinaryTree::Node* left = *aLeft ,BinaryTree::Node* right = *aRight){
    val = aVal;
    left = aLeft;
    right = aRight;
}
BinaryTree::BinaryTree(){
    root = nullptr;
}
void BinaryTree::insertNode(int aVal){
    Node* ewNode = new Node(aVal);
    insert(root,newNode);
}
void BinaryTree::insert(BinaryTree::Node *&aNodePtr,BinaryTree::Node *&aNewNodePtr){
    if(aNodePtr==nullptr){
        aNodePtr = aNewNodePtr;
    }
    else if(aNewNodePtr->bal<aNodePtr->val){
            insert(aNodePtr->left,aNewNodePtr);
    }
    else{
        insert(aNodePtr->right,aNewNodePtr)
    }
}
void BinaryTree::deleteNode(int aVal,BinaryTree::Node *&aNodePtr){
    if(aVal<aNodePtr->val){
        deleteNode(aVal,aNOdePtr->left);
    }
    else if(aVal>aNodePtr->val){
        deleteNode(aVal,aNodePtr->right);
    }
    else{
        //value is found
        makeDeletion(aNodePtr);
    }
}
void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr){
    Node* tempNodePtr = nullptr;
    if(aNodePtr == nullptr){
        std::cout<<"Cannot remove emptyNode"<<std::endl;
    }
    else if(aNodePtr->right ==nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else if(aNodePtr->left==nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    }
    else{
        tempNodePtr = aNodePtr->right;
        while(tempNodePtr->left){
            tempNodePtr = tempNodePtr->left;
        }
        tempNodePtr->left = aNodePtr->left;
        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;
        delete tempNodePtr;
    }

}
bool BinaryTree::searchNode(int aVal){
    Node* currentNode = root;
    while(currentNode){
        if(currentNode->val == aVal){
            return true;
        }
        else if(aVal<currentNode->val){
            currentNode = currentNode->left;
        }
        else{
            currentNode=currentNode->right;
        }
    }
    return false;
}
void BinaryTree::remove(int aVal){
    deleteNode(aVal,root);
}