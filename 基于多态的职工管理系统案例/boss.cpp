/*************************************************************************
    > File Name       : boss.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 17时34分39秒
 ************************************************************************/
#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	m_Id = id;
	m_Name = name;
	m_Id = dId;
}

void Boss::showInfo()
{
	cout << "职工编号：" << m_Id << "\t职工姓名：" << m_Name << "\t岗位：" << getDeptName()
		<< "\t岗位职责：管理公司所有事物。" << endl;
}

string Boss::getDeptName()
{
	return string ("老板");
}
