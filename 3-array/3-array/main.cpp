//
//  main.cpp
//  3-array
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>

int main() {
    int len = 7;
    int arr[7] = {2,3,1,0,2,5,3};
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
    return 0;
}
