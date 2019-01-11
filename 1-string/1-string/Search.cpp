//
//  Search.cpp
//  1-string
//
//  Created by FlyElephant on 2019/1/11.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
using namespace std;

class Search {
public:
    
    int findNumber(char *str, int position) {
        char val = *(str+position);
        return val - '0';
    }
    
    void test() {
        char str[] = "012345678910";
        int val = findNumber(str, 5);
        printf("字符串中的数字:%d\n",val);
    }
};
