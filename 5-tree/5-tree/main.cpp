//
//  main.cpp
//  5-tree
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>

#define maxsize 10

typedef struct TBTNode {
    char data;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
    int ltag; // 0表示lchild指向是左孩子,1表示指向其前驱
    int rtag; // 0表示rchild指向是右孩子，1表示指向其后继
} TBTNode;


void visit(TBTNode *node) {
    printf("%c",node->data);
}

TBTNode *inorderlist(TBTNode *root,int len) {
    TBTNode *list = (TBTNode *)malloc(sizeof(TBTNode) * len);
    TBTNode *stack[maxsize];
    int top = -1;
    int i = 0;
    TBTNode *p = root;
    while (top >= 0 || p != NULL) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->lchild;
        }
        if (top >= 0) {
            TBTNode *node = stack[top--];
//            *node = TBNode node只是其中的一个地址
            *(list+i) = *node;
            i++;
            visit(node);
            p = node->rchild;
        }
    }
    return list;
}

int main() {
    TBTNode node1 = {'1',NULL,NULL};
    TBTNode node2 = {'2',NULL,NULL};
    TBTNode node3 = {'3',NULL,NULL};
    TBTNode node4 = {'4',NULL,NULL};
    TBTNode node5 = {'5',NULL,NULL};
    TBTNode node6 = {'6',NULL,NULL};
    node1.lchild = &node2;
    node1.rchild = &node4;
    node2.lchild = &node3;
    node2.rchild = &node5;
    node4.lchild = &node6;
    printf("\n");
    TBTNode *list = inorderlist(&node1, 6);
    for (int i=0; i < 6; i++) {
        TBTNode *node = list+i;
        printf("node的值：%c---\n\n",node->data);
        
    }
    return 0;
}
