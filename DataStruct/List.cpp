#include "List.h"

#define Size 5 //��Size���к궨�壬��ʾ˳�������ռ��С 

//˳���Ļ������� 
Table InitTable() {
	Table t;
	t.head = (int*)malloc(Size * sizeof(int));//����һ���յ�˳�����̬����洢�ռ� 
	if (!t.head) {//�������ʧ�ܣ�˳����ȸ�ֵ-1 
		t.length = -1;
		t.size = 0;
	}
	else {
		t.length = 0;
		t.size = Size;
	}
	return t;
}

Table addTable(Table t, int index, int elem) {
	/*
		�жϲ��뱾���Ƿ�������⣨�������Ԫ��λ�ñ����ű�ĳ��Ȼ��������ȣ���β����������
	���߲����λ�ñ������ڣ�������Ϊ��ʾ���Զ��˳���
	*/
	if (index<0 || index>t.length) {
		printf("���棺����λ�÷Ƿ���");
		return t;
	}
	//�ж�˳����Ƿ��ж���Ĵ洢�ռ��ṩ���µ�Ԫ�أ�����������������µĿռ� 
	if (t.length == t.size) {
		t.head = (int*)realloc(t.head, (t.size + Size) * sizeof(int));
		if (!t.head) {
			printf("�洢�ռ����ʧ�ܣ�");
			return t;
		}
		t.size = t.size + Size;
	}
	//�����������Ҫ��Ҫ�����λ�ÿ�ʼ�������������Ԫ�غ���
	int i = t.length;
	for (; i > index; i--) {
		t.head[i] = t.head[i - 1];
	}
	t.head[index] = elem;
	t.length++;
	return t;
}

Table deleteTableIndex(Table t, int index) {
	//ɾ��ǰ�жϴ����λ���ǲ��ǺϷ��ģ�������Ǿ��˳����� 
	if (index < 0 || index >= t.length) {
		printf("Ҫɾ����λ�÷Ƿ���");
		return t;
	}
	int i = 0;
	for (i = index; i < t.length - 1; i++) {
		t.head[i] = t.head[i + 1];
	}
	t.length--;
	return t;
}

Table deleteTableElem(Table t, int elem) {
	int index = selectTable(t, elem);
	int i = 0;
	for (i = index; i < t.length; i++) {
		t.head[i] = t.head[i + 1];
	}
	t.length--;
	return t;
}

int selectTable(Table t, int elem) {
	int index = -1, i = 0;
	//ʹ��˳�����
	for (; i < t.length; i++) {
		if (t.head[i] == elem) {
			index = i;
			break;
		}
	}
	return index;
}

Table amendTableIndex(Table t, int index, int elem) {
	//�޸�ǰ�ж�Ҫ�޸ĵ�Ԫ��λ���Ƿ�Ƿ� 
	if (index < 0 || index >= t.length) {
		printf("Ҫ�޸ĵ�λ�÷Ƿ���");
		return t;
	}
	t.head[index] = elem;
	return t;
}

Table amendTableElem(Table t, int oldElem, int newElem) {
	int index = selectTable(t, oldElem);
	if (index == -1) {
		printf("%d���ڱ���", oldElem);
		return t;
	}
	t.head[index] = newElem;
	return t;
}

void printTable(Table t) {
	int i = 0;
	for (; i < t.length; i++) {
		printf("%d ", t.head[i]);
	}
	printf("\n");
}

void TestTable() {
	Table t1 = InitTable();
	int i = 0;
	for (; i < Size; i++) {
		t1.head[i] = i;
		t1.length++;
	}
	printf("ԭ˳���\n");
	printTable(t1);

	printf("ɾ��Ԫ��1:\n");
	t1 = deleteTableIndex(t1, 1);
	printTable(t1);

	printf("�ڵ�2��λ�ò���Ԫ��5:\n");
	t1 = addTable(t1, 2, 5);
	printTable(t1);

	printf("����Ԫ��3��λ��:\n");
	int add = selectTable(t1, 3);
	printf("%d\n", add);

	printf("��Ԫ��3��Ϊ6:\n");
	t1 = amendTableElem(t1, 3, 6);
	printTable(t1);
}

