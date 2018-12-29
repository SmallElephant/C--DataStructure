//
//  main.cpp
//  1-string
//
//  Created by FlyElephant on 2018/12/29.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "hello world";
    int len = (int)str.length();
    for (int i = 0; i <= len / 2; i++) {
        swap(str[i], str[len-i-1]);
    }
    cout<<str<<endl;
    return 0;
}
