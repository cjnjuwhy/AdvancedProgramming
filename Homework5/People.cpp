#include "People.h"


People::People(string name, int card_number)
{
	this->name = name;
	this->card_number = card_number;
}

People::~People()
{
}

int People::getCard()
{
	return card_number;
}

void People::showLog()
{
	for (Log s : log)
		cout << s.showLog() << endl;
}