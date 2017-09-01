#include "T_tools.h"
#include <iostream>
#include <string>
using namespace std;


T_tools& T_tools::operator>>(int & i)
{
	string str;
	char ch;
	while ((ch = getchar()) != '\n')
	{
		str += ch;
	}
	int t;
	while ((t = str.find(' ', 0)) != str.npos)
	{
		str.erase(t, 1);
	}
	if (str.length() == 1)
	{
		i = int(str.at(0))-48;
	}
	else if (str.length() == 2)
	{
		i = int(str.at(0)) - 48;
		i=i*10+ int(str.at(1)) - 48;
	}
	else if (str.length() == 2)
	{
		i = int(str.at(0)) - 48;
		i = i * 10 + int(str.at(1)) - 48;
		i = i * 10 + int(str.at(2)) - 48;
	}
	return (*this);
}

namespace Tts 
{
	T_tools cint;
}

T_tools::T_tools()
{
}


T_tools::~T_tools()
{
}
