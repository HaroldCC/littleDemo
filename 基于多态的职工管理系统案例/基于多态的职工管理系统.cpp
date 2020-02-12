/*************************************************************************
    > File Name       : 基于多态的职工管理系统.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 14时20分01秒
 ************************************************************************/
#include<iostream>
#include "workManager.h"

using namespace std;

int main()
{
	WorkManager wm;
	int choice = 0;   // 选择变量
	
	while(true)
	{
		wm.ShowMenu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;

		switch(choice)
		{
			case 0:              // 退出系统
				wm.exitSystem();
				break;
			case 1:              // 增加职工
			wm.AddEmp();
				break;
			case 2:               // 显示职工
				wm.showEmp();
				break;
			case 3:                // 删除职工
				wm.DelEmp();
				break;
			case 4:                // 修改职工
				wm.ModEmp();
				break;
			case 5:                // 查找职工
				wm.FindEmp();
				break;
			case 6:                 // 排序职工
				wm.SortEmp();
				break;
			case 7:                  // 清空
				break;
			default:
				system("cls");
				break;
		}


	}
	system("pause");	
     
    return 0;
}

