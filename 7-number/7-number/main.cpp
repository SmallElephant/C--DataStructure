//
//  main.cpp
//  7-number
//
//  Created by FlyElephant on 2019/1/3.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>

#define maxsize 100
int *convertToBinary(int num) {
    int *arr = (int *)malloc(sizeof(int) * maxsize);
    int p = num;
    int i = 0;
    while (p > 0) {
        int t = p % 2;
        *(arr+i) = t;
        p = p / 2;
        i++;
    }
    return arr;
}

int countBinaryNum(int num) {
    int count = 0;
    int p = num;
    while (p > 0) {
        int mod = p % 2;
        if (mod == 1) {
            count++;
        }
        p = p / 2;
    }
    return count;
}

int numof1(int num) {
    int flag = 1;
    int count = 0;
    int n = num;
    while (flag) {
        if (n & flag) {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

int numof1_2(int num) {
    int count = 0;
    int n = num;
    while (n) {
        if (n & 1) { //  位运算
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main() {
    int num = 9;
    int *res = convertToBinary(num);
    for (int i = 0; i < 10; i++) {
        int t = *(res+i);
        printf("current value:%d\n",t);
    }
    int p = 9;
    int count = countBinaryNum(p);
    printf("%d中1的个数:%d\n",p,count);
    int num1 = numof1(0x1001);
    printf("1--%d中1的个数:%d\n",p,num1);
    int num2 = numof1_2(p);
    printf("1--%d中1的个数:%d\n",p,num2);
    return 0;
}
