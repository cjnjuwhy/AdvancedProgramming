#ifndef STUDENTMANAGE_H
#define STUDENTMANAGE_H

#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include"Student.h"

using namespace std;

bool compId(const Student &lhs, const Student &rhs);
bool compName(const Student &lhs, const Student &rhs);

class StudentManage {
    const static string file_name;
public:
    void sortById();
    void sortByName();
    void add(Student &s);
    bool writeToFile(string fname = file_name);
    bool readFromFile(string fname = file_name);

    void show();

    friend bool compId(const Student &lhs, const Student &rhs);
    friend bool compName(const Student &lhs, const Student &rhs);

public:
    vector<Student> student_vector;



};



#endif // STUDENTMANAGE_H
