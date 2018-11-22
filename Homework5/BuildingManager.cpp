#include"BuildingManager.h"

BuildingManager::BuildingManager(){
}

void BuildingManager::addCard(vector<int> cards){
	for(int c:cards){
		card_info.insert(c);
	}
}

void BuildingManager::addFace(vector<int> faces){
	for(int f:faces){
		face_info.insert(f);
	}
}

void BuildingManager::deleteCard(vector<int> cards){
	for(int c: cards){
		deleteCard(c);
	}
}

void BuildingManager::deleteFace(vector<int> faces){
	for(int f:faces){
		deleteFace(f);
	}
}

void BuildingManager::deleteCard(int card){
	set<int>::iterator it = card_info.find(card);
	if(it != card_info.end())	
		card_info.erase(it);
}

void BuildingManager::deleteFace(int face){

}

void BuildingManager::clearCard(){
	card_info.clear();
}

void BuildingManager::clearFace(){
	face_info.clear();
}

void BuildingManager::printCard(){
	cout << "The registered card:";
	for(int c:card_info){
		cout << c << "\t";
	}
	cout << endl;
}

void BuildingManager::printFace(){
	cout << "The registered face:";
	for(int f:face_info){
		cout << f << "\t";
	}
	cout << endl;
}

bool BuildingManager::checkFace(int face)
{
	set<int>::iterator it = face_info.find(face);
	if (it == face_info.end())
		return false;
	else
		return true;
}

bool BuildingManager::checkCard(int card)
{
	set<int>::iterator it = card_info.find(card);
	if (it == card_info.end())
		return false;
	else
		return true;
}

void BuildingManager::addLog(Log & newLog)
{
	log.push_back(newLog);
}

void BuildingManager::showLog(){
	sort(log.begin(), log.end(), comp);

	for(auto s:log){
		cout << s.showLog() << endl;
	}
}

void BuildingManager::in(People* p, string time)
{
	Log newLog(p->addLog(time, true, checkCard(p->getCard()), checkFace(p->getFace())));
	newLog.showLog();
	log.push_back(newLog);
}

void BuildingManager::out(People * p, string time)
{
	Log newLog = p->addLog(time, false, checkCard(p->getCard()), checkFace(p->getFace()));
	newLog.showLog();
	log.push_back(newLog);
}



bool comp(const Log& a,const Log& b) {
	string a_first = a.time.substr(0, a.time.find(":"));
	string a_second = a.time.substr(a.time.find(":") + 1, a.time.size());
	int a1 = atoi(a_first.c_str());
	int a2 = atoi(a_second.c_str());

	string b_first = b.time.substr(0, b.time.find(":"));
	string b_second = b.time.substr(b.time.find(":") + 1, b.time.size());
	int b1 = atoi(b_first.c_str());
	int b2 = atoi(b_second.c_str());

	if (a1 < b1)
		return true;
	else if (a1 > b1)
		return false;
	else {
		if (a2 < b2)
			return true;
		else if (a2 > b2)
			return false;
		else {
			if (!(b.in))
				return false;
			return true;
		}
	}
	return true;
}
