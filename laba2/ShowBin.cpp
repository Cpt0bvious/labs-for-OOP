// ShowBin.cpp
#include <iostream>
#include "ShowBin.h"
#include "ShowDec.h"
#include "AString.h"

using namespace std;

void ShowBin::Operate(AString* pObj) {
	cout << pObj->GetName() << ": ";
	cout << GetBinary(pObj) << endl;
	cin.get();
}

string ShowBin::GetBinary(AString* pObj) const {
	int nBinDigit = 3 * pObj->GetSize();
	char* binStr = new char[nBinDigit];
	long decVal = GetDecimal(pObj);
	if(-1 == decVal)
		return string("");
	int i = nBinDigit;
	while (decVal > 0) {
		binStr[--i] = 48 + (decVal % 2);
		decVal >>= 1;
	}
	string temp = "";
	for (int i = 0; i < nBinDigit; i++) 
		temp += binStr[i];
	delete [] binStr;
	return temp;
}

// Глобальный объект
ShowBin show_bin;
