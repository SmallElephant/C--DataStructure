//
//  Reverse.cpp
//  3-array
//
//  Created by FlyElephant on 2019/1/12.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>

class Reverse {
public:
    
    int reversePairs(int arr[],int n) {
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    res++;
                }
            }
        }
        return res;
    }
    
    // 数组中的逆序对
    void test() {
        int arr[] = {7,5,6,4};
        int count = reversePairs(arr, 4);
        printf("数组中逆序对出现的次数:%d\n",count);
    }
};
