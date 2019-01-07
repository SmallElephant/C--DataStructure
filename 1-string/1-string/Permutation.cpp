//
//  Permutation.cpp
//  1-string
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Permute {
public:
    // 全排列就是字符串的每个字符分别和其他的字符进行交换
    void permute(char *str,int l,int r) {
        if (l==r) {
            printf("%s\n",str);
            return;
        }
        for (int i = l; i <= r; i++) {
            swap((str+l), (str+i));// 首个字符和其他的字符进行交换
            permute(str, l+1, r);
            swap((str+l), (str+i));//恢复原状
        }
    }
    
    void test() {
        char p[] = "abc";
        printf("字符串的全排列:\n");
        permute(p, 0, 2);
        printf("字符串的所有子串:\n");    }
private:
    void printChar(char *str,int l,int r) {
        for (int i = l; i <= r; i++) {
            printf("%c",*(str+i));
        }
        printf("\n");
    }
    
    void swap(char *a,char *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};