//����Ļ������� 
void InitLink(linkedList* list) {
	list->head = NULL;
	list->last = NULL;
	list->size = 0;
}
//��������������� 
void addLink(linkedList* list, int index, char elem) {
	if (index<0 || index>index) {
		printf("Ҫ������ݵ�λ�÷Ƿ�");
		return;
	}
	linkNode* link = (linkNode*)malloc(sizeof(linkNode));
	link->elem = elem;
	link->next = NULL;
	if (index == 0) {
		list->head = link;
		list->last = link;
	}
	else if (index == list->size) {
		list->last->next = link;
		list->last = link;
	}
	else {
		linkNode* h = list->head;
		int i = 0;
		while (i < list->size) {
			if (i == index) {
				link->next = h->next;
				h->next = link;
			}
			h = h->next;
			i++;
		}
	}
	list->size++;
}

void printList(linkedList* list) {
	printf("\n������Ϊ��%d\n", list->size);
	linkNode* h = list->head;
	int i = 0;
	while (i < list->size) {
		printf("%c ", h->elem);
		h = h->next;
		i++;
	}
	printf("\n");
}

void deleteListIndex(linkedList* list, int index) {
	if (index < 0 || index >= list->size) {
		printf("Ҫɾ����λ�ò��Ϸ�");
		return;
	}
	linkNode* h = list->head;
	if (index == 0) {
		list->head = list->head->next;
		free(h);
	}
	else if (index < list->size) {
		linkNode* pre = NULL;
		linkNode* next = h->next;
		int i = 0;
		while (h != NULL) {
			if (i == index) {
				linkNode* p = h;
				pre->next = next;
				free(p);
				list->size--;
				if (index == list->size - 1) {
					list->last = pre;
				}
				break;
			}
			pre = h;
			h = h->next;
			next = h->next;
			i++;
		}
	}
}

void deleteListElem(linkedList* list, char elem) {
	linkNode* h = list->head;
	linkNode* pre = NULL;
	linkNode* next = h->next;
	linkNode* p = NULL;
	while (h != NULL) {
		if (h->elem == elem) {
			if (h == list->head) {
				p = h;
				list->head = h->next;
			}
			else if (h->next == NULL) {
				pre->next = NULL;
				list->last = pre;
				p = h;
			}
			else {
				p = h;
				pre->next = next;
			}
			free(p);
			list->size--;
			break;
		}
		pre = h;
		h = h->next;
		if (h != NULL) {
			next = h->next;
		}
	}
	if (h == NULL) {
		printf("Ԫ��\'%c\'���������У�", elem);
	}
}

void changeListIndex(linkedList* list, int index, char elem) {
	if (index<0 || index>list->size - 1) {
		printf("Ҫ�޸ĵ�λ�ò��Ϸ���");
		return;
	}
	linkNode* h = list->head;
	int i = 0;
	while (h != NULL || h != list->head) {
		if (i == index) {
			h->elem = elem;
			break;
		}
		h = h->next;
		i++;
	}
}

void changeListElem(linkedList* list, char oldElem, char newElem) {
	linkNode* h = list->head;
	while (h != NULL || h != list->head) {
		if (h->elem == oldElem) {
			h->elem = newElem;
			break;
		}
		h = h->next;
	}
	if (h == NULL || h == list->head) {
		printf("Ԫ��%c���������У�", oldElem);
	}
}

int indexOf(linkedList* list, char elem) {
	int i = 0, index = -1;
	linkNode* h = list->head;
	for (; h != NULL || h != list->head ; h = h->next) {
		if (h->elem == elem) {
			index = i;
			break;
		}
		i++;
	}
	return index;
}

void freeList(linkedList* list) {
	linkNode* h = list->head;
	linkNode* p = NULL;
	while (h != NULL) {
		p = h;
		h = h->next;
		free(p);
	}
	list->head = NULL;
	list->last = NULL;
	list->size = 0;
}

