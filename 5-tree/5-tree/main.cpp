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

// 二叉树的中序线索化
TBTNode *pre=NULL;
void inThread(TBTNode *p) {
    if (p == NULL) {
        return;
    }
    inThread(p->lchild);
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = 1;
    }
    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = 1;
    }
    pre = p;
    inThread(p->rchild);
}

void createThread(TBTNode *root) {
    if (root == NULL) {
        return;
    }
    inThread(root);
    pre->rtag = 1;
    pre->rchild = NULL;
}

// 中序线索化的第一个节点

TBTNode *first(TBTNode *p) {
    while (p->ltag==0) {
        p = p->lchild; // 最左下的孩子
    }
    return p;
}

TBTNode *next(TBTNode *p) {
    if (p->rtag == 0) {
        return first(p->rchild); // 右孩子的最左下的节点
    } else {
        return p->rchild; // 后继存在直接返回后继
    }
}

void inOrderThread(TBTNode *root) {
    for (TBTNode *p=first(root); p != NULL; p = next(p)) {
        visit(p);
    }
}

void preThread(TBTNode *p) {
    if (p == NULL) {
        return;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rtag = 1;
        pre->rchild = p;
    }
    if (p->lchild == NULL) {
        p->ltag = 1;
        p->lchild = pre;
    }
    pre = p;
    if (p->ltag == 0) {
        preThread(p->lchild);
    }
    if (p->rtag == 0) {
        preThread(p->rchild);
    }
}

void printPreThread(TBTNode *root) {
    if (root == NULL) {
        return;
    }
    TBTNode *p = root;
    while (p != NULL) {
        while (p->ltag==0) {//左线索不存在
            visit(p);
            p = p->lchild;
        }
        visit(p);
        p = p->rchild;//不论是否为线索都指向后继
    }
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
    // 先序遍历打印
//    preThread(&node1);
//    printPreThread(&node1);
    createThread(&node1);
    inOrderThread(&node1);
    printf("\n");
    return 0;
}
