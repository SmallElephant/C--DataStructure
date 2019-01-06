//
//  ConvertTree.cpp
//  5-tree
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "Common.hpp"

class ConvertTree {
    
public:
    TreeNode *convert(TreeNode *root) {
        TreeNode *p = root;
        int top = -1;
        TreeNode *stack[100];
        TreeNode *pre=NULL;
        TreeNode *head=NULL;
        while (top >= 0 || p != NULL) {
            while (p != NULL) {
                stack[++top] = p;
                p = p->lchild;
            }
            if (top >= 0) {
                TreeNode *cur = stack[top--];
                printf("%c ",cur->data);
                if (pre != NULL) {
                    pre->rchild = cur;
                    cur->lchild = pre;
                } else {
                    head = cur;
                }
                pre = cur;
                p = cur->rchild;
            }
        }
        printf("\n");
        return head;
    }
    
    void test() {
        TreeNode t1 = {'5',NULL,NULL};
        TreeNode t2 = {'3',NULL,NULL};
        TreeNode t3 = {'8',NULL,NULL};
        TreeNode t4 = {'2',NULL,NULL};
        TreeNode t5 = {'4',NULL,NULL};
        TreeNode t6 = {'7',NULL,NULL};
        TreeNode t7 = {'9',NULL,NULL};
        t1.lchild = &t2;
        t1.rchild = &t3;
        t2.lchild = &t4;
        t2.rchild = &t5;
        t3.lchild = &t6;
        t3.rchild = &t7;
        TreeNode *root = convert(&t1);
        while (root != NULL) {
            printf("%c ",root->data);
            root = root->rchild;
        }
        printf("\n");
    }
};
