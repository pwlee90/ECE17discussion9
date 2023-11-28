//
// Created by 李芃瑋 on 11/27/23.
//

#ifndef DOWNLOADS_BINARYTREE_H
#define DOWNLOADS_BINARYTREE_H
class BinaryTree{
private:
    struct Node{
        int val;
        Node* left;
        Node* right;

        Node(int aVal, Node* left = nullptr,Node* right = nullptr);
    };
    Node* root;
};
#endif //DOWNLOADS_BINARYTREE_H
