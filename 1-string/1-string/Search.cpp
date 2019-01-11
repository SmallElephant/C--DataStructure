//
//  Search.cpp
//  1-string
//
//  Created by FlyElephant on 2019/1/11.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Search {
public:
    
    int findNumber(char *str, int position) {
        char val = *(str+position);
        return val - '0';
    }
    
    int findNotRepeatingNumber(string str) {
        map<char,int> hashMap;
        for (int i = 0; i < str.size(); i++) {
            hashMap[str[i]] += 1;
        }
        int index = -1;
        for (int i = 0; i < str.size(); i++) {
            if (hashMap[str[i]] == 1) {
                index = i;
                break;
            }
        }
        return index;
    }
    
    void test() {
        char str[] = "012345678910";
        int val = findNumber(str, 5);
        printf("字符串中的数字:%d\n",val);
        string repeatingStr = "abaccdeff";
        int index = findNotRepeatingNumber(repeatingStr);
        printf("第一个只出现一次字符的位置:%d\n",index);
    }
};
