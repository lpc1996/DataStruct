#pragma once
#ifndef STACK_H
#define STACK_H

#include "DataStruct.h"
//ջ�Ͷ��л���������C����ʵ��
 
typedef struct _STACK_NODE {
    int data;
    struct _STASK_NODE* next;
}stack_node;

#endif // !STACK_H
