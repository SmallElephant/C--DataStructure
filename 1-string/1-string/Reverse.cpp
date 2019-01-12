//
//  Reverse.cpp
//  1-string
//
//  Created by FlyElephant on 2019/1/12.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>

class Reverse {
    
public:
    
    void reversestring(char *str,int l,int r) {
        while (l <= r) {
            swap(str+l, str+r);
            l++;
            r--;
        }
    }
    
    void reverse(char *str) {
        int len = (int)strlen(str);
        reversestring(str, 0, len - 1);
        int begin = 0;
        int end = 0;
        while (begin <= end && end < len) { // 遍历字符串
            while (*(str+end) != ' ') {
                if (*(str+end) == '\0') {
                    break;
                } else {
                    end++;
                }
            }
            reversestring(str, begin, end - 1);
            end++;
            begin = end;
        }
    }
    
    void test() {
        char restr[] = "I am a man.";
        reverse(restr);
        printf("反转的字符串:%s\n",restr);
    }
    
private:
    
    void swap(char *a,char *b) {
        char tmp = *a;
        *a = *b;
        *b = tmp;
    }
    
};
