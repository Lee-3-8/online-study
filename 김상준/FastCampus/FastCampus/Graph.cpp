//
//  Graph.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/11/29.
//  Copyright © 2020 SJKim. All rights reserved.
//

#include <iostream>

int a[1001][1001];
int n, m;

struct Node
{
    int index;
    int distance;
    Node* next;
    
    Node(Node* next, int index, int distance)
    :next(next), index(index), distance(distance) {}
};

void AddFront(Node* root, int index, int distance)
{
    Node* node = new Node(root->next, index, distance);
    root->next = node;
}

void ShowAll(Node* root)
{
    Node* cur = root->next;
    while (cur)
    {
        std::cout << cur->index << "(거리: " << cur->distance << ") ";
        cur = cur->next;
    }
}

int main()
{
    // 그래프 - 사물을 정점(Vertex)과 간선(Edge)으로 나타내기 위한 도구
    // 두가지 방식으로 구현 가능
    // 1. 인접 행렬 (Adjcency Matrix) - 2차원 배열을 이용, 모든 정점들의 연결 여부를 저장 -> 공간 복잡도 O(V^2), 연결성 확인에는 O(1)
    // 2. 인접 리스트 (Adjacency List) - 리스트를 사용, 연결된 간선의 정보만을 저장 -> 공간 복잡도 O(E), 연결성 확인에는 O(V)
    
    // 무방향 비가중치 그래프 & 인접 행렬
    std::cin >> n >> m; // 정점 n개, 간선 m개
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    // 방향 가중치 그래프 & 인접 리스트
    std::cin >> n >> m;
    Node **a = new Node*[n + 1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = new Node(nullptr, 0, 0);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, distance;
        std::cin >> x >> y >> distance;
        AddFront(a[x], y, distance);
    }
    for (int i = 1; i <= n; i++)
    {
        std::cout << "원소 [" << i <<"]: ";
        ShowAll(a[i]);
        std::cout << "\n";
    }
    
    return 0;
}
