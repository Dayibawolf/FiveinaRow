#pragma once
//#include "T_tools.h"

class T_tools
{
public:
	T_tools & operator >> (int &i);  //���� >> ���ڶ�ȡ1000���ڵ�int�͵�����
	T_tools();
	~T_tools();
};

namespace Tts
{
	extern T_tools cint;  //����cint�����cin
}