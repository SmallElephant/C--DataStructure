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
    
    int numberOf1(int num) {
        int count = 0;
        while (num) {
            if (num % 10 == 1) {
                count++;
            }
            num = num / 10;
        }
        return count;
    }
    
    // 1~n整数中1出现的次数
    int numOf1From1ToN(int n) {
        int count = 0;
        for (int i = 0; i <= n; i++) {
            count += numberOf1(i);
        }
        return count;
    }
    
    int getNumOfK(int arr[],int len,int k) {
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (k == arr[i]) {
                count++;
            }
        }
        return count;
    }
    
    void test() {
//        int arr[7] = {2,3,4,5,2,3,1};
//        findRepeatedNumber(arr, 7);
//        int data[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
//        int num = 100;
//        bool res = findTargetNumber(data, num, 4, 4);
//        if (res) {
//            printf("%d exist\n",10);
//        } else {
//            printf("not exist\n");
//        }
//        int arr1[] = {1,2,3,4,5,6,1,1,1};
//        int val = findMoreHalfNumber(arr1, 9);
//        if (val > 0) {
//            printf("超过一半的数字:%d\n",val);
//        } else {
//            printf("没有超过一半的数字\n");
//        }
//        int search[] = {3,8,9,10,11,12};
//        int index =binarySearch(search, 8, 6);
//        printf("二分查找位置:%d\n",index);
        int count = numOf1From1ToN(12);
        printf("1出现的总共次数:%d\n",count);
        int arr[] = {1,2,3,3,3,3,5,6};
        int nums = getNumOfK(arr, 8, 3);
        printf("出现的次数:%d\n",nums);
    }
};

