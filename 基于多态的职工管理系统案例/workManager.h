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


		// 添加职工
		void AddEmp();


		~WorkManager();
};
