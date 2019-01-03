//
//  main.cpp
//  4-linkList
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>

typedef struct LinkNode {
    char data;
    struct LinkNode *next;
} LinkNode;

void visit(LinkNode *node) {
    if (node == NULL) {
        return;
    }
    printf("%c",node->data);
}

void printLinkList(LinkNode *root) {
    LinkNode *p = root;
    while (p != NULL) {
        visit(p);
        p = p->next;
    }
}

// 从尾到头打印链表

void printFromTail(LinkNode *root,int len) {
    char *arr = (char *)malloc(sizeof(char) * len);
    int i = 0;
    LinkNode *node = root;
    while (node != NULL) {
        arr[i++] = node->data;
        node = node->next;
    }
    for (int j = i; j >= 0; j--) {
        printf("%c ",arr[j]);
    }
    printf("\n");
}

LinkNode *deleteListNode(LinkNode *root, char target) {
    LinkNode *pre = NULL;
    LinkNode *p = root;
    while (p != NULL) {
        if (p->data == target) {
            if (pre == NULL) {
                root = p->next;
            } else {
                pre->next = p->next;
            }
            break;
        }
        pre = p;
        p = p->next;
    }
    return root;
}

int main() {
    LinkNode node1 = {'A',NULL};
    LinkNode node2 = {'B',NULL};
    LinkNode node3 = {'C',NULL};
    node1.next = &node2;
    node2.next = &node3;
    printFromTail(&node1, 3);
    LinkNode n1 = {'A',NULL};
    LinkNode n2 = {'B',NULL};
    LinkNode n3 = {'C',NULL};
    LinkNode n4 = {'D',NULL};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    printLinkList(&n1);
    printf("\n");
    LinkNode *root = deleteListNode(&n1, 'A');
    printLinkList(root);
    printf("\n");
    return 0;
}
