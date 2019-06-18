// Action.cpp
#include <iostream>
#include "Action.h"
#include "OctString.h"

using namespace std;

long Action::GetDecimal(AString* pObj) const {
	if (dynamic_cast<OctString*>(pObj)) {
		long dest;
		string source = pObj->GetVal();
		sscanf(source.c_str(), "%o", &dest);
		return dest;
	}
	else {
		cout << "Action not supported." << endl;
		return -1;
	}
}
