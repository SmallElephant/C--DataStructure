//
//  BinarySearch.cpp
//  5-tree
//
//  Created by FlyElephant on 2019/1/12.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include "Common.hpp"

class BinarySearch {
public:
    
    //  二叉树的搜索树的
    char findNumber(TreeNode *root,int k) {
        TreeNode *p = root;
        TreeNode *stack[100];
        int arr[100];
        int i = 0;
        int top = -1;
        while (top >= 0 || p != NULL) {
            while (p != NULL) {
                stack[++top] = p;
                p = p->lchild;
            }
            if (top  >= 0) {
                TreeNode *cur = stack[top--];// 取栈顶元素
                arr[i++] = cur->data;
                p = cur->rchild; // 右孩子如果有值，直接推入栈中
            }
        }
        return arr[k-1];
    }
    
    void test() {
        TreeNode node1 = {'5',NULL};
        TreeNode node2 = {'3',NULL};
        TreeNode node3 = {'7',NULL};
        TreeNode node4 = {'2',NULL};
        TreeNode node5 = {'4',NULL};
        TreeNode node6 = {'6',NULL};
        TreeNode node7 = {'8',NULL};
        node1.lchild = &node2;
        node1.rchild = &node3;
        node2.lchild = &node4;
        node2.rchild = &node5;
        node3.lchild = &node6;
        node3.rchild = &node7;
        int k = 4;
        char res = findNumber(&node1, k);
        printf("二叉搜索树的第%d大结点:%c\n",k,res);
    }
};
