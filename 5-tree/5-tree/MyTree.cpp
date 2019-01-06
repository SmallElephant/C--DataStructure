//
//  MyTree.cpp
//  5-tree
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include "CommonStruct.cpp"
using namespace std;

class Symmetric {
public:
    bool isSymmetric(TreeNode *root) {
        if (root==NULL) {
            return true;
        }
        return commonRoot(root->lchild, root->rchild);
    }
    
    bool commonRoot(TreeNode *root1,TreeNode *root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1 == NULL || root2 == NULL) {
            return false;
        }
        if (root1->data != root2->data) {
            return false;
        }
        bool isLeftSymmetric = commonRoot(root1->lchild, root2->rchild);
        bool isRightSymmetric = commonRoot(root1->rchild, root2->lchild);
        return isLeftSymmetric && isRightSymmetric;
    }
    
    void test() {
        TreeNode t1 = {'1',NULL,NULL};
        TreeNode t2 = {'2',NULL,NULL};
        TreeNode t3 = {'2',NULL,NULL};
        TreeNode t4 = {'3',NULL,NULL};
        TreeNode t5 = {'5',NULL,NULL};
        TreeNode t6 = {'5',NULL,NULL};
        TreeNode t7 = {'3',NULL,NULL};
        t1.lchild = &t2;
        t1.rchild = &t3;
        
        t2.lchild = &t4;
        t2.rchild = &t5;
        
        t3.lchild = &t6;
        t3.rchild = &t7;
        bool res= isSymmetric(&t1);
        if (res) {
            printf("is symmertic tree\n");
        } else {
            printf("is not symmertic tree\n");
        }
    }
};
