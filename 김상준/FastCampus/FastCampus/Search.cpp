//
//  Search.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/11/29.
//  Copyright © 2020 SJKim. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100
#define MAX_SIZE 100000

char** array;
bool founded = false;

int a[MAX_SIZE];

int search(int start, int end, int target)
{
    if (start > end) return -9999;
    int mid = (start + end) / 2;
    if (a[mid] == target) return mid;
    else if (a[mid] > target) return search(start, mid - 1, target);
    else return search(mid + 1, end, target);
}

int main()
{
    // 순차 탐색 (Sequential Search) - 특정한 원소를 찾기 위해 원소를 순차적으로 하나씩 탐색하는 방법, 시간복잡도 O(N)
    int n;
    char word[LENGTH];
    std::cin >> n >> word;
    array = new char*[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new char[LENGTH];
        std::cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (!strcmp(array[i], word))
        {
            std::cout << i + 1 << "번째 원소입니다." << std::endl;
            founded = true;
        }
    }
    if (!founded)
    {
        std::cout << "원소를 찾을 수 없습니다." << std::endl;
    }
    
    // 이진 탐색 (Binary Search) - 배열 내부가 이미 정렬 되어 있는 상황에서 사용 가능한 알고리즘, 탐색 범위를 절반 씩 좁혀가며 데이터를 탑색, 시간복잡도 O(logN)
    founded = false;
    int target;
    std::cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int result = search(0, n - 1, target);
    if (result != -9999)
    {
        std::cout << result + 1 << "번째 원소입니다." << std::endl;
    }
    else
    {
        std::cout << "원소를 찾을 수 없습니다." << std::endl;
    }
    
    return 0;
}
