//
//  Permutation.cpp
//  1-string
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>

class Permute {
public:
    void permute(char *str,int l,int r) {
        if (l==r) {
            printf("%s\n",str);
        }
        for (int i=l; i <= r ; i++) {
            swap((str+l), (str+i));
            permute(str, l+1, r);
            swap((str+l), (str+i));
        }
    }
    
    void test() {
        char p[] = "abc";
        permute(p, 0, 2);
    }
private:
    void swap(char *a,char *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
};
