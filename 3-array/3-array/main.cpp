//
//  main.cpp
//  3-array
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>
#include "Search.cpp"
#include "Sort.hpp"
#include "Sum.cpp"
#include "Permuate.cpp"
#include "Reverse.cpp"

void printList(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d",*(arr+i));
    }
    printf("\n");
}


// 青蛙跳级与斐波那契数列
int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    }
    int n1 = 0;
    int n2 = 1;
    int count = 0;
    // 1 1 2 3 5
    for (int i = 1; i <= n; i++) {
        count = n1 + n2;
        n1 = n2;
        n2 = count;
    }
    return count;
}

int findPosition(int arr[],int left,int right) {
    int val = arr[left];
    for (int i = left; i <= right; i++) {
        if (arr[i] < val) {
            val = arr[i];
        }
    }
    return val;
}

// 旋转数组中的最小数字
int minRoateArray(int arr[],int n) {
    int left = 0;
    int right = n-1;
    int mid = 0;
    while (arr[left] >= arr[right]) { // 确保数组是旋转过的
        if (right - left == 1) {
            mid = right;
            break;
        }
        mid = (left + right) / 2;
        if (arr[left] == arr[mid] && arr[mid] == arr[right]) { // 无法判断中间数组属于左半部分和右半部分
            return findPosition(arr, left, right);
        }
        if (arr[mid] >= arr[left]) { // 中间数字位于左侧递增数组
            left = mid;
        } else { // 位于右侧递增数组
            right = mid;
        }
    }
    return arr[mid];
}

// 奇数判断
bool isOdd(int num) {
    return num & 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reorderOddEven(int *arr, int len) {
    int p1 = 0;
    int p2 = len-1;
    while (p1 < p2) {
        while (p1 < p2 && isOdd(*(arr+p1))) {
            p1++;
        }
        while (p1 < p2 && !isOdd(*(arr+p2))) {
            p2--;
        }
        if (p1 < p2) {
            swap(arr+p1, arr+p2);
        }
    }
}

// 顺时针打印数组
void printClockArr(int arr[][4],int rows,int cols) {
    if (rows == 0 || cols == 0) {
        return;
    }
    int iStart = 0; // 行的起始点
    int iEnd = rows - 1; // 行的终点
    int jStart = 0; // 列的起始点
    int jEnd = cols - 1; // 列的终点
    while (iStart < iEnd && jStart < jEnd) {
        for (int i = jStart; i <= jEnd; i++) {
            printf("%d ",arr[iStart][i]);
        }
        iStart++;
        for (int i = iStart; i <= iEnd; i++) {
            printf("%d ",arr[i][jEnd]);
        }
        jEnd--;
        for (int i = jEnd; i >= jStart; i--) {
            printf("%d ",arr[iEnd][i]);
        }
        iEnd--;
        for (int i = iEnd; i >= iStart; i--) {
            printf("%d ",arr[i][jStart]);
        }
        jStart++;
    }
}

void testRoateArr() {
    int roateArr[] = {3,4,5,1,2};
    int roateMin = minRoateArray(roateArr, 5);
    printf("旋转数组的最小数字:%d\n",roateMin);
}

void tesClockArray() {
    int arr[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printClockArr(arr, 4, 4);
}

int main() {
    int num1 = 5;
    int count = fibonacci(num1);
    printf("%d级台阶的总共步数:%d\n",num1,count);
    int order[9] = {1,2,3,4,5,6,7,8,9};
    reorderOddEven(order, 9);
    printList(order, 9);
    tesClockArray();
    printf("\n");
    Sort sort;
    sort.test();
    Sum sum;
    sum.test();
    Search searchData;
    searchData.test();
    Permuate permuate;
    permuate.test();
    Reverse reverse;
    reverse.test();
    return 0;
}
