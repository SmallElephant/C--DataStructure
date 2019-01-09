//
//  main.cpp
//  8-queue
//
//  Created by FlyElephant on 2019/1/9.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <queue>
#include "MedianQueue.cpp"
using namespace std;

int main() {
    priority_queue<int> queue;
    queue.push(1);
    queue.push(10);
    queue.push(3);
    queue.push(8);
    while (queue.size() > 0) {
        cout<<queue.top()<<endl;
        queue.pop();
    }
    MedianQueue medianQueue;
    for (int i = 0; i < 10; i++) {
        medianQueue.insert(i);
    }
    
    double res = medianQueue.getMedian();
    printf("中位数%f\n",res);
    return 0;
}
