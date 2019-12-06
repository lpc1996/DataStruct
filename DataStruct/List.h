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

//��ʼ����ѭ������
extern void InitCircularLinkedList(linkedList* circularLinkedList);
//��ѭ���������������
extern void addCircular(linkedList* circularList, int index, char elem);
//ɾ����ѭ��������indexλ�õ�Ԫ��
extern void deleteCircular(linkedList* circularList, int index);
//ɾ����ѭ��������ֵΪelem��Ԫ��
extern void deleteCircular(linkedList* circularList, char elem);
//����ѭ��������indexλ�õ�Ԫ���޸�Ϊelem
extern void changeCircular(linkedList* circularList, int index, char elem);
//����ѭ��������ֵΪoldElem��Ԫ���޸�ΪnewElem
extern void changeCircular(linkedList* circularList, char oldElem, char newElem);
//�ͷŵ�ѭ��������ʹ�õĵĴ洢�ռ䲢ɾ����ѭ������
extern void freeCircular(linkedList* circularList);
//��ѭ�������ܲ���
extern void TestCircular();

//˫������ڵ����
typedef struct _TwoNode {
	struct _TwoNode* pre;
	char elem;
	struct _TwoNode* next;
}twoNode;

//˫���������ݽṹ��װ
typedef struct _TwoLinkedList {
	twoNode* head;
	twoNode* last;
	int size;
}twoLinkedList;

//˫�������������ʵ��

//��ʼ��˫������
extern void InitTwoList(twoLinkedList* twoList);
//��˫���������������
extern void addTwoList(twoLinkedList* twoList, char elem);
//��˫�������е����ݴ�ӡ����Ļ��
extern void printTwoList(twoLinkedList* twoList);
//ɾ��˫��������ָ��λ�õ�Ԫ�ؽڵ�
extern void deleteTwoList(twoLinkedList* twoList, int index);
//ɾ��˫��������ָ��ֵ��Ԫ�ؽڵ�
extern void deleteTwoList(twoLinkedList* twoList, char elem);
//��˫��������indexλ��Ԫ�ص�ֵ�޸�Ϊelem
extern void changeTwoList(twoLinkedList* twoList, int index, char elem);
//��˫��������ֵΪoldElem�Ľڵ��ֵ�޸�ΪnewElem
extern void changeTwoList(twoLinkedList* twoList, char oldElem, char newElem);
//�ͷ�˫��������ռ�õĴ洢�ռ�
extern void freeTwoList(twoLinkedList* twoList);
//��˫�������в���Ԫ��elem��λ��
extern int indexOfTwoList(twoLinkedList* twoList, char elem);
//˫�������ܲ���
extern void TestTwoList();

//��̬�����������ʵ��
//��̬����ڵ����
typedef struct _Static_Node {
	int data;
	int next;
}staticNode;

//��̬�������ݽṹ��װ
typedef struct _Static_List {
	staticNode* node;
	int length;
	int size;
}staticList;

#endif