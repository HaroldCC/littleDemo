/*************************************************************************
    > File Name       : manager.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 17时25分53秒
 ************************************************************************/
#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_DepId = dId;
}

void Manager::showInfo()
{
	cout << "职工编号：" << m_Id << "\t职工姓名：" << m_Name << "\t岗位：" << getDeptName()
		<< "\t岗位职责：完成老板给的任务，并下发给员工。" << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}
