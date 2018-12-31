//
//  main.cpp
//  2-input
//
//  Created by FlyElephant on 2018/12/30.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>
using namespace std;

#define maxsize 100

int main() {
    char num[maxsize];
    char t;
    scanf("%s",num);
    getchar();
    scanf("%c",&t);
    int start = -1;
    int end = -1;
    int len = 0;
    int index = 0;
    while (*(num+index)!= '\0') {
        index = index + 1;
        len = len+1;
    }
    for (int i = 0; i < len; i++) {
        if (num[i] == t) {
            if (start == -1) {
                start = i;
            }
            end = i;
        }
    }
    printf("input data %s--%c--start:%d---end:%d\n",num,t,start,end);
    return 0;
}
