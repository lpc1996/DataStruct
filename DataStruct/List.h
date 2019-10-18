#pragma once
#ifndef LIST_H
#define LIST_H

#include "DataStruct.h"

//˳���ڵ����
typedef struct _Table {
	int* head;//������һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
	int length;//��¼��ǰ˳���ĳ���
	int size;//��¼˳������Ĵ洢����
}Table;

//��ʼ��˳��� 
extern Table InitTable();
//˳�����˳���Ԫ��
extern void printTable(Table t);
//��˳������������
extern Table addTable(Table t, int index, int elem);
//����Ԫ��λ�ô�˳�����ɾ������ 
extern Table deleteTableIndex(Table t, int index);
//��˳����в���Ԫ�أ������ظ�Ԫ������λ��
extern int selectTable(Table t, int elem);
//����Ԫ��ֵ��˳�����ɾ��Ԫ�� 
extern Table deleteTableElem(Table t, int elem);
//��ָ��λ�õ�Ԫ���޸�Ϊָ��ֵ
extern Table amendTableIndex(Table t, int index, int elem);
//��ָ��Ԫ���޸�Ϊָ��ֵ
extern Table amendTableElem(Table t, int oldElem, int newElem);
//˳������ 
extern void TestTable();

//������ڵ����
typedef struct _Link_Node {
	char elem;
	struct _Link_Node* next;
}linkNode;
//���������ݽṹ��װ 
typedef struct _Linked_List {
	linkNode* head;
	linkNode* last;
	int size;
}linkedList;
//��ʼ������ 
extern void InitLink(linkedList* list);
//���������������
extern void addLink(linkedList* list, int index, char elem);
//�������е����ݴ�ӡ����Ļ��
extern void printList(linkedList* list);
//����Ļ�����������
extern void TestList();
//�ͷ�����ռ�
extern void freeList(linkedList* list);
//ɾ��������ָ��λ�õ�Ԫ��
extern void deleteListIndex(linkedList* list, int index);
//�޸�ָ��λ��Ԫ��Ϊָ��ֵ
extern void changeListIndex(linkedList* list, int index, char elem);
//��ѯ�����������е�λ��
extern int indexOf(linkedList* list, char elem);
//ɾ��������ָ��Ԫ��
extern void deleteListElem(linkedList* list, char elem);
//�޸��ƶ�Ԫ��Ϊָ��ֵ
extern void changeListElem(linkedList* list, char oldElem, char newElem);

//��ѭ������
extern void InitCircularLinkedList(linkedList* circularLinkedList);
extern void addCircular(linkedList* circularList, int index, char elem);
extern void TestCircular();
#endif