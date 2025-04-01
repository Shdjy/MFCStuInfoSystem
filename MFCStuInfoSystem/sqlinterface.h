#pragma once
#include "StuInfo.h"

#define SQL_MAX 256		// sql语句字符数组最大值

class sqlinterface
{
public:
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;
	char sql[SQL_MAX];

	bool Connect_MySql();
	//获取所有信息
	vector<StuInfo> GetAllInfo();
	//添加数据
	bool AddInfo(StuInfo info);
	//删除数据
	bool DeleteInfo(StuInfo info);
	//修改
	bool UpdataInfo(StuInfo OldInfo,StuInfo NewInfo);
	//查找
	vector<StuInfo> SelectInfo(CString name);
	//关闭数据库
	void CloseMysql();
};

