//
//  BinaryTree.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/11/28.
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

Node* InitNode(int data, Node* leftChild, Node* rightChild)
{
    Node* node = new Node(data, leftChild, rightChild);
    return node;
}

void PreorderTraverse(Node* root)
{
    if (root)
    {
        std::cout << root->data << " ";
        PreorderTraverse(root->leftChild);
        PreorderTraverse(root->rightChild);
    }
}

void InorderTraverse(Node* root)
{
    if (root)
    {
        InorderTraverse(root->leftChild);
        std::cout << root->data << " ";
        InorderTraverse(root->rightChild);
    }
}

void PostorderTraverse(Node* root)
{
    if (root)
    {
        PostorderTraverse(root->leftChild);
        PostorderTraverse(root->rightChild);
        std::cout << root->data << " ";
    }
}

int main()
{
    // 이진 트리
    // 포화 이진 트리 (Full Binary Tree) - 리프 노드를 제외한 모든 노드가 두개의 자식을 가진 트리
    // 완전 이진 트리 (Complete Binary Tree) - 모든 노드들이 왼쪽 자식부터 채원진 트리
    // 높이 균형 트리 (Height Balanced Tree) - 왼쪽 자식 트리와 오른쪽 자식 트리의 높이가 1 이상 차이나지 않는 트리
    Node* n7 = InitNode(50, nullptr, nullptr);
    Node* n6 = InitNode(37, nullptr, nullptr);
    Node* n5 = InitNode(23, nullptr, nullptr);
    Node* n4 = InitNode( 5, nullptr, nullptr);
    Node* n3 = InitNode(48, n6, n7);
    Node* n2 = InitNode(17, n4, n5);
    Node* n1 = InitNode(30, n2, n3);
    
    // 이진 트리 순회
    // 전위 순회 - 자기 자신 출력 -> 왼쪽 자식 방문 -> 오른쪽 자식 방문
    // 중위 순회 - 왼쪽 자식 방문 -> 자기 자신 출력 -> 오른쪽 자식 방문
    // 후위 순회 - 왼쪽 자식 방문 -> 오른쪽 자식 방문 -> 자기 자신 출력
    PreorderTraverse(n1);
    std::cout << std::endl;
    InorderTraverse(n1);
    std::cout << std::endl;
    PostorderTraverse(n1);
    std::cout << std::endl;
    
    return 0;
}
