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
    int top = 0;
    int target = 11;
    void printPath(TreeNode *root) {
        char paths[10];
        printTreePath(root, paths);
    }
    
    void printTreePath(TreeNode *root,char paths[]) {
        if (root == NULL) {
            return;
        }
        paths[top++] = root->data;
        if (root->lchild == NULL && root->rchild == NULL) {
            print(paths);
        } else {
            printTreePath(root->lchild, paths);
            printTreePath(root->rchild, paths);
        }
        top--;
    }
    
    void print(char paths[]) {
        int sum = 0;
        for (int i = 0; i < top; i++) {
            sum += paths[i] - '0';
        }
        if (sum == target) {
            for (int i = 0; i < top; i++) {
                 printf("%c ",paths[i]);
            }
            printf("\n");
        }
    }
    
    void test() {
        TreeNode t1 = {'1',NULL,NULL};
        TreeNode t2 = {'2',NULL,NULL};
        TreeNode t3 = {'3',NULL,NULL};
        TreeNode t4 = {'4',NULL,NULL};
        TreeNode t5 = {'8',NULL,NULL};
        TreeNode t6 = {'6',NULL,NULL};
        t1.lchild = &t2;
        t1.rchild = &t4;
        t2.lchild = &t3;
        t2.rchild = &t5;
        t4.lchild = &t6;
        printPath(&t1);
    }
};
