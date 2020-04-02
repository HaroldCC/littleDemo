/*************************************************************************
    > File Name       : workManager.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 14时28分31秒
 ************************************************************************/
#pragma once         // 防止头文件重复包含

#include<iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkManager
{
	public:
		WorkManager();

		// 显示菜单函数
		void ShowMenu();
		
		// 退出系统函数
		void exitSystem();

		// 记录职工人数
		int m_EmpNum; 

		//添加职工
		Worker ** m_EmpArray;

		// 文件是否为空标志
		bool m_isFileEmpty;


		// 添加职工
		void AddEmp();

		// 将职工信息保存到文件
		void save_staff_toFile();

		// 获取文件中有多少职工数据
		int getEMpNum();

		// 初始化职工
		void init_Emp();

		// 显示职工
		void showEmp();

		// 删除职工
		void DelEmp();

		// 判断职工编号是否存在，若存在返回职工在数组中的位置，不存在返回-1
		int isEmpExist(int id);

		// 修改职工
		void ModEmp();

		// 查找员工
		void FindEmp();
		
		// 排序职工
		void SortEmp();

		// 清空文件
		void CleanFile();

		~WorkManager();
};
