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

typedef struct Level {
    struct BTNode *node;
    int lno;
} Level;

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

void printPath(char path[],int len) {
    for (int i = 0; i < len; i++) {
        printf("%c->",path[i]);
    }
    printf("\n");
}

void printTargetPath(char path[], int len,int target) {
    int sum = 0;
    char res[maxsize];
    for (int i = 0; i < len; i++) {
        sum += path[i] - '0';
        res[i] = path[i];
    }
    if (sum == target) {
        for (int i = 0; i < len; i++) {
            printf("%c",res[i]);
        }
        printf("\n");
    }
}

void printAllPaths(BTNode *root,char paths[],int len) {
    if (root == NULL) {
        return;
    }
    paths[len++] = root->data;
    if (root->lchild == NULL && root->rchild == NULL) {
//        printPath(paths, len);
        printTargetPath(paths, len, 15);
    }
    printAllPaths(root->lchild, paths, len);
    printAllPaths(root->rchild, paths, len);
}

// 二叉树的高度

int getTreeHeight(BTNode *root) {
    if (root==NULL) {
        return 0;
    }
    int leftHeight = getTreeHeight(root->lchild) + 1;
    int rightHeight = getTreeHeight(root->rchild) + 1;
    return leftHeight > rightHeight ? leftHeight : rightHeight;
}

// 二叉树的层次遍历

void levelorder(BTNode *root) {
    if (root==NULL) {
        return;
    }
    BTNode *queue[maxsize];
    int front = 0;
    int rear = 0;
    rear = (rear + 1) % maxsize;
    queue[rear] = root;
    while (front != rear) {
        front = (front + 1) % maxsize;
        BTNode *node = queue[front];
        visit(node);
        if (node->lchild != NULL) {
            rear = (rear + 1) % maxsize;
            queue[rear] = node->lchild;
        }
        if (node->rchild != NULL) {
            rear = (rear + 1) % maxsize;
            queue[rear] = node->rchild;
        }
    }
    printf("\n");
}

int maxTreeWidth(BTNode *root) {
    if (root==NULL) {
        return 0;
    }
    Level queue[maxsize];
    int front = 0;
    int rear = 0;
    int maxLevel = 1;
    Level node = {root,maxLevel};
    queue[rear++] = node;
    while (front != rear) {
        Level lNode= queue[front++];
        BTNode *curBT = lNode.node;
        int curl = lNode.lno;
        if (curBT->lchild != NULL) {
            maxLevel = curl + 1;
            queue[rear].node = curBT->lchild;
            queue[rear].lno = curl + 1;
            rear++;
        }
        if (curBT->rchild != NULL) {
            maxLevel = curl + 1;
            queue[rear].node = curBT->rchild;
            queue[rear].lno = maxLevel;
            rear++;
        }
    }
    int res = 0;
    for (int i = 1; i <= maxLevel; i++) {
        int count = 0;
        for (int j = 0; j < rear; j++) {
            Level level = queue[j];
            if (level.lno == i) {
                count++;
            }
        }
        if (count > res) {
            res = count;
        }
    }
    return res;
}

// 二叉树的宽度

int main() {
    BTNode node1 = {'1',NULL,NULL};
    BTNode node2 = {'2',NULL,NULL};
    BTNode node3 = {'3',NULL,NULL};
    BTNode node4 = {'4',NULL,NULL};
    BTNode node5 = {'5',NULL,NULL};
    BTNode node6 = {'6',NULL,NULL};
    BTNode node7 = {'7',NULL,NULL};
    BTNode node8 = {'8',NULL,NULL};
    node1.lchild = &node2;
    node1.rchild = &node4;
    node2.lchild = &node3;
    node2.rchild = &node5;
    node4.lchild = &node6;
    node5.lchild = &node7;
    node5.rchild = &node8;
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
    char paths[maxsize];
    printAllPaths(&node1, paths, 0);
    int height = getTreeHeight(&node1);
    printf("binary tree height:%d\n",height);
    levelorder(&node1);
    maxTreeWidth(&node1);
    return 0;
}
