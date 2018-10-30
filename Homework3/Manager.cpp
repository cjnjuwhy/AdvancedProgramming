#include"Manager.h"

 	
Manager::Manager(){
}
Manager::~Manager(){
}

void Manager::add(Member * member){
	data.push_back(member);
}

void Manager::sortById(){
	sort(data.begin(), data.end(), compareId);
}

void Manager::sortByDate(){
	sort(data.begin(), data.end(), compareDate);
}

void Manager:: printSearch(const int id){
	for(Member *m: data){
		if(m->getId() == id)
			m->printInfo();
	}
}

void Manager:: printAll(){
	for(Member *m: data){
		m->printInfo();
	}
}

bool compareId(Member* a, Member* b){
	if(a->getId() < b->getId())
		return true;
	return false;
}
bool compareDate(Member* a, Member* b){
	if(a->getDate() < b->getDate())
		return true;
	return false;
}