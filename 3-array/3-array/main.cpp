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
    return 0;
}
