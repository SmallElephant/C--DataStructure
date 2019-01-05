//
//  main.cpp
//  5-tree
//
//  Created by FlyElephant on 2018/12/31.
//  Copyright © 2018年 FlyElephant. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

#define maxsize 10

typedef struct TBTNode {
    char data;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
    int ltag; // 0表示lchild指向是左孩子,1表示指向其前驱
    int rtag; // 0表示rchild指向是右孩子，1表示指向其后继
} TBTNode;

typedef struct BTNextNode {
    char data;
    struct BTNextNode *lchild;
    struct BTNextNode *rchild;
    struct BTNextNode *next;
} BTNextNode;

typedef struct TreeNode {
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

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

BTNextNode *getNextNode(BTNextNode *node) {
    if (node == NULL) {
        return NULL;
    }
    BTNextNode *cur = node;
    BTNextNode *p=NULL;
    if (cur->rchild != NULL) { // 右子树存在，找到右子树最左下的孩子结点
        p = cur->rchild;
        while (p->lchild != NULL) {
            p = p->lchild;
        }
    } else {
        p = cur;
        while (p->next != NULL) {
            if (p->next->lchild == p) { // 节点位置处于根节点的左侧
                return p->next;
            }
            p = p->next;
        }
    }
    return p;
}

bool doesTree1HasTree2(TreeNode *root1,TreeNode *root2) {
    if (root2==NULL) {
        return true;
    }
    if (root1==NULL) {
        return false;
    }
    if (root1->data != root2->data) {
        return false;
    }
    return doesTree1HasTree2(root1->lchild, root2->lchild) && doesTree1HasTree2(root1->rchild, root2->rchild);
}

// 树的子结构
bool isSubTree(TreeNode *root,TreeNode *subNode) {
    if (root == NULL || subNode == NULL) {
        return false;
    }
    bool res = false;
    if (root->data == subNode->data) {
        res = doesTree1HasTree2(root, subNode);
    }
    if (!res) {
        res = isSubTree(root->lchild, subNode);
    }
    if (!res) {
        res = isSubTree(root->rchild, subNode);
    }
    return res;
}

void swapTreeNode(TreeNode *node) {
    TreeNode *lchild = node->lchild;
    node->lchild = node->rchild;
    node->rchild = lchild;
}

// 二叉树的镜像
void mirrorTree(TreeNode *root) {
    if (root==NULL) {
        return;
    }
    swapTreeNode(root);
    mirrorTree(root->lchild);
    mirrorTree(root->rchild);
}

// 二叉树的先序非递归遍历
void preOrderNonRecursive(TreeNode *root) {
    TreeNode *stack[10];
    int arr[10];
    int i = 0;
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        TreeNode *cur = stack[top--];
        arr[i++] = cur->data;
        if (cur->rchild != NULL) {
            stack[++top] = cur->rchild;
        }
        if (cur->lchild != NULL) {
            stack[++top] = cur->lchild;
        }
    }
    for (int j = 0;j <= i; j++) {
        printf("%c ",arr[j]);
    }
    printf("\n");
}

// 二叉树的非递归中序遍历

void inOrderNonRecurison(TreeNode *root) {
    TreeNode *stack[10];
    int top = -1;
    int count = -1;
    char arr[10];
    TreeNode *p = root;
    while (top >= 0 || p != NULL) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->lchild;
        }
        if (top >= 0) {
            TreeNode *cur = stack[top--];
            arr[++count] = cur->data;
            p = cur->rchild;
        }
    }
    for (int i = 0; i <= count; i++) {
        printf("%c ",arr[i]);
    }
    printf("\n");
}

//二叉树的后序遍历
void postOrderNonRecursion(TreeNode *root) {
    if (root==NULL) {
        return;
    }
    int top1 = -1;
    int top2 = -1;
    TreeNode *stack1[10];
    TreeNode *stack2[10];
    TreeNode *p = root;
    stack1[++top1] = root;
    while (top1 >= 0) {
        p = stack1[top1--];
        stack2[++top2] = p;
        if (p->lchild != NULL) {
            stack1[++top1] = p->lchild;
        }
        if (p->rchild != NULL) {
            stack1[++top1] = p->rchild;
        }
    }
    for (int i = top2; i>= 0; i--) {
        TreeNode *node = stack2[top2--];
        printf("%c ",node->data);
    }
    printf("\n");
}

// 二叉树的层次遍历
void levelOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    TreeNode *p = root;
    TreeNode *queue[100];
    int queuesize = 10;
    char arr[100];
    char count = -1;
    int front = -1;
    int rear = -1;
    rear = (rear + 1) % queuesize;
    queue[rear] = p;
    while (front != rear) {
        front = (front + 1) % queuesize;
        p = queue[front];
        arr[++count] = p->data;
        if (p->lchild != NULL) {
            rear = (rear + 1) % queuesize;
            queue[rear] = p->lchild;
        }
        if (p->rchild != NULL) {
            rear = (rear + 1) % queuesize;
            queue[rear] = p->rchild;
        }
    }
    for (int i = 0; i <= count; i++) {
        printf("%c ",arr[i]);
    }
    printf("\n");
}

void levelOrder2(TreeNode *root) {
    if (root==NULL) {
        return;
    }
    queue<TreeNode *> inQueue;
    inQueue.push(root);
    queue<TreeNode *> outQueue;
    while (!inQueue.empty()) {
        TreeNode *top = inQueue.front();
        outQueue.push(top);
        inQueue.pop();
        if (top->lchild != NULL) {
            inQueue.push(top->lchild);
        }
        if (top->rchild != NULL) {
            inQueue.push(top->rchild);
        }
    }
    while (outQueue.size()) {
        TreeNode *top = outQueue.front();
        printf("%c ",top->data);
        outQueue.pop();
    }
    printf("\n");
}


void testNexNode() {
    BTNextNode n1 = {'1',NULL,NULL};
    BTNextNode n2 = {'2',NULL,NULL};
    BTNextNode n3 = {'3',NULL,NULL};
    BTNextNode n4 = {'4',NULL,NULL};
    BTNextNode n5 = {'5',NULL,NULL};
    BTNextNode n6 = {'6',NULL,NULL};
    n1.lchild = &n2;
    n1.rchild = &n4;
    n2.lchild = &n3;
    n2.rchild = &n5;
    n4.lchild = &n6;
    n3.next = &n2;
    n5.next = &n2;
    n2.next = &n1;
    n6.next = &n4;
    n4.next = &n1;
    BTNextNode *next = getNextNode(&n5);
    printf("next value:%c\n",next->data);
}

void testSubTree() {
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
    TreeNode s1 = {'4',NULL,NULL};
    TreeNode s2 = {'6',NULL,NULL};
    s1.lchild = &s2;
    bool isSub = isSubTree(&t1, &s1);
    if (isSub) {
        printf("is sub stree\n");
    } else {
        printf("is not sub tree\n");
    }
}

void testMirrorTree() {
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
    mirrorTree(&t1);
    printf("left:%c---right:%c\n",t1.lchild->data,t1.rchild->data);
}

void testOrderNonRecursion() {
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
    preOrderNonRecursive(&t1);
    inOrderNonRecurison(&t1);
    postOrderNonRecursion(&t1);
    levelOrder(&t1);
    levelOrder2(&t1);
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
    // 二叉树的中序线索化及打印
//    createThread(&node1);
//    inOrderThread(&node1);
//    printf("\n");
    testSubTree();
    testMirrorTree();
    testOrderNonRecursion();
    return 0;
}
