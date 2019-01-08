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
    
    int partition(int arr[],int start,int end) {
        int pivot = arr[end];
        int left = start;
        int right = end-1;
        while (left < right) {
            while (left < right && arr[left] <= pivot) {
                left++;
            }
            while (left < right && arr[right] > pivot) {
                right--;
            }
            if (left < right) {
                 swap(&arr[left], &arr[right]);
            }
        }
        if (arr[left] >= arr[end]) {
            swap(&arr[left], &arr[end]);
        } else {
            left++;
        }
        return left;
    }
    
    int partition2(int arr[],int start,int end) {
        int sortIndex = start;
        int pivot = arr[end];
        for (int i = start; i < end; i++) {
            if (arr[i] < pivot) {
                swap(&arr[sortIndex], &arr[i]);
                sortIndex++;
            }
        }
        swap(&arr[sortIndex], &arr[end]);
        return sortIndex;
    }
    
    void quickSort(int arr[],int start,int end) {
        if (start > end) {
            return;
        }
        int mid = partition(arr, start, end);
        quickSort(arr, start, mid-1);
        quickSort(arr, mid+1, end);
    }
    
    void quickSort2(int arr[],int start,int end) {
        if (start > end) {
            return;
        }
        int mid = partition2(arr, start, end);
        quickSort2(arr, start, mid-1);
        quickSort2(arr, mid+1, end);
    }
    
    void test() {
        int arr[] = {3,4,1,2,8,10,5,6,7,9};
        bubbleSort(arr, 10);
        printArr(arr, 10);
        int quickArr[] = {3,4,1,2,8,10,5,6,7,9};
        printf("快速排序之后的结果:\n");
        quickSort(quickArr, 0, 9);
        printArr(quickArr, 10);
        int quickArr2[] = {3,4,1,2,8,10,5,6,7,9};
        printf("快速排序之后的结果2:\n");
        quickSort2(quickArr2, 0, 9);
        printArr(quickArr2, 10);
    }
    
};
