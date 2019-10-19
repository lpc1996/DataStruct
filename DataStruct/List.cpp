#include "List.h"

#define Size 5 //对Size进行宏定义，表示顺序表申请空间大小 

//顺序表的基本操作 
Table InitTable() {
	Table t;
	t.head = (int*)malloc(Size * sizeof(int));//构造一个空的顺序表，动态申请存储空间 
	if (!t.head) {//如果申请失败，顺序表长度赋值-1 
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
		判断插入本身是否存在问题（如果插入元素位置比整张表的长度还大（如果相等，是尾随的情况），
	或者插入的位置本身不存在，程序作为提示并自动退出）
	*/
	if (index<0 || index>t.length) {
		printf("警告：插入位置非法！");
		return t;
	}
	//判断顺序表是否有多余的存储空间提供给新的元素，如果不够，则申请新的空间 
	if (t.length == t.size) {
		t.head = (int*)realloc(t.head, (t.size + Size) * sizeof(int));
		if (!t.head) {
			printf("存储空间分配失败！");
			return t;
		}
		t.size = t.size + Size;
	}
	//插入操作，需要从要插入的位置开始，将后面的所有元素后移
	int i = t.length;
	for (; i > index; i--) {
		t.head[i] = t.head[i - 1];
	}
	t.head[index] = elem;
	t.length++;
	return t;
}

Table deleteTableIndex(Table t, int index) {
	//删除前判断传入的位置是不是合法的，如果不是就退出函数 
	if (index < 0 || index >= t.length) {
		printf("要删除的位置非法！");
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
	//使用顺序查找
	for (; i < t.length; i++) {
		if (t.head[i] == elem) {
			index = i;
			break;
		}
	}
	return index;
}

Table amendTableIndex(Table t, int index, int elem) {
	//修改前判断要修改的元素位置是否非法 
	if (index < 0 || index >= t.length) {
		printf("要修改的位置非法！");
		return t;
	}
	t.head[index] = elem;
	return t;
}

Table amendTableElem(Table t, int oldElem, int newElem) {
	int index = selectTable(t, oldElem);
	if (index == -1) {
		printf("%d不在表中", oldElem);
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
	printf("原顺序表：\n");
	printTable(t1);

	printf("删除元素1:\n");
	t1 = deleteTableIndex(t1, 1);
	printTable(t1);

	printf("在第2的位置插入元素5:\n");
	t1 = addTable(t1, 2, 5);
	printTable(t1);

	printf("查找元素3的位置:\n");
	int add = selectTable(t1, 3);
	printf("%d\n", add);

	printf("将元素3改为6:\n");
	t1 = amendTableElem(t1, 3, 6);
	printTable(t1);
}

//链表的基本操作 
void InitLink(linkedList* list) {
	list->head = NULL;
	list->last = NULL;
	list->size = 0;
}
//向链表中添加数据 
void addLink(linkedList* list, int index, char elem) {
	if (index<0 || index>index) {
		printf("要添加数据的位置非法");
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
	printf("\n链表长度为：%d\n", list->size);
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
		printf("要删除的位置不合法");
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
		printf("元素\'%c\'不在链表中！", elem);
	}
}

void changeListIndex(linkedList* list, int index, char elem) {
	if (index<0 || index>list->size - 1) {
		printf("要修改的位置不合法！");
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
		printf("元素%c不在链表中！", oldElem);
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
	//项链表中添加数据 
	int i = 0;
	for (; i < 6; i++) {
		addLink(&list, i, 'a' + i);
	}
	printList(&list);
	printf("删除链表中的第5个元素\n");
	deleteListIndex(&list, 4);
	printList(&list);
	printf("删除链表中的 \'o\'\n");
	deleteListElem(&list, 'o');
	printList(&list);
	printf("修改链表中第4个元素为：\'l\'\n");
	changeListIndex(&list, 3, 'l');
	printList(&list);
	printf("数据 \'l\' 在链表中的位置：%d\n", indexOf(&list, 'l'));
	printf("修改元素\'a\'为A\n");
	changeListElem(&list, 'a', 'A');
	printList(&list);
	printf("修改元素\'c\'为C\n");
	changeListElem(&list, 'c', 'C');
	printList(&list);
	printf("修改元素\'f\'为F\n");
	changeListElem(&list, 'f', 'F');
	printList(&list);
	freeList(&list);
}

//初始化单循环链表
void InitCircularLinkedList(linkedList* circularLinkedList) {
	circularLinkedList->head = NULL;
	circularLinkedList->last = NULL;
	circularLinkedList->size = 0;
}

//向单循环链表中添加数据
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

//单循环链表功能测试
void TestCircular() {
	cout << "\n单循环链表功能测试" << endl;
	linkedList circularList;
	InitCircularLinkedList(&circularList);
	char x = 'a';
	cout << "向单循环链表中添加‘a-z’10个小写字母" << endl;
	for (int i = 0; i < 10; i++) {
		addCircular(&circularList, i, x);
		x += 1;
	}
	printList(&circularList);
	cout << "删除单循环链表中字母‘f’" << endl;
	deleteCircular(&circularList, 'f');
	printList(&circularList);
	cout << "删除单循环链表中第5个元素" << endl;
	deleteCircular(&circularList, 4);
	printList(&circularList);
	cout << "修改单循环链表中‘c’为‘C’" << endl;
	changeCircular(&circularList, 'c', 'C');
	printList(&circularList);
	cout << "修改单循环链表中第4个元素为‘M’" << endl;
	changeCircular(&circularList, 3, 'M');
	printList(&circularList);
	cout << "释放单循环链表空间，并删除单循环链表" << endl;
	freeCircular(&circularList);
	printList(&circularList);
}

//双向链表基本操作实现

//双向链表初始化
void InitTwoList(twoLinkedList* twoList) {
	twoList->head = NULL;
	twoList->last = NULL;
	twoList->size = 0;
}

//向双向链表中添加数据
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

//删除双向链表中指定位置的节点删除
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
		cout << "要删除的位置不合法，请检查输入！" << endl;
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

//删除双向链表中指定值的元素
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

//把双向链表中index位置元素的值修改为elem
void changeTwoList(twoLinkedList* twoList, int index, char elem) {
	if (index < 0 || index >= twoList->size) {
		cout << "要修改的位置不合法，请检查输入！" << endl;
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

//把双向链表中值为oldElem的节点的值修改为newElem
void changeTwoList(twoLinkedList* twoList, char oldElem, char newElem) {
	twoNode* h = twoList->head;
	int index = indexOfTwoList(twoList, oldElem);
	if (index == -1) {
		cout << "本链表中没有找到值为：" << oldElem << "的元素节点" << endl;
	}
	else {
		changeTwoList(twoList, index, newElem);
	}
}

//在双向链表中查找元素elem的位置
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

//打印双向链表中的元素到屏幕上
void printTwoList(twoLinkedList* twoList) {
	twoNode* h = twoList->head;
	cout << "双向链表中有" << twoList->size << "个元素" << endl;
	while (h != NULL) {
		cout << h->elem << " ";
		h = h->next;
	}
	cout << endl;
}

//释放双向链表所占用的存储空间
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
	cout << "\n双向链表测试" << endl;
	twoLinkedList twoList;
	InitTwoList(&twoList);
	cout << "向双向链表中添加10个字母" << endl;
	char x = 'a';
	for (int i = 0; i < 10; i++) {
		addTwoList(&twoList, x);
		x += 1;
	}
	printTwoList(&twoList);
	cout << "删除双向链表中第5个元素" << endl;
	deleteTwoList(&twoList, 4);
	printTwoList(&twoList);
	cout << "删除双向链表中‘f’元素" << endl;
	deleteTwoList(&twoList, 'f');
	printTwoList(&twoList);
	cout << "把双向链表中第5个元素修改为M" << endl;
	changeTwoList(&twoList, 4, 'M');
	printTwoList(&twoList);
	cout << "把双向链表中值为'c'的节点值修改为‘C'" << endl;
	changeTwoList(&twoList, 'c', 'C');
	printTwoList(&twoList);
	cout << "释放双向链表所占用的存储空间" << endl;
	freeTwoList(&twoList);
	printTwoList(&twoList);
}