//
//  main.cpp
//  1-string
//
//  Created by FlyElephant on 2018/12/29.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>
#include "Permutation.cpp"
#include "Search.cpp"
#include "Reverse.cpp"
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

int *mergeArr(int a[],int b[],int len1,int len2) {
    int len = len1 + len2;
    int *arr = (int *)malloc(sizeof(int) * len);
    int k = 0;
    int i = 0;
    int j = 0;
    while (i < len1 && j < len2) {
        if (a[i] < b[j]) {
            arr[k++] = a[i++];
        } else {
            arr[k++] = b[j++];
        }
    }
    while (i < len1) {
        arr[k++] = a[i++];
    }
    while (j < len2) {
        arr[k++] = b[j++];
    }
    return arr;
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
    
    int a[5] = {1,3,5,7,9};
    int b[5] = {2,4,6,8,10};
    int *res1 = mergeArr(a, b, 5, 5);
    int count = 10;
    for (int i = 0; i < count; i++) {
        printf("%d\n",res1[i]);
    }
    Permute permute;
    permute.test();
    Search search;
    search.test();
    Reverse reverse;
    reverse.test();
    return 0;
}
