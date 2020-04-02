/*************************************************************************
    > File Name       : boss.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 17时31分58秒
 ************************************************************************/
#pragma once
#include<iostream>
#include "worker.h"

using namespace std;

class Boss : public Worker
{
	public:
		Boss(int id, string name, int dId);

		// 显示个人信息
		virtual void showInfo();

		// 获取岗位名称
		virtual string getDeptName();
};

