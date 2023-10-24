#pragma once
class StuInfo
{
public:
	string m_name;
	string m_sex;
	int m_class_;
	int m_chinese;
	int m_math;
	int m_english;
	
	StuInfo();
	StuInfo(string name, string sex, int class_, int chinese, int math, int english);
};

