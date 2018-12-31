//
//  main.cpp
//  5-tree
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>

#define maxsize 10

typedef struct BTNode {
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

void visit(BTNode *node) {
    printf("%c",node->data);
}

// 先序递归遍历
void preOrder(BTNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%c",root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

// 先序遍历的非递归遍历
void preorderNorecursion(BTNode *root) {
    BTNode *stack[10];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        BTNode *node = stack[top--];
        visit(node);
        if (node->rchild != NULL) {
            stack[++top] = node->rchild;
        }
        if (node->lchild != NULL) {
            stack[++top] = node->lchild;
        }
    }
}

//中序遍历
void inorder(BTNode *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->lchild);
    visit(root);
    inorder(root->rchild);
}

void inorderNonrecursion(BTNode *root) {
    BTNode *stack[maxsize];
    int top = -1;
    BTNode *p = root;
    while (top >= 0 || p != NULL) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->lchild;
        }
        if (top >= 0) {
            BTNode *node = stack[top--];
            visit(node);
            p = node->rchild;
        }
    }
}

// 后序遍历
void postorder(BTNode *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    visit(root);
}

void postorderNonrecursion(BTNode *root) {
    BTNode *stack[maxsize];
    int top = -1;
    stack[++top] = root;
    BTNode *stack2[maxsize];
    int top2 = -1;
    while (top >= 0) {
        BTNode *node = stack[top--];
        stack2[++top2] = node;
        if (node->lchild != NULL) {
            stack[++top] = node->lchild;
        }
        if (node->rchild != NULL) {
            stack[++top] = node->rchild;
        }
    }
    while (top2 >= 0) {
        BTNode *node = stack2[top2--];
        visit(node);
    }
    printf("\n");
}

int main() {
    BTNode node1 = {'1',NULL,NULL};
    BTNode node2 = {'2',NULL,NULL};
    BTNode node3 = {'3',NULL,NULL};
    BTNode node4 = {'4',NULL,NULL};
    BTNode node5 = {'5',NULL,NULL};
    node1.lchild = &node2;
    node1.rchild = &node4;
    node2.lchild = &node3;
    node2.rchild = &node5;
    preOrder(&node1);
    printf("\n");
    preorderNorecursion(&node1);
    printf("\n");
    inorder(&node1);
    printf("\n");
    inorderNonrecursion(&node1);
    printf("\n");
    postorder(&node1);
    printf("\n");
    printf("后序非递归遍历:");
    postorderNonrecursion(&node1);
    return 0;
}
