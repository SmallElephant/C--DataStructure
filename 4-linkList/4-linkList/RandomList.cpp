//
//  RandomList.cpp
//  4-linkList
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//
#include <iostream>
using namespace std;

 struct RandomListNode {
     char data;
     struct RandomListNode *next;
     struct RandomListNode *random;
 };

class RandomList {
    
public:
    RandomListNode *clone(RandomListNode *pHead) {
        if (pHead == NULL) {
            return NULL;
        }
        RandomListNode *head = pHead;
        // 1.复制每个结点
        while (head != NULL) {
            RandomListNode *clone = new RandomListNode();
            RandomListNode *next = head->next;
            clone->data = head->data;
            head->next = clone;
            clone->next = next;
            head = next;
        }
        // 2.复制结点的随机结点连接
        RandomListNode *randomHead = pHead;
        while (randomHead != NULL) {
            RandomListNode *clone = randomHead->next;
            RandomListNode *random = randomHead->random;
            if (random != NULL) {
                clone->random = random->next;
            }
            randomHead = clone->next;
        }
        // 3.断开结点连接
        RandomListNode *head1 = pHead;
        RandomListNode *root = pHead->next;
        while (head1->next != NULL) {
            RandomListNode *next = head1->next;
            head1->next = next->next;
            head1 = next;
        }
        return root;
    }
    
    void printListNode(RandomListNode *root) {
        RandomListNode *head = root;
        while (head != NULL) {
            RandomListNode *next = head->next;
            printf("%c ",head->data);
            head = next;
        }
        printf("\n");
    }
    
    void test() {
        RandomListNode h1 = {'A',NULL,NULL};
        RandomListNode h2 = {'B',NULL,NULL};
        RandomListNode h3 = {'C',NULL,NULL};
        RandomListNode h4 = {'D',NULL,NULL};
        RandomListNode h5 = {'E',NULL,NULL};
        h1.next = &h2;
        h2.next = &h3;
        h3.next = &h4;
        h4.next = &h5;
        h1.random = &h3;
        h2.random = &h5;
        h4.random = &h2;
        printListNode(&h1);
        RandomListNode *head = clone(&h1);
        printListNode(head);
    }
};
