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
    
    void insertSort(int arr[],int n) {
        if (n <= 0) {
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (arr[j] < arr[j-1]) {
                    swap(&arr[j], &arr[j-1]);
                }
            }
        }
    }
    
    // 选择排序
    void selectSort(int arr[],int n) {
        for (int i = 0; i < n; i++) {
            int last= n - i - 1;
            int max = arr[last];
            int maxIndex = last;
            for (int j = 0; j < last; j++) {
                if (arr[j] > max) {
                    maxIndex = j;
                    max = arr[j];
                }
            }
            swap(&arr[maxIndex], &arr[last]);
        }
    }
    
    // 构建最大堆
    void max_heapify(int arr[],int start,int end) {
        int dad = start;
        int son = start * 2 + 1;
        while (son <= end) {
            if (son+1 <= end && arr[son] < arr[son+1]) { // 左右孩子结点中找到最大的结点
                son++;
            }
            if (arr[dad] > arr[son]) {
                return;
            } else {
                swap(&arr[dad], &arr[son]);
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }
    
    void heapSort(int arr[],int n) {
        for (int i = n/2 - 1; i >= 0; i--) { // 构造最大堆
            max_heapify(arr, i, n);
        }
        printArr(arr, n);
        for (int i = n - 1; i>= 0 ; i--) {
            swap(&arr[0], &arr[i]);
            max_heapify(arr, 0, i-1);
        }
        printArr(arr, n);
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
        int insertArr[] = {3,4,1,2,8,10,5,6,7,9};
        printf("插入排序之后的结果:\n");
        insertSort(insertArr, 10);
        printArr(insertArr, 10);
        int heapArr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
        int len = (int)sizeof(heapArr) / sizeof(*heapArr);
        printf("堆排序之后的结果:\n");
        heapSort(heapArr, len);
        int selectArr[] = {3,4,1,2,8,10,5,6,7,9};
        printf("选择排序之后的结果:\n");
        selectSort(selectArr, 10);
        printArr(selectArr, 10);
    }
    
};
