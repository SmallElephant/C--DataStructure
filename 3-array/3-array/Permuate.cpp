//
//  Permuate.cpp
//  3-array
//
//  Created by FlyElephant on 2019/1/11.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
using namespace std;

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
    
    int convertToNumber(int arr[],int n) {
        if (arr == NULL) {
            return -1;
        }
        char str[100];
        strcpy(str, "");
        for (int i = 0; i < n; i++) {
            char nsum[10];
            sprintf(nsum, "%d", arr[i]);
            strcat(str, nsum);
        }
        return atoi(str);
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
        int min = convertToNumber(res[0], 3);
        for (int i = 0; i < index; i++) {
            int num = convertToNumber(res[i], 3);
            if (num <= min) {
                min = num;
            }
        }
        printf("数组全排列最小的值:%d\n",min);
    }
    
private:
    int *res[100];
    int index = 0;
};
