//
//  MinStack.cpp
//  6-stack
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> dataStack;
    stack<int> minStack;
    
    void push(int val) {
        dataStack.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            int min = val <= minStack.top() ? val : minStack.top();
            minStack.push(min);
        }
    }
    
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int min() {
        return minStack.top();
    }
};