void TestList() {
	linkedList list;
	InitLink(&list);
	//��������������� 
	int i = 0;
	for (; i < 6; i++) {
		addLink(&list, i, 'a' + i);
	}
	printList(&list);
	printf("ɾ�������еĵ�5��Ԫ��\n");
	deleteListIndex(&list, 4);
	printList(&list);
	printf("ɾ�������е� \'o\'\n");
	deleteListElem(&list, 'o');
	printList(&list);
	printf("�޸������е�4��Ԫ��Ϊ��\'l\'\n");
	changeListIndex(&list, 3, 'l');
	printList(&list);
	printf("���� \'l\' �������е�λ�ã�%d\n", indexOf(&list, 'l'));
	printf("�޸�Ԫ��\'a\'ΪA\n");
	changeListElem(&list, 'a', 'A');
	printList(&list);
	printf("�޸�Ԫ��\'c\'ΪC\n");
	changeListElem(&list, 'c', 'C');
	printList(&list);
	printf("�޸�Ԫ��\'f\'ΪF\n");
	changeListElem(&list, 'f', 'F');
	printList(&list);
	freeList(&list);
}

//��ʼ����ѭ������
void InitCircularLinkedList(linkedList* circularLinkedList) {
	circularLinkedList->head = NULL;
	circularLinkedList->last = NULL;
	circularLinkedList->size = 0;
}

//��ѭ���������������
void addCircular(linkedList* circularList, int index, char elem) {
	addLink(circularList, index, elem);
	circularList->last->next = circularList->head;
}

void deleteCircular(linkedList* circularList, int index) {
	deleteListIndex(circularList, index);
	if (index == 0 || index == circularList->size) {
		circularList->last->next = circularList->head;
	}
}

void deleteCircular(linkedList* circularList, char elem) {
	deleteListElem(circularList, elem);
	circularList->last->next = circularList->head;
}

void changeCircular(linkedList* circularList, int index, char elem) {
	changeListIndex(circularList, index, elem);
}

void changeCircular(linkedList* circularList, char oldElem, char newElem) {
	changeListElem(circularList, oldElem, newElem);
}

void freeCircular(linkedList* circularList) {
	circularList->last->next = NULL;
	freeList(circularList);
}

//��ѭ�������ܲ���
void TestCircular() {
	cout << "\n��ѭ�������ܲ���" << endl;
	linkedList circularList;
	InitCircularLinkedList(&circularList);
	char x = 'a';
	cout << "��ѭ����������ӡ�a-z��10��Сд��ĸ" << endl;
	for (int i = 0; i < 10; i++) {
		addCircular(&circularList, i, x);
		x += 1;
	}
	printList(&circularList);
	cout << "ɾ����ѭ����������ĸ��f��" << endl;
	deleteCircular(&circularList, 'f');
	printList(&circularList);
	cout << "ɾ����ѭ�������е�5��Ԫ��" << endl;
	deleteCircular(&circularList, 4);
	printList(&circularList);
	cout << "�޸ĵ�ѭ�������С�c��Ϊ��C��" << endl;
	changeCircular(&circularList, 'c', 'C');
	printList(&circularList);
	cout << "�޸ĵ�ѭ�������е�4��Ԫ��Ϊ��M��" << endl;
	changeCircular(&circularList, 3, 'M');
	printList(&circularList);
	cout << "�ͷŵ�ѭ������ռ䣬��ɾ����ѭ������" << endl;
	freeCircular(&circularList);
	printList(&circularList);
}

//˫�������������ʵ��

//˫�������ʼ��
void InitTwoList(twoLinkedList* twoList) {
	twoList->head = NULL;
	twoList->last = NULL;
	twoList->size = 0;
}

//��˫���������������
void addTwoList(twoLinkedList* twoList,char elem) {
	twoNode* p = (twoNode*)malloc(sizeof(twoNode));
	p->elem = elem;
	p->pre = NULL;
	p->next = NULL;
	if (twoList->head == NULL) {
		twoList->head = p;
	}
	else {
		p->pre = twoList->last;
		twoList->last->next = p;
	}
	twoList->last = p;
	twoList->size++;
}

//ɾ��˫��������ָ��λ�õĽڵ�ɾ��
void deleteTwoList(twoLinkedList* twoList,int index) {
	twoNode* p = NULL;
	if (index == 0) {
		p = twoList->head;
		twoList->head = p->next;
		twoList->head->pre = NULL;
	}
	else if (index == twoList->size - 1) {
		p = twoList->last;
		twoList->last = twoList->last->pre;
		twoList->last = NULL;
	}
	else if(index < 0 || index >= twoList->size ){
		cout << "Ҫɾ����λ�ò��Ϸ����������룡" << endl;
		return;
	}
	else {
		twoNode* h = twoList->head;
		for (int i = 1; i < twoList->size-1; i++) {
			if (index == i) {
				p = h;
				//twoNode* pre = h->pre
				h->pre->next = h->next;
			}
			h = h->next;
		}
	}
	free(p);
	twoList->size--;
}

