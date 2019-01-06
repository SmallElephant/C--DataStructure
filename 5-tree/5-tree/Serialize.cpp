//
//  Serialize.cpp
//  5-tree
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <string>
#include "Common.hpp"
using namespace std;

class Serialize {
public:
    string str;
    void serialize(TreeNode *root) {
        if (root == NULL) {
            str += "$,";
            return;
        }
        str += root->data;
        str += ",";
        serialize(root->lchild);
        serialize(root->rchild);
    }
    int index = 0;
    TreeNode *deserialize(char *p) {
        char cur = *(p+index);
        if (cur == '$') {
            return NULL;
        }
        TreeNode *root = new TreeNode();
        root->data = cur;
        index++;
        root->lchild = deserialize(p);
        index++;
        root->rchild = deserialize(p);
        return root;
    }
    
    void test() {
        TreeNode t1 = {'1',NULL,NULL};
        TreeNode t2 = {'2',NULL,NULL};
        TreeNode t3 = {'3',NULL,NULL};
        TreeNode t4 = {'4',NULL,NULL};
        TreeNode t5 = {'5',NULL,NULL};
        TreeNode t6 = {'6',NULL,NULL};
        t1.lchild = &t2;
        t1.rchild = &t3;
        t2.lchild = &t4;
        t3.lchild = &t5;
        t3.rchild = &t6;
        serialize(&t1);
        cout<<str<<endl;
        
        char *desc = (char *)malloc(sizeof(char) * str.size());
        int len = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != ',') {
                *(desc+len) = str[i];
                len++;
            }
        }
        TreeNode *root = deserialize(desc);
        printf("%c\n",root->data);
    }
};
