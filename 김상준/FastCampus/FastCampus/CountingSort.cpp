//
//  CountingSort.cpp
//  FirstXCode
//
//  Created by Sangjun Kim on 2020/11/28.
//  Copyright © 2020 SJKim. All rights reserved.
//

#include <iostream>
#define MAX_VALUE 10001

int n, m;
int a[MAX_VALUE];

int main()
{
    // 크기를 기준으로 데이터의 개수를 세는 정렬 알고리즘, 시간복잡도 O(N)
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> m;
        a[m]++;
    }
    for (int i = 0; i < MAX_VALUE; i++)
    {
        while (a[i] != 0)
        {
            std::cout << i << " ";
            a[i]--;
        }
    }
    
    return 0;
}
