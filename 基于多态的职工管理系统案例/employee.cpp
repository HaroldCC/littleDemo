/*************************************************************************
    > File Name       : emplyee.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 17时07分02秒
 ************************************************************************/
#include "employee.h"

Employee::Employee(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DepId = dId;
}

void Employee::showInfo()
{
	cout << "职工编号：" << m_Id << "\t职工姓名：" << m_Name << "\t岗位：" << getDeptName()
		<< "\t岗位职责: 完成经理交给的任务。" << endl;
}

string Employee::getDeptName()
{
	return string("普通员工");
}
