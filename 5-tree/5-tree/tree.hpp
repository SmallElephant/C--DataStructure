//
//  tree.hpp
//  5-tree
//
//  Created by FlyElephant on 2019/1/1.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>

#endif /* tree_hpp */

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


