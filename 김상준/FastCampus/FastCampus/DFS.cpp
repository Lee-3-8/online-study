//
//  DFS.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/11/29.
//  Copyright © 2020 SJKim. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#define MAX_SIZE 1001

struct Node
{
    int index;
    Node* next;
    
    Node(int index, Node* next)
    :index(index), next(next) {}
};

Node** a;
int n, m, c[MAX_SIZE]; // c는 방문 체크

void AddFront(Node* root, int index)
{
    Node* node = new Node(index, root->next);
    root->next = node;
}

// 탐색 알고리즘
// 1. 탐색 시작 노드를 스택에 삽입하고 방문 처리
// 2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 하나라도 있으면, 그 노드를 스택에 넣고 방문 처리. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼냄
// 3. 2번을 더 수행 할 수 없을 때 까지 반복
void DepthFirstSearch(int x)
{
    if (c[x]) return;
    c[x] = 1;
    std::cout << x << " ";
    Node* cur = a[x]->next;
    while (cur)	
    {
        int next = cur->index;
        DepthFirstSearch(next);
        cur = cur->next;
    }
}

int main()
{
    // 깊이 우선 탐색 (Depth First Search)
    // 보다 깊은 것을 우선적으로 탐색하는 알고리즘
    // 전체 노드를 맹목적으로 탐색하고자 할 때 사용, 스택 자료 구조에 기초
    // O(N)의 시간이 소요되는 알고리즘
    std::cin >> n >> m;
    a = new Node*[MAX_SIZE];
    for (int i = 1; i <= n; i++)
    {
        a[i] = new Node(0, nullptr);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        AddFront(a[x], y);
        AddFront(a[y], x);
    }
    DepthFirstSearch(1);
    
    return 0;
}
