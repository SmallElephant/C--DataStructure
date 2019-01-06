//
//  main.cpp
//  6-stack
//
//  Created by FlyElephant on 2019/1/2.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include "MinStack.cpp"
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

// 栈的压入，弹出序列

bool isPopOrder(vector<int> pushV,vector<int> popV) {
    if (pushV.size() == 0) {
        return false;
    }
    vector<int> stack;
    for (int i = 0, j = 0; i < pushV.size(); i++) {
        stack.push_back(pushV[i]);
        while (j < popV.size() && stack.back() == popV[j]) {
            stack.pop_back();
            j++;
        }
    }
    return stack.empty();
}

void testPopOrder() {
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {4,5,3,2,1};
    bool res = isPopOrder(pushV, popV);
    if (res) {
        printf("is pop order\n");
    } else {
        printf("is not pop order\n");
    }
}

void tesMinStack() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(4);
    minStack.push(2);
    minStack.push(1);
    printf("min:%d\n",minStack.min());
    minStack.pop();
    printf("min:%d\n",minStack.min());
    minStack.push(0);
    printf("min:%d\n",minStack.min());
}

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    for (int i = 0; i < 2; i++) {
        printf("val:%d\n",queue.pop());
    }
    queue.push(3);
    printf("val:%d\n",queue.pop());
    testPopOrder();
    tesMinStack();
    return 0;
}
