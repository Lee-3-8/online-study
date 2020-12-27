//
//  PriorityQueue.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/11/29.
//  Copyright © 2020 SJKim. All rights reserved.
//

#include <iostream>
#define MAX_SIZE 10000

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct priorityQueue
{
    int heap[MAX_SIZE];
    int count;
};

void push(priorityQueue* pq, int data)
{
    if (pq->count >= MAX_SIZE) return;
    pq->heap[pq->count] = data;
    int now = pq->count;
    int parent = (pq->count - 1) / 2;
    while (now > 0 && pq->heap[now] > pq->heap[parent])
    {
        swap(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

int pop(priorityQueue* pq)
{
    if (pq->count <= 0) return -9999;
    int res = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftChild = 1, rightChild = 2;
    int target = now;
    while (leftChild < pq->count)
    {
        if (pq->heap[target] < pq->heap[leftChild])  target = leftChild;
        if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
        if (target == now) break;
        else
        {
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftChild = now * 2 + 1;
            rightChild = now * 2 + 2;
        }
    }
    return res;
}

int main()
{
    // 우선순위 큐
    // 우선순위를 가진 데이터를 저장하는 큐 - 데이터를 꺼낼 때 우선순위가 높은 데이터가 가장 먼저 나옴
    // 운영체제의 작업 스케줄링, 정렬, 네트워크 관리 등 여러 기술에 적용
    
    // 트리구조로 보는 것이 합리적 -> 최대 힙을 이용해 구현 (완전 이진 트리를 이용해 구현)
    // 최대 힙 (Max Heap) - 부모 노드가 자식 노드보다 값이 큰 완전 이진 트리
    
    // 우선순위 큐 삽입 - 완전 이진 트리를 유지하는 형태로 순차적으로 삽입 후 상향식 힙 구성, 시간복잡도 O(logN)
    // 우선순위 큐 삭제 - 루트 노드 삭제 후, 마지막 원소를 루트 노드의 위치로, 이후 하향식 힙 구성, 시간복잡도 O(logN)
    
    // 우선순위 큐를 이용한 정렬 (힙 정렬) - 시간복잡도 O(NlogN)
    int n, data;
    std::cin >> n;
    priorityQueue pq;
    pq.count = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> data;
        push(&pq, data);
    }
    for (int i = 0; i < n; i++)
    {
        data = pop(&pq);
        std::cout << data << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
