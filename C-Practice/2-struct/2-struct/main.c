//
//  main.c
//  2-struct
//
//  Created by FlyElephant on 2019/1/6.
//  Copyright © 2019年 FlyElephant. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    char data;
    struct ListNode *next;
} ListNode;

int main(int argc, const char * argv[]) {
    printf("malloc test 1:\n");
    for (int i = 0; i < 10; i++) {
        ListNode node = {'A',NULL};
        printf("%p\n",&node);
    }
    printf("malloc test 2:\n");
    for (int i = 0; i < 10; i++) {
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->data = 'A';
        printf("%p\n",node);
    }
    return 0;
}
