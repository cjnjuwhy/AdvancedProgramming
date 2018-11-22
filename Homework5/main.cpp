#include"Teacher.h"
#include"Student.h"
#include"BuildingManager.h"
#include<stdlib.h>

int main() {
	BuildingManager *CSBuilding = new BuildingManager();

	CSBuilding->addCard({1,2,5});
	CSBuilding->addFace({2,3,4});

	Student* st1 = new Student("A", 2);
	Student* st2 = new Student("B", 3);
	Teacher* t1 = new Teacher("C", 5, 1);
	Teacher* t2 = new Teacher("D", 6, 2);
	Student* st3 = new Student("E", 4);

	CSBuilding->in(st1, "8:00");
	CSBuilding->out(st2, "8:05");
	CSBuilding->out(t1, "8:05");
	CSBuilding->in(t2, "8:10");
	CSBuilding->in(st3, "8:10");

	cout << "Building dialog\n";
	CSBuilding->showLog();

	cout << "\nStudent dialog\n";
	st1->showLog();
	t1->print();


	cin.get();

}