//ɾ��˫��������ָ��ֵ��Ԫ��
void deleteTwoList(twoLinkedList* twoList, char elem) {
	twoNode* h = twoList->head;
	twoNode* p;
	while (h) {
		if (h->elem == elem) {
			p = h;
			if (h == twoList->head) {
				twoList->head = h->next;
				twoList->head->pre = NULL;
			}
			else {
				h->pre->next = h->next;
			}
			free(p);
			twoList->size--;
			break;
		}
		h = h->next;
	}
}

//��˫��������indexλ��Ԫ�ص�ֵ�޸�Ϊelem
void changeTwoList(twoLinkedList* twoList, int index, char elem) {
	if (index < 0 || index >= twoList->size) {
		cout << "Ҫ�޸ĵ�λ�ò��Ϸ����������룡" << endl;
		return;
	}
	else {
		twoNode* h = twoList->head;
		for (int i = 0; i < twoList->size; i++) {
			if (index == i) {
				h->elem = elem;
				break;
			}
			h = h->next;
		}
	}
}

//��˫��������ֵΪoldElem�Ľڵ��ֵ�޸�ΪnewElem
void changeTwoList(twoLinkedList* twoList, char oldElem, char newElem) {
	twoNode* h = twoList->head;
	int index = indexOfTwoList(twoList, oldElem);
	if (index == -1) {
		cout << "��������û���ҵ�ֵΪ��" << oldElem << "��Ԫ�ؽڵ�" << endl;
	}
	else {
		changeTwoList(twoList, index, newElem);
	}
}

//��˫�������в���Ԫ��elem��λ��
int indexOfTwoList(twoLinkedList* twoList, char elem) {
	int index = -1;
	twoNode* h = twoList->head;
	for (int i = 0; i < twoList->size; i++) {
		if (h->elem == elem) {
			index = i;
			break;
		}
		h = h->next;
	}
	return index;
}

//��ӡ˫�������е�Ԫ�ص���Ļ��
void printTwoList(twoLinkedList* twoList) {
	twoNode* h = twoList->head;
	cout << "˫����������" << twoList->size << "��Ԫ��" << endl;
	while (h != NULL) {
		cout << h->elem << " ";
		h = h->next;
	}
	cout << endl;
}

//�ͷ�˫��������ռ�õĴ洢�ռ�
void freeTwoList(twoLinkedList* twoList) {
	twoNode* h = twoList->head;
	twoNode* pre;
	while (h) {
		pre = h;
		h = h->next;
		free(pre);
	}
	twoList->head = NULL;
	twoList->last = NULL;
	twoList->size = 0;
}
void TestTwoList() {
	cout << "\n˫���������" << endl;
	twoLinkedList twoList;
	InitTwoList(&twoList);
	cout << "��˫�����������10����ĸ" << endl;
	char x = 'a';
	for (int i = 0; i < 10; i++) {
		addTwoList(&twoList, x);
		x += 1;
	}
	printTwoList(&twoList);
	cout << "ɾ��˫�������е�5��Ԫ��" << endl;
	deleteTwoList(&twoList, 4);
	printTwoList(&twoList);
	cout << "ɾ��˫�������С�f��Ԫ��" << endl;
	deleteTwoList(&twoList, 'f');
	printTwoList(&twoList);
	cout << "��˫�������е�5��Ԫ���޸�ΪM" << endl;
	changeTwoList(&twoList, 4, 'M');
	printTwoList(&twoList);
	cout << "��˫��������ֵΪ'c'�Ľڵ�ֵ�޸�Ϊ��C'" << endl;
	changeTwoList(&twoList, 'c', 'C');
	printTwoList(&twoList);
	cout << "�ͷ�˫��������ռ�õĴ洢�ռ�" << endl;
	freeTwoList(&twoList);
	printTwoList(&twoList);
}