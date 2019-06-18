#include "Action.h"

class ShowBin : public Action {
public:
	ShowBin() : name("Show binary value") {}
	void Operate(AString*);
	const std::string& GetName() const{ return name; }
private:
	std::string GetBinary(AString*) const;
	std::string name; 
};
