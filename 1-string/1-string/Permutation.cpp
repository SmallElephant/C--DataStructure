//
//  Permutation.cpp
//  1-string
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
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
    
    // 位图实现所有子集
    
    void allsubnets(char *str) {
        int len = (int)strlen(str);
        if (len == 0) {
            return;
        }
        int max = 1 << len;
        for (int i = 0; i < max; i++) {
            string s;
            for (int j = 0; j < len; j++) { // 判断i的每一位是否为1
                int t =  1 << j;
                if (i & t) {
                    s.push_back(*(str+j));
                }
            }
            if (s != "") {
                cout<<s<<endl;
            }
        }
    }
    
    // 循环实现字符串的所有子集
    vector<string> getAllSubnets(string str) {
        vector<string> res;
        if (str.size() == 0) {
            return res;
        }
        res.push_back("");
        for (int i = 0; i < str.size(); i++) {
            char cur = str[i]; // 当前的字符
            int size = (int)res.size();
            for (int j = 0; j < size; j++) {
                string pre = res[j];
                string des = pre + cur;
                res.push_back(des);
            }
        }
        return res;
    }
    
    vector<string> getAllSubstring(string str,int end) {
        vector<string> res;
        if (end == -1) {
            res.push_back("");
            return res;
        }
        vector<string> next = getAllSubstring(str, end - 1);
        for (int i = 0; i < next.size(); i++) {
            res.push_back(next[i]);
            string s = next[i] + str[end];
            res.push_back(s);
        }
        return res;
    }
    
    void printVector(vector<string> list) {
        for (int i = 0; i < list.size(); i++) {
            cout<<list[i]<<endl;
        }
    }
    
    void test() {
        char p[] = "abc";
        printf("字符串的全排列:\n");
        permute(p, 0, 2);
        printf("字符串的所有子串:\n");
        allsubnets(p);
        printf("所有字符串方法2:\n");
        vector<string> res = getAllSubnets("abc");
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != "") {
                cout<<res[i]<<endl;
            }
        }
        printf("所有字符串方法3:\n");
        vector<string> res2 = getAllSubstring("abc", 2);
        printVector(res2);
    }
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
