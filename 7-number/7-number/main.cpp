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

int main() {
    int num = 9;
    int *res = convertToBinary(num);
    for (int i = 0; i < 10; i++) {
        int t = *(res+i);
        printf("current value:%d\n",t);
    }
    int p = 0;
    scanf("%d",&p);
    if (p < 0) {
        printf("invalid arguements\n");
    } else {
        int count = countBinaryNum(p);
        printf("%d中1的个数:%d\n",p,count);
    }
    return 0;
}
