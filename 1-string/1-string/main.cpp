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

int main() {
    char str[] = "hello world";
    reverseString(str, 11);
    printf("%s\n",str);
    cout<<str<<endl;
    char str2[] = "we are happy";
    int len = sizeof(str2) / sizeof(str2[0]) - 1;
    char *res = replaceSpace(str2, len);
    printf("res:%s\n",res);
    return 0;
}
