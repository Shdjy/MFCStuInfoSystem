#include "pch.h"
#include "sqlinterface.h"

bool sqlinterface::Connect_MySql()
{
	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, "localhost", "root", "123456", "stuinfo", 3306, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败"));
		return false;
	}
	else
	{
		AfxMessageBox(_T("成功访问数据库"));
		
		mysql_query(&mysqlCon, "SET NAMES 'GB2312'");
	}
	return true;
}

vector<StuInfo> sqlinterface::GetAllInfo()
{
	vector < StuInfo> info;

	snprintf(sql, SQL_MAX, "select * from stuinfosystem;");

	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	if (ret)
	{
		AfxMessageBox(_T("数据库查询失败"));
		return info;
	}
	// 获取结果集
	res = mysql_store_result(&mysqlCon);

	// 获取查询到的一行数据
	// 给row赋值，判断row是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res)) {
		StuInfo stuinfo(row[0], row[1], atoi(row[2]), atoi(row[3]), atoi(row[4]), atoi(row[5]));
		info.push_back(stuinfo);
	}

	// 释放结果集
	mysql_free_result(res);

	return info;
}

bool sqlinterface::AddInfo(StuInfo info)
{
	snprintf(sql, SQL_MAX, "INSERT INTO `stuinfo`.`stuinfosystem`  VALUES ('%s', '%s', %d, %d, %d, %d);", info.m_name.c_str(), info.m_sex.c_str(),
		info.m_class_, info.m_chinese,info.m_math,info.m_english);
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	if (ret)
	{
		AfxMessageBox(_T("数据库查询失败"));
		return false;
	}
	return true;
}

bool sqlinterface::DeleteInfo(StuInfo info)
{
	snprintf(sql, SQL_MAX, "DELETE FROM `stuinfo`.`stuinfosystem` WHERE `name` = '%s';", info.m_name);
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	if (ret)
	{
		AfxMessageBox(_T("删除失败"));
		return false;
	}
	return true;
}

bool sqlinterface::UpdataInfo(StuInfo OldInfo,StuInfo NewInfo)
{
	snprintf(sql, SQL_MAX, "UPDATE `stuinfo`.`stuinfosystem` SET `name` = '%s', `sex` = '%s', `class_` = %d, `chinese` = %d,`math` = %d, `english` = %d WHERE `name` = '%s';", 
		NewInfo.m_name.c_str(),NewInfo.m_sex.c_str(),NewInfo.m_class_,NewInfo.m_chinese,NewInfo.m_math,NewInfo.m_english,OldInfo.m_name.c_str());
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	if (ret)
	{
		AfxMessageBox(_T("修改失败！"));
		return false;
	}
	return true;
}

vector<StuInfo> sqlinterface::SelectInfo(CString name)
{
	vector <StuInfo> info;
	snprintf(sql, SQL_MAX, "SELECT * FROM `stuinfo`.`stuinfosystem` WHERE `NAME` = '%s';",name);
	int ret = mysql_real_query(&mysqlCon, sql, (unsigned long)strlen(sql));
	if (ret)
	{
		AfxMessageBox(_T("查找失败！"));
		return info;
	}
	else
	{
		// 获取结果集
		res = mysql_store_result(&mysqlCon);

		// 获取查询到的一行数据
		// 给row赋值，判断row是否为空，不为空就打印数据。
		while (row = mysql_fetch_row(res)) {
			StuInfo stuinfo(row[0], row[1], atoi(row[2]), atoi(row[3]), atoi(row[4]), atoi(row[5]));
			info.push_back(stuinfo);
		}

		// 释放结果集
		mysql_free_result(res);
		return info;
	}
}

void sqlinterface::CloseMysql()
{
	mysql_close(&mysqlCon);
}
