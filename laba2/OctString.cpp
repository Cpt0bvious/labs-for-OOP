// HexString.cpp
#include <iostream>
#include <string>
#include "OctString.h"

using namespace std;

bool IsOctStrVal(std::string str) {
	for (int i = 0; i < str.size(); ++i)
		if (-1 == octal.find_first_of(str[i]))
			return false;
	return true;
}

OctString::OctString(string _name, string _val):
name(_name) {
	if(IsOctStrVal(_val))
		val = _val;
}
