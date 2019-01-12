//
//  Search.cpp
//  4-linkList
//
//  Created by FlyElephant on 2019/1/12.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include "Common.hpp"
using namespace std;

class Search {
public:
    
    LinkNode *findFirstNode(LinkNode *root1,LinkNode *root2) {
        LinkNode *res = NULL;
        int len1 = getLinkListLength(root1);
        int len2 = getLinkListLength(root2);
        LinkNode *p1 = root1;
        LinkNode *p2 = root2;
        if (len1 > len2) {
            p1 = moveForward(p1, len1 - len2);
        } else {
            p2 = moveForward(p2, len2 - len1);
        }
        while (p1 != NULL && p2 != NULL && p1->data != p2->data) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    
    void test() {
        LinkNode node1 = {'1',NULL};
        LinkNode node2 = {'2',NULL};
        LinkNode node3 = {'3',NULL};
        LinkNode node4 = {'6',NULL};
        LinkNode node5 = {'7',NULL};
        node1.next = &node2;
        node2.next = &node3;
        node3.next = &node4;
        node4.next = &node5;
        LinkNode n1 = {'4',NULL};
        LinkNode n2 = {'5',NULL};
        LinkNode n3 = {'6',NULL};
        LinkNode n4 = {'7',NULL};
        n1.next = &n2;
        n2.next = &n3;
        n3.next = &n4;
        LinkNode *first = findFirstNode(&node1, &n1);
        if (first != NULL) {
            printf("第一个相同结点的值:%c\n",first->data);
        } else {
            printf("无相同的公共结点");
        }
    }
    
private:
    
    LinkNode *moveForward(LinkNode *root,int steps) {
        for (int i = 0; i < steps; i++) {
            root = root->next;
        }
        return root;
    }
    
    int getLinkListLength(LinkNode *root) {
        int count = 0;
        LinkNode *p = root;
        while (p != NULL) {
            count++;
            p = p->next;
        }
        return count;
    }
    
};
