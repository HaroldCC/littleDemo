/*************************************************************************
    > File Name       : employee.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 17时02分28秒
 ************************************************************************/
// 普通员工

#pragma once

#include<iostream>
#include "worker.h"

using namespace std;

class Employee: public Worker
{
	public:
		Employee(int id, string name, int dId);

		// 显示个人信息
		virtual void showInfo();

		// 获取岗位名称
		virtual string getDeptName();
};
