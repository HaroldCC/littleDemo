/*************************************************************************
    > File Name       : manager.h
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月08日 星期六 17时22分07秒
 ************************************************************************/
// 经理类文件
#pragma once
#include<iostream>
#include "worker.h"

using namespace std;

class Manager : public Worker
{
	public:
		Manager(int id, string name, int dId);

		// 显示个人信息
		virtual void showInfo();

		// 获取岗位名称
		virtual string getDeptName();
};
