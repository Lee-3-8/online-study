//
//  BinarySearchTree.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/12/26.
//  Copyright © 2020 SJKim. All rights reserved.
//

#include <iostream>

struct Node
{
    int data;
    Node* leftChild;
    Node* rightChild;
    
    Node(int data, Node* leftChild, Node* rightChild)
    : data(data), leftChild(leftChild), rightChild(rightChild) {}
};

Node* InsertNode(Node* root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data, nullptr, nullptr);
        return root;
    }
    else
    {
        if (root->data > data)
        {
            root->leftChild = InsertNode(root->leftChild, data);
        }
        else
        {
            root->rightChild = InsertNode(root->rightChild, data);
        }
    }
    return root;
}

Node* SearchNode(Node* root, int data)
{
    if (root == nullptr) return nullptr;
    if (root->data == data) return root;
    else if (root->data > data) return SearchNode(root->leftChild, data);
    else return SearchNode(root->rightChild, data);
}

void InorderTraverse(Node* root)
{
    if (root == nullptr) return;
    InorderTraverse(root->leftChild);
    std::cout << root->data << " ";
    InorderTraverse(root->rightChild);
}

Node* FindMinNode(Node* root)
{
    Node* node = root;
    while (node->leftChild != nullptr)
    {
        node = node->leftChild;
    }
    return node;
}

Node* DeleteNode(Node* root, int data)
{
    Node* node = nullptr;
    if (root == nullptr) return nullptr;
    if (root->data > data) root->leftChild = DeleteNode(root->leftChild, data);
    else if (root->data < data) root->rightChild = DeleteNode(root->rightChild, data);
    else
    {
        if (root->leftChild != nullptr && root->rightChild != nullptr)
        {
            node = FindMinNode(root->rightChild);
            root->data = node->data;
            root->rightChild = DeleteNode(root->rightChild, node->data);
        }
        else
        {
            node = (root->leftChild != nullptr) ? root->leftChild : root->rightChild;
            delete root;
            return node;
        }
    }
    return root;
}

int main()
{
    // 이진 탐색 트리
    // 이진 탐색(Binary Search)이 항상 동작하도록 구현하여 탐색 속도를 높인 자료구조
    // 부모 노드가 왼쪽 자식보다는 크고, 오른쪽 자식보다는 작다.
    // 완전 이진 트리의 경우 O(logN)의 시간복잡도를 가짐
    Node* root = nullptr;
    root = InsertNode(root, 30);
    root = InsertNode(root, 17);
    root = InsertNode(root, 48);
    root = InsertNode(root, 5);
    root = InsertNode(root, 23);
    root = InsertNode(root, 37);
    root = InsertNode(root, 50);
    root = DeleteNode(root, 50);
    InorderTraverse(root);
    
    return 0;
}
