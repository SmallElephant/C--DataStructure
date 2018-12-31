//
//  main.cpp
//  4-linkList
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>

struct LinkNode {
    char val;
    struct LinkNode *next;
};

// 从尾到头打印链表

void printFromTail(LinkNode *root,int len) {
    char *arr = (char *)malloc(sizeof(char) * len);
    int i = 0;
    LinkNode *node = root;
    while (node != NULL) {
        arr[i++] = node->val;
        node = node->next;
    }
    for (int j = i; j >= 0; j--) {
        printf("%c ",arr[j]);
    }
    printf("\n");
}

int main() {
    LinkNode node1 = {'A',NULL};
    LinkNode node2 = {'B',NULL};
    LinkNode node3 = {'C',NULL};
    node1.next = &node2;
    node2.next = &node3;
    printFromTail(&node1, 3);
    return 0;
}
