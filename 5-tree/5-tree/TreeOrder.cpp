//
//  TreeOrder.cpp
//  5-tree
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include "Common.hpp"

class TreeOrder {
public:
    
    bool isPostOrder(int *arr, int n) {
        return isBinarySearchOrder(arr, 0, n-1);
    }
    
    bool isBinarySearchOrder(int arr[], int start, int end) {
        if (start >= end) {
            return true;
        }
        int i = start;
        for (; i < end; i++) { // 左子树的结点
            if (arr[i] > arr[end]) {
                break;
            }
        }
        for (int j = i; j < end; j++) {
            if (arr[j] < arr[end]) { // 确保右子树的结点全部大于末尾结点
                return false;
            }
        }
        bool isLeft = isBinarySearchOrder(arr, start, i - 1);
        bool isRight = isBinarySearchOrder(arr, i, end-1);
        return isLeft && isRight;
    }
    
    void test() {
        int arr[7] = {5,7,6,9,11,10,8};
        int n = (int)(sizeof(arr) / sizeof(arr[0]));
        bool res = isPostOrder(arr,n);
        if (res) {
            printf("is post order\n");
        } else {
            printf("is not post order\n");
        }
    }
};
