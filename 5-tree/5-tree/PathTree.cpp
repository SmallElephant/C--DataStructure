//
//  PathTree.cpp
//  5-tree
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include "Common.hpp"
using namespace std;

class PathTree {
    
public:
    
    void printPath(TreeNode *root) {
        int stack[10];
        printTreePath(root, stack, 0);
    }
    
    void printTreePath(TreeNode *root,int *stack, int len) {
        if (root == NULL) {
            return;
        }
        *(stack+len) = root->data;
        len++;
        if (root->lchild == NULL && root->rchild == NULL) {
            printStack(stack, len);
            len--;
        } else {
            printTreePath(root->lchild, stack, len);
            printTreePath(root->rchild, stack, len);
        }
    }
    
    void printStack(int *stack,int len) {
        for (int i = 0; i < len; i++) {
            printf("%c ",*(stack+i));
        }
        printf("\n");
    }
    
    void test() {
        TreeNode t1 = {'1',NULL,NULL};
        TreeNode t2 = {'2',NULL,NULL};
        TreeNode t3 = {'3',NULL,NULL};
        TreeNode t4 = {'4',NULL,NULL};
        TreeNode t5 = {'5',NULL,NULL};
        TreeNode t6 = {'6',NULL,NULL};
        t1.lchild = &t2;
        t1.rchild = &t4;
        t2.lchild = &t3;
        t2.rchild = &t5;
        t4.lchild = &t6;
        printPath(&t1);
    }
};
