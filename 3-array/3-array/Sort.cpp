//
//  Sort.cpp
//  3-array
//
//  Created by FlyElephant on 2019/1/7.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>

class Sort {
public:
    
    void swap(int *a,int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    
    void printArr(int arr[],int n) {
        for (int i = 0; i < n; i++) {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    
    // 冒泡排序 稳定 时间复杂度O(n²)
    void bubbleSort(int arr[],int n) {
        for (int i = 0;  i < n - 1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(&arr[j], &arr[j+1]);
                }
            }
        }
    }
    
    void test() {
        int arr[] = {3,4,1,2,8,10,5,6,7,9};
        bubbleSort(arr, 10);
        printArr(arr, 10);
    }
    
};
