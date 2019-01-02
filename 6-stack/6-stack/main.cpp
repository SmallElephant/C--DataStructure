//
//  main.cpp
//  6-stack
//
//  Created by FlyElephant on 2019/1/2.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
    void push(int val) {
        s1.push(val);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
private:
    stack<int> s1;
    stack<int> s2;
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    for (int i = 0; i < 2; i++) {
        printf("val:%d\n",queue.pop());
    }
    queue.push(3);
    printf("val:%d\n",queue.pop());
    return 0;
}
