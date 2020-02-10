/*************************************************************************
    > File Name       : worker.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 16时54分26秒
 ************************************************************************/

#pragma once
#include <iostream>
#include <string>

using namespace std;

// 职工抽象类
class Worker
{
	public:
		int m_Id;              // 职工编号
		string m_Name;         // 职工姓名
		int m_DepId;           // 部门编号

		// 显示个人信息
		virtual void showInfo() = 0;

		// 获取岗位名称
		virtual string getDeptName() = 0;
};
