//
//  main.cpp
//  1-string
//
//  Created by FlyElephant on 2018/12/29.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>
using namespace std;

// 字符串反转
void reverseString(char str[],int len) {
    for (int i = 0; i <= len / 2; i++) {
        swap(str[i], str[len-i-1]);
    }
}

//替换空格
char *replaceSpace(char str[],int len) {
    int count = 0;
    int total = len;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    total += count * 2;
    char *res = (char *)malloc(sizeof(char) * total);
    int j = 0;
    for (int i = 0; i < total; i++) {
        if (str[i] != ' ') {
            res[j++] = str[i];
        } else {
            res[j++] = '%';
            res[j++] = '2';
            res[j++] = '0';
        }
    }
    return res;
}

// 原地替换字符串
void replaceSpace2(char str[],int maxLen) {
    int count = 0;
    int len = 0;
    int i = 0;
    while (str[i++] != '\0') {
        len++;
        if (str[i] == ' ') {
            count++;
        }
    }
    int newlen = len + count * 2;
    int pre = len - 1;
    int next = newlen - 1;
    while (pre >= 0 && next > pre) {
        if (str[pre] != ' ') {
            str[next--] = str[pre];
        } else {
            str[next--] = '0';
            str[next--] = '2';
            str[next--] = '%';
        }
        pre--;
    }
}

int main() {
    char str[] = "hello world";
    reverseString(str, 11);
    printf("%s\n",str);
    cout<<str<<endl;
    char str2[] = "we are happy";
    int len = sizeof(str2) / sizeof(str2[0]) - 1;
    char *res = replaceSpace(str2, len);
    printf("res:%s\n",res);
    char str3[100] = "I am a man";
    replaceSpace2(str3, 100);
    printf("%s\n",str3);
    return 0;
}
