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
	// 1、文件不存在
	ifstream fin;
	fin.open(FILENAME, ios::in);

	if (!fin.is_open())
	{
		cout << "文件不存在！" << endl;

		// 初始化属性
		m_EmpNum = 0;           // 初始化记录人数
		m_EmpArray = nullptr;         // 初始化数组指针
		m_isFileEmpty = true;         // 初始化文件为空

		fin.close();
		return;
	}

	// 2、文件存在但数据为空
	char ch;
	fin >> ch;
	if (fin.eof())
	{
		cout << "文件内容为空！" << endl;  
		
		// 初始化属性
		m_EmpNum = 0;           // 初始化记录人数
		m_EmpArray = nullptr;         // 初始化数组指针
		m_isFileEmpty = true;         // 初始化文件为空

		fin.close();
		return;
	}

	// 3、文件存在，并且有数据
	int num = getEMpNum();
	//cout << "职工人数为：" << num << endl;
	m_EmpNum = num;

	// 开辟空间
	m_EmpArray = new Worker*[m_EmpNum];
	// 将文件的数据存到数组中
	init_Emp();

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

		save_staff_toFile();    // 将员工添加进文件中

		// 当添加职工后将文件为空标志设为false
		m_isFileEmpty = false;

		// 提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;
	}
	else 
		cout << "输入数据有误！" << endl;

	// 按任意键清屏，回到上级目录；
	system("pause");
	system("cls");
}

// 将职工信息保存到文件函数声明
void WorkManager::save_staff_toFile()
{
	ofstream fout;
	fout.open(FILENAME, ios::out);

	for(int i = 0; i < m_EmpNum; i++)
	{
		fout << "Num" << " Name" << " DepartmentId" << endl;
		fout <<  m_EmpArray[i]->m_Id << "   "
			<< m_EmpArray[i]->m_Name << "    "
			<< m_EmpArray[i]->m_DepId << endl;
	}

	fout.close();
}


// 获取文件中人数函数声明
int WorkManager::getEMpNum()
{
	ifstream fin;
	fin.open(FILENAME, ios::in);        // 打开文件 读

	int id;
	string name;
	int dId;

	int num = 0;

	while (fin >> id && fin >> name && fin >> dId)
	{
		// 统计人数
		num++;
	}

	fin.close();

    return num;

}

// 初始化员工函数声明
void WorkManager::init_Emp()
{
	ifstream fin;
	fin.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (fin >> id && fin >> name && fin >> dId)
	{
		Worker * worker = nullptr;

		if (dId == 1)    // 普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)         // 经理
		{
			worker = new Manager(id, name, dId);
		}
		else         // 老板
		{
			worker = new Boss(id, name, dId);
		}

		m_EmpArray[index] = worker;
		index++;
	}

	// 关闭文件
	fin.close();
}

// 显示职工信息
void WorkManager::showEmp()
{
	// 判断文件是否为空
	if(m_isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// 利用多态调用接口
			m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

// 删除职工函数声明
void WorkManager::DelEmp()
{
	if (m_isFileEmpty)
	{
		cout << "文件不存在或记录为空！" <<  endl;
	}
	else
	{
		cout << "请输入想要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = isEmpExist(id);

		if (index != -1)               // 职工存在，且要删除index位置上的职工‘
		{
			// 数据前移
			for (int i = index; i < m_EmpNum - 1; i++)
			{
				// 数据=前移
				m_EmpArray[i] = m_EmpArray[i+1];
			}
			m_EmpNum--;            // 更新数组中人员个数

			// 数据同步到文件中
			save_staff_toFile();

			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到职工！" << endl;
		}
	}

	system("pause");
	system("cls");
}

// 判断职工是否存在，存在返回在数组中的位置，否则返回 -1
int WorkManager::isEmpExist(int id)
{
	int index = -1;

	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_Id == id)
		{
			// 找到职工
			index = i;
			break;
		}
	}

	return index;
}

// 修改职工
void WorkManager::ModEmp()
{
	if (m_isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = isEmpExist(id);
		if(ret != -1)
		{
			// 查找到员工
			delete m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到：" << id << "号员工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入新姓名：" << endl;
			cin >> newName;

			cout << "请输入岗位：" <<endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker * worker = nullptr;
			switch(dSelect)
			{
				case 1:
					worker = new Employee(newId, newName, dSelect);
					break;
				case 2:
					worker = new Manager(newId, newName, dSelect);
					break;
				case 3:
					worker = new Boss(newId, newName, dSelect);
					break;
				default:
					break;
			}


			// 更新数据到数组
			m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			save_staff_toFile();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}

	system("pause");
	system("cls");
}

// 查找职工
void WorkManager::FindEmp()
{
	if (m_isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			// 按编号
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = isEmpExist(id);
			if (ret != -1)
			{
				// 找到职工
				cout << "查找成功！该职工信息如下：" << endl;
				m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败！查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			// 按姓名
			string name;
			cout << "请输入查找的职工姓名：" << endl;
			cin >> name;

			// 判断是否查到的标志，默认未找到职工
			bool flag = false;
			
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功！职工编号为：" << m_EmpArray[i]->m_Id << "号职工信息如下：" << endl;

					flag = true;

					m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
				{
					cout << "查找失败，查无此人！" << endl;
				}
		}
		else 
		{
			cout << "输入选项有误！" << endl;
		}
	}

	system("pause");
	system("cls");
}

// 排序职工
void WorkManager::SortEmp()
{
	if (m_isFileEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;               // 声明最小值或最大值

			for (int j = j+1; j < m_EmpNum; j++)
			{
				if (select == 1) 	// 升序
				 {
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else         // 降序
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			// 判断数据，进行交换
			if (i != minOrMax)
			{
				Worker * temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "排序成功！排序后结果为：" << endl;
		save_staff_toFile();     // 将排序后结果存入文件
		showEmp();
	}
}

// 清空文件
void WorkManager::CleanFile()
{
	cout << "确认清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream fout(FILENAME, ios::trunc);        // 删除文件后重新创建
		fout.close();

		if (m_EmpArray != nullptr)
		{
			// 删除堆区的每个职工对象
			for (int i = 0; i < m_EmpNum; i++)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = nullptr;
			}


			// 删除堆区数组指针
			delete [] m_EmpArray;
			m_EmpArray = nullptr;
			m_EmpNum = 0;
			m_isFileEmpty = true;
		}

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkManager::~WorkManager()
{
	if(m_EmpArray != nullptr)
	{
		delete [] m_EmpArray;
		m_EmpArray = NULL;
	}
}
