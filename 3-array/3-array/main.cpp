//
//  main.cpp
//  3-array
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>

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
    return 0;
}
