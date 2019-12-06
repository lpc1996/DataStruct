#pragma once
#ifndef STACK_H
#define STACK_H

#include "DataStruct.h"
//栈和队列基本操作的C语言实现
 
typedef struct _STACK_NODE {
    int data;
    struct _STASK_NODE* next;
}stack_node;

#endif // !STACK_H
