//
//  Permuate.cpp
//  3-array
//
//  Created by FlyElephant on 2019/1/11.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>

class Permuate {
    
public:
    
    void swap(int *a,int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    
    void printArr(int arr[],int n) {
        if (arr == NULL) {
            return;
        }
        for (int i = 0; i < n; i++) {
            printf("%d",arr[i]);
        }
        printf("\n");
    }
    
    void permuate(int arr[],int start,int len) {
        if (start == len-1) {
            int *data = (int *)malloc(sizeof(int) * len);
            for (int i = 0; i < len; i++) {
                *(data+i) = arr[i];
            }
            res[index++] = data;
            return;
        }
        for (int i = start; i < len; i++) { // 每个数字分别和后面的数字交换
            swap(&arr[start], &arr[i]);
            permuate(arr, start+1, len);
            swap(&arr[start], &arr[i]);
        }
    }
    
    void test() {
        int arr[] = {1,2,3};
        printf("全排列开始:\n");
        permuate(arr, 0, 3);
        printf("全排列结束:\n");
        for (int i = 0; i <= index; i++) {
            printArr(res[i], 3);
        }
    }
    
private:
    int *res[100];
    int index = 0;
};
