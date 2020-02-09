/*************************************************************************
    > File Name       : workManager.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 14时35分02秒
 ************************************************************************/
#include"workManager.h"

using namespace std;

WorkManager::WorkManager()
{

}

// 显示菜单函数声明
void WorkManager::ShowMenu()
{
	cout << "*********************************************" << endl;
	cout << "********* 欢迎使用职工管理系统 ************" << endl;
	cout << "*********** 0.退出管理程序 ******************" << endl;	cout << "*********** 1.增加职工信息 ******************" << endl;	cout << "*********** 2.显示职工信息 ******************" << endl;	cout << "*********** 3.删除离职职工 ******************" << endl;	cout << "*********** 4.修改职工信息 ******************" << endl;
	cout << "*********** 5.查找职工信息 ******************" << endl;
	cout << "*********** 6.按照编号排序 ******************" << endl;	cout << "*********** 7.清空所有文档 ******************" << endl;	cout << "**********************************************" << endl << endl;
}

// 退出系统函数声明
void WorkManager::exitSystem()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);             // 退出程序
}

// 添加职工函数声明
void WorkManager::AddEmp()
{
	cout << "请输入添加职工数量：" << endl;

	int addNum = 0;           // 保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		// 添加，计算添加新空间的大小
		int newSize = m_EmpNum + addNum;      // 新空间大小 = 原来记录人数 + 新增人数	
		Worker ** newSpace = new Worker* [newSize];

		// 将原来空间下数据，拷贝到新空间下
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}

		// 批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;        // 部门选择

			cout << "请输入第" << i + 1 << "个新职工编号；" << endl;
			cin >> id;
			
			cout << "请输入第" << i + 1 << "个新职工姓名；" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			
			Worker * worker = nullptr;
			switch(dSelect)
			{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3: 
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
			}
			newSpace[m_EmpNum + i] = worker;
		}

		// 释放原有空间
		delete[] m_EmpArray;

		// 更新空间的指向
		m_EmpArray = newSpace;
		
		// 更新新的职工人数
		m_EmpNum = newSize;

		// 提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else 
		cout << "输入数据有误！" << endl;

	// 按任意键清屏，回到上级目录
	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{

}
