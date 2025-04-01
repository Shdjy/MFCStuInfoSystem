#pragma once
#include "StuInfo.h"

#define SQL_MAX 256		// sql����ַ��������ֵ

class sqlinterface
{
public:
	MYSQL_RES* res;
	MYSQL_ROW row;
	MYSQL mysqlCon;
	char sql[SQL_MAX];

	bool Connect_MySql();
	//��ȡ������Ϣ
	vector<StuInfo> GetAllInfo();
	//�������
	bool AddInfo(StuInfo info);
	//ɾ������
	bool DeleteInfo(StuInfo info);
	//�޸�
	bool UpdataInfo(StuInfo OldInfo,StuInfo NewInfo);
	//����
	vector<StuInfo> SelectInfo(CString name);
	//�ر����ݿ�
	void CloseMysql();
};

