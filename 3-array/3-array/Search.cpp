//
//  Search.cpp
//  3-array
//
//  Created by FlyElephant on 2019/1/7.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
using namespace std;

class Search {
public:
    
    // 数组中出现超过一半的数字
    int findMoreHalfNumber(int arr[],int n) {
        if (n <= 0) {
            return -1;
        }
        int num = arr[0];
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (count > 0) {
                if (arr[i] == num) {
                    count++;
                } else {
                    count--;
                }
            } else {
                num = arr[i];
                count = 1;
            }
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == num) {
                c++;
            }
        }
        return c > n / 2 ? num : -1;
    }
    
    void test() {
        int arr[] = {1,2,3,4,5,6,1,1,1};
        int val = findMoreHalfNumber(arr, 9);
        if (val > 0) {
            printf("超过一半的数字:%d\n",val);
        } else {
            printf("没有超过一半的数字\n");
        }
    }
};

