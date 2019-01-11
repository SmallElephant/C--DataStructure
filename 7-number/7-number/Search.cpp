//
//  Search.cpp
//  7-number
//
//  Created by FlyElephant on 2019/1/11.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>

class Search {
public:
    
    bool isUglyNumber(int num) {
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1 ? true : false;
    }
    
    int uglyNumber(int index) {
        int num = 0;
        int i = 0;
        while (num < index) {
            i++;
            if (isUglyNumber(i)) {
                num++;
            }
        }
        return i;
    }
    
    int minOfNumbers(int a,int b,int c) {
        int mid = a < b ? a : b;
        return mid < c ? mid : c;
    }
    
    int uglyNumber2(int index) {
        if (index < 7) {
            return index;
        }
        int arr[index];
        arr[0] = 1;
        int t2 = 0;
        int t3 = 0;
        int t5 = 0;
        for (int i = 1; i < index; i++) {
            int num2 = arr[t2] * 2;
            int num3 = arr[t3] * 3;
            int num5 = arr[t5] * 5;
            arr[i] = minOfNumbers(num2, num3, num5);
            if (arr[i] == num2) {
                t2++;
            }
            if (arr[i] == num3) {
                t3++;
            }
            if (arr[i] == num5) {
                t5++;
            }
        }
        return arr[index-1];
    }
    
    void test() {
        int uglyRes = uglyNumber(10);
        printf("最终的丑数:%d\n",uglyRes);
        int uglyRes2 = uglyNumber2(10);
        printf("最终的丑数:%d\n",uglyRes2);
    }
    
};
