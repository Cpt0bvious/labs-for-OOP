// Main.cpp
#include <iostream>
#include <string>
#include "AString.h"
#include "SymbString.h"
//#include "HexString.h"
#include "OctString.h"
#include "Action.h"
#include "ShowStr.h"
#include "ShowDec.h"
#include "ShowBin.h"
#include "OperatorSub.h"
#include "Factory.h"
#include "Menu.h"

using namespace std;

Action* pActs[] = { &show_str, &show_dec, &show_bin, &operator_sub};
vector<Action*> actionList(pActs,
	pActs + sizeof(pActs) / sizeof(Action*));
AString* pSubObj;

int main() {
	Factory factory;
	Menu menu(actionList);
	JobMode jobMode;
	while ((jobMode = menu.SelectJob()) != Exit) {
		switch (jobMode) {
		case AddObj:
		    factory.AddObject();
			break;
		case DelObj:
		    factory.DeleteObject();
			break;
		case WorkWithObj:
			AString* pObj = menu.SelectObject(factory, "...................................\nSelect one of the following Object:\n"); // выбор объекта
			Action* pAct = menu.SelectAction(pObj); // выбор действия
//			if (pAct) 
				if (pAct == &operator_sub) { // если выбран "Оператор -"
					pSubObj = menu.SelectObject(factory, "Select the subtracted object\n"); // выбор вычитаемого объекта
					if ((dynamic_cast<OctString*>(pObj)) && (dynamic_cast<OctString*>(pSubObj)) // если тип обоих объектов OctString
					|| (dynamic_cast<SymbString*>(pObj)) && (dynamic_cast<SymbString*>(pSubObj))) {// или если тип обоих объектов SymbString
						pObj->SubObjValue = pSubObj->GetVal();
						pAct->Operate(pObj);
					} else {
						cout << "Object types are not identical\n"; // если объекты разных типов
					}
				} else {
					pAct->Operate(pObj);
				}
			break;
		}
		cin.get();
	}
	cout << "Bye!\n";
	return 0;
}
