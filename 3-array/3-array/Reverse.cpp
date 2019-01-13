//
//  Reverse.cpp
//  3-array
//
//  Created by FlyElephant on 2019/1/13.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include "Reverse.hpp"
#include <iostream>
#include <math.h>
using namespace std;

class Reverse {
public:
    
    int reversePairs(int arr[],int n) {
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    res++;
                }
            }
        }
        return res;
    }
    
    // n个骰子的概率
    void probability(int number,int max) { // 骰子的个数，骰子的最大点数
        int size = number * max + 1;
        int **result = (int **)malloc(sizeof(int *) * 2);
        result[0] = (int *)malloc(sizeof(int) * size);
        result[1] = (int *)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) { //数据初始化
            result[0][i] = 0;
            result[1][i] = 0;
        }
        int flag = 0;
        for (int i = 1; i <= max; i++) { // 初始化第一个骰子出现的次数
            result[flag][i] = 1;
        }
        for (int i = 2; i <= number; i++) { // 遍历其他骰子
            for (int m = 0; m < i; m++) {
                result[1-flag][m] = 0;
            }
            for (int k = i; k <= i * max ; k++) {
                result[1-flag][k] = 0;
                for (int j = 1; j <= k && j <= max; j++) {
                    result[1-flag][k] += result[flag][k - j];
                }
            }
            flag = 1 - flag;
        }
        for (int i = 1; i < size; i++) {
            printf("骰子%d出现的次数:%d\n",i,result[flag][i]);
        }
    }
    
    void printArr(int arr[],int n) {
        for (int i = 0; i < n; i++) {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    
    bool isContinuous(int arr[],int n) {
        Sort sort;
        sort.quickSort(arr, 0, n-1);
        printArr(arr, n);
        int numOfZero = 0;
        int numOfGap = 0;
        int pre = arr[0];
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                numOfZero++;
            } else {
                if (arr[i] == pre) {
                    return false;
                }
                int gap = arr[i] - pre - 1;
                pre = arr[i];
                numOfGap += gap;
            }
        }
        return numOfGap == numOfZero ? true : false;
    }
    
    
    int maxDiff(int arr[],int n) {
        if (n <= 0) {
            return -1;
        }
        int maxDiff = 0;
        int min = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
            int diff = arr[i] - min;
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
        return maxDiff;
    }
    
    // 数组中的逆序对
    void test() {
        int arr[] = {7,5,6,4};
        int count = reversePairs(arr, 4);
        printf("数组中逆序对出现的次数:%d\n",count);
        probability(6, 6);
        int contious[] = {0,2,1,3,8};
        bool isContious = isContinuous(contious, 5);
        if (isContious) {
            printf("是顺子\n");
        } else {
            printf("不是顺子\n");
        }
        int diffArr[] = {9,11,8,5,7,12,16,14};
        int diff = maxDiff(diffArr,8);
        printf("最大的差额:%d\n",diff);
    }
};
