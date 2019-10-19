// DataStruct.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "List.h"

int main()
{
	int choice = - 1;
	cout << "数据结构实现" << endl;
	cout << "1：顺序表实现    2：单链表实现    3：单循环链表实现    4：双向链表实现    0：退出" << endl;
	while (1) {
		cout << "请输入一个整数以选择功能：";
		cin >> choice;
		if (choice == 0) {
			break;
		}
		switch (choice) {
		case 1:
			TestTable();
			break;
		case 2:
			TestList();
			break;
		case 3:
			TestCircular();
			break;
		case 4:
			TestTwoList();
			break;
		default:
			cout << "输入的数字非法，请重新输入！";
			break;
		}
	}
	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
