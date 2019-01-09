//
//  MedianQueue.cpp
//  8-queue
//
//  Created by FlyElephant on 2019/1/9.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianQueue {
public:
    void insert(int num) {
        if (lqueue.empty() || num <= lqueue.top()) {
            lqueue.push(num);
        } else {
            rqueue.push(num);
        }
        if (lqueue.size() == rqueue.size() + 2) { // 左队列中元素的格式最多超出右队列一个
            rqueue.push(lqueue.top());
            lqueue.pop();
        }
        if (lqueue.size() + 1 == rqueue.size()) {
            lqueue.push(rqueue.top());
            rqueue.pop();
        }
    }
    
    double getMedian() { // 数组中元素的个数为奇数，选择左队列中的最大值，保证左队列元素的个数大于右队列
        return lqueue.size() == rqueue.size() ? (lqueue.top() + rqueue.top()) / 2 : lqueue.top();
    }
    
private:
    priority_queue<int,vector<int>,less<int>> lqueue; // 递减序列
    priority_queue<int,vector<int>,greater<int>> rqueue; // 递增序列
};
