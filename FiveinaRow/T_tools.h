#pragma once
//#include "T_tools.h"

class T_tools
{
public:
	T_tools & operator >> (int &i);  //重载 >> 用于读取1000以内的int型的数字
	T_tools();
	~T_tools();
};

namespace Tts
{
	extern T_tools cint;  //定义cint类比于cin
}