#include"Teacher.h"

Teacher::Teacher(string name, int card)
:People(name, card){
}

Teacher::Teacher(string name, int card, int face)
:Teacher(name, card){
    face_number = face;
}


Teacher::~Teacher(){

}

int Teacher::getFace(){
    return face_number;
}

Log& Teacher::addLog(string time, bool in, bool checkCard, bool checkFace)
{
	bool result = checkCard || checkFace;
	Log newLog(name, "老师", time, in, result, checkFace);
	log.push_back(newLog);
	return log.back();
}

void Teacher::print()
{
	cout << "老师：" << name  << "\tCard: " << card_number << "\tFace: " << face_number << endl;
}

