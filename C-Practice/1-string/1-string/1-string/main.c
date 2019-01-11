//
//  main.c
//  1-string
//
//  Created by FlyElephant on 2018/12/29.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <stdio.h>
//#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b= t;
}

void swapchar(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b= t;
}

int main() {
    int a = 10;
    int b= 100;
    swap(&a, &b);
    printf("%d---%d\n",a,b);
    char s[] = "hello world";
    int len = sizeof(s) / sizeof(s[0]) - 1;
    for (int i = 0; i <= len / 2; i++) {
        swapchar(&s[i], &s[len-i-1]);
    }
    printf("%s\n",s);
    char str[100];
    sprintf(str, "%d", 42);
    printf("转换之后的结果:%s\n",str);
    return 0;
}
