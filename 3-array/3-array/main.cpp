//
//  main.cpp
//  3-array
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>

void printList(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d",*(arr+i));
    }
    printf("\n");
}

// 查找数组中重复的数字
void findRepeatedNumber(int *arr,int len) {
    int map[len];
    for (int i = 0; i < len; i++) {
        map[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        int index = arr[i] % len;
        map[index] = map[index] + 1;
    }
    for (int i = 0; i < len; i++) {
        if (map[i] > 1) {
            printf("重复的数字:%d---重复次数:%d\n",i,map[i]);
        }
    }
}

// 二维数组中查找指定的数字是否存在

bool findTargetNumber(int arr[][4],int num,int cols,int rows) {
    int row = 0;
    int col = cols - 1;
    while (row < cols && col >= 0) {
        int target = arr[row][col];
        if (num == arr[row][col]) {
            return true;
        } else if (num < target) {
            col--;
        } else {
            row++;
        }
    }
    return false;
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

int binarySearch(int arr[], int num, int n) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == num) {
            return mid;
        } else if (arr[mid] < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
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

int main() {
    int arr[7] = {2,3,4,5,2,3,1};
    findRepeatedNumber(arr, 7);
    int data[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    int num = 100;
    bool res = findTargetNumber(data, num, 4, 4);
    if (res) {
        printf("%d exist\n",10);
    } else {
        printf("not exist\n");
    }
    int num1 = 5;
    int count = fibonacci(num1);
    printf("%d级台阶的总共步数:%d\n",num1,count);
    int search[] = {3,8,9,10,11,12};
    int index =binarySearch(search, 8, 6);
    printf("二分查找位置:%d\n",index);
    int roateArr[] = {3,4,5,1,2};
    int roateMin = minRoateArray(roateArr, 5);
    printf("旋转数组的最小数字:%d\n",roateMin);
    int roateArr1[] = {1,0,1,1,1};
    int roateMin1 = minRoateArray(roateArr1, 5);
    printf("旋转数组的最小数字1:%d\n",roateMin1);
    int order[9] = {1,2,3,4,5,6,7,8,9};
    reorderOddEven(order, 9);
    printList(order, 9);
    return 0;
}
