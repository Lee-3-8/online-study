//
//  RadixSort.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/11/28.
//  Copyright © 2020 SJKim. All rights reserved.
//

#include <iostream>
#define MAX 10000

void RadixSort(int* a, int n)
{
    int res[MAX], maxValue = 0;
    int exp = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > maxValue) maxValue = a[i];
    }
    while (maxValue / exp > 0)
    {
        int bucket[10] = {0,};
        for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++; // 자릿수 배열
        for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1]; // 누적 배열
        for (int i = 0; i < n; i++) // 같은 자릿수끼리 정렬
        {
            res[--bucket[a[i] / exp % 10]] = a[i];
        }
        for (int i = 0; i < n; i++) a[i] = res[i]; // 기존 배열 갱신
        exp *= 10;
    }
}

int main()
{
    // 자릿수를 기준으로 차례대로 데이터를 정렬하는 알고리즘, 시간복잡도 O(DN) 여기서 D는 가장 큰 자릿수
    int a[MAX];
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    RadixSort(a, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    
    return 0;
}
