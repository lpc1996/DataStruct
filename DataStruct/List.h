#pragma once
#ifndef LIST_H
#define LIST_H

#include "DataStruct.h"

//顺序表节点设计
typedef struct _Table {
	int* head;//声明了一个名为head的长度不确定的数组，也叫“动态数组”
	int length;//记录当前顺序表的长度
	int size;//记录顺序表分配的存储容量
}Table;

//初始化顺序表 
extern Table InitTable();
//顺序输出顺序表元素
extern void printTable(Table t);
//向顺序表中添加数据
extern Table addTable(Table t, int index, int elem);
//根据元素位置从顺序表中删除数据 
extern Table deleteTableIndex(Table t, int index);
//从顺序表中查找元素，并返回该元素所在位置
extern int selectTable(Table t, int elem);
//根据元素值从顺序表中删除元素 
extern Table deleteTableElem(Table t, int elem);
//将指定位置的元素修改为指定值
extern Table amendTableIndex(Table t, int index, int elem);
//将指定元素修改为指定值
extern Table amendTableElem(Table t, int oldElem, int newElem);
//顺序表测试 
extern void TestTable();

//单链表节点设计
typedef struct _Link_Node {
	char elem;
	struct _Link_Node* next;
}linkNode;
//单链表数据结构封装 
typedef struct _Linked_List {
	linkNode* head;
	linkNode* last;
	int size;
}linkedList;
//初始化链表 
extern void InitLink(linkedList* list);
//向链表中添加数据
extern void addLink(linkedList* list, int index, char elem);
//把链表中的数据打印在屏幕上
extern void printList(linkedList* list);
//链表的基本操作测试
extern void TestList();
//释放链表空间
extern void freeList(linkedList* list);
//删除链表中指定位置的元素
extern void deleteListIndex(linkedList* list, int index);
//修改指定位置元素为指定值
extern void changeListIndex(linkedList* list, int index, char elem);
//查询数据在链表中的位置
extern int indexOf(linkedList* list, char elem);
//删除链表中指定元素
extern void deleteListElem(linkedList* list, char elem);
//修改制定元素为指定值
extern void changeListElem(linkedList* list, char oldElem, char newElem);

//单循环链表

//初始化单循环链表
extern void InitCircularLinkedList(linkedList* circularLinkedList);
//向单循环链表中添加数据
extern void addCircular(linkedList* circularList, int index, char elem);
//删除单循环链表中index位置的元素
extern void deleteCircular(linkedList* circularList, int index);
//删除单循环链表中值为elem的元素
extern void deleteCircular(linkedList* circularList, char elem);
//将单循环链表中index位置的元素修改为elem
extern void changeCircular(linkedList* circularList, int index, char elem);
//将单循环链表中值为oldElem的元素修改为newElem
extern void changeCircular(linkedList* circularList, char oldElem, char newElem);
//释放单循环链表所使用的的存储空间并删除单循环链表
extern void freeCircular(linkedList* circularList);
//单循环链表功能测试
extern void TestCircular();

//双向链表节点设计
typedef struct _TwoNode {
	struct _TwoNode* pre;
	char elem;
	struct _TwoNode* next;
}twoNode;

//双向链表数据结构封装
typedef struct _TwoLinkedList {
	twoNode* head;
	twoNode* last;
	int size;
}twoLinkedList;

//双向链表基本操作实现

//初始化双向链表
extern void InitTwoList(twoLinkedList* twoList);
//向双向链表中添加数据
extern void addTwoList(twoLinkedList* twoList, char elem);
//将双向链表中的数据打印在屏幕上
extern void printTwoList(twoLinkedList* twoList);
//删除双向链表中指定位置的元素节点
extern void deleteTwoList(twoLinkedList* twoList, int index);
//删除双向链表中指定值得元素节点
extern void deleteTwoList(twoLinkedList* twoList, char elem);
//把双向链表中index位置元素的值修改为elem
extern void changeTwoList(twoLinkedList* twoList, int index, char elem);
//把双向链表中值为oldElem的节点的值修改为newElem
extern void changeTwoList(twoLinkedList* twoList, char oldElem, char newElem);
//释放双向链表所占用的存储空间
extern void freeTwoList(twoLinkedList* twoList);
//从双向链表中查找元素elem的位置
extern int indexOfTwoList(twoLinkedList* twoList, char elem);
//双向链表功能测试
extern void TestTwoList();

//静态链表基本操作实现
//静态链表节点设计
typedef struct _Static_Node {
	int data;
	int next;
}staticNode;

//静态链表数据结构封装
typedef struct _Static_List {
	staticNode* node;
	int length;
	int size;
}staticList;

#endif