//
//  Sum.cpp
//  3-array
//
//  Created by FlyElephant on 2019/1/8.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>

class Sum {
public:
    
    int maxSubsequenceSum(int arr[],int n) {
        if (n <= 0) {
            return -1;
        }
        int sum = arr[0];
        int max = sum;
        for (int i = 1; i < n; i++) {
            if (sum <= 0) { // 如果之前的和是负数,重新开始计算
                sum = arr[i];
            } else {
                sum += arr[i];
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
    
    void test() {
        int arr[] = {1,-2,3,10,-4,7,2,-5};
        int max = maxSubsequenceSum(arr, 8);
        printf("最大连续子序列的和:%d\n",max);
    }
};
