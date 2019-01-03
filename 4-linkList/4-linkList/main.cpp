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

LinkNode *deleteListNode2(LinkNode *root, char target) {
    if (root->data == target) {
        return root->next;
    } else {
        LinkNode *p = root;
        while (p->next != NULL) {
            if (p->next->data == target) {
                p->next = p->next->next;
                break;
            }
            p = p->next;
        }
        return root;
    }
}

LinkNode *deleteDuplicateNode(LinkNode *root) {
    LinkNode *p = root;
    while (p != NULL && p->next != NULL) {
        if (p->data != p->next->data) {
            p = p->next;
        } else {
            LinkNode *cur = p;
            while (cur->data == cur->next->data) {
                cur = cur->next;
            }
            p->next = cur->next;
        }
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
    LinkNode *root = deleteListNode2(&n1, 'D');
    printLinkList(root);
    printf("\n");
    
    LinkNode d1 = {'1',NULL};
    LinkNode d2 = {'2',NULL};
    LinkNode d3 = {'3',NULL};
    LinkNode d4 = {'3',NULL};
    LinkNode d5 = {'3',NULL};
    LinkNode d6 = {'4',NULL};
    LinkNode d7 = {'5',NULL};
    d1.next = &d2;
    d2.next = &d3;
    d3.next = &d4;
    d4.next = &d5;
    d5.next = &d6;
    d6.next = &d7;
    LinkNode *del = deleteDuplicateNode(&d1);
    printLinkList(del);
    printf("\n");
    return 0;
}
