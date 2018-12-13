#include"StudentManage.h"

const string StudentManage::file_name = "/Users/huanyu_wang/Desktop/Student.qt";

void StudentManage::sortById() {
    sort(student_vector.begin(), student_vector.end(), compId);
}

void StudentManage::sortByName() {
    sort(student_vector.begin(), student_vector.end(), compName);
}

void StudentManage::add(Student &s) {
    student_vector.push_back(s);
}

void StudentManage::show() {
    for(auto st : student_vector){
        st.show();
    }

}

bool compId(const Student &lhs, const Student &rhs) {
    return (lhs.id < rhs.id);
}

bool compName(const Student &lhs, const Student &rhs) {
    return rhs.name.compare(lhs.name) > 0;
}

bool StudentManage::writeToFile(string fname) {

    ofstream out_file;
    try {
        out_file.open(fname, ios::out|ios::binary);
        if (out_file.fail())
            throw fname;
    }
    catch (string e) {
        cout << "Failed to write the file.";
        return false;
    }

    int size = student_vector.size();
    out_file.write((char*)&size, sizeof(size));

    for(auto s:student_vector){
        out_file.write((char*)&s, sizeof(s));
    }
    out_file.close();
    return true;

}

bool StudentManage::readFromFile(string fname) {
    ifstream in_file;
    try{
        in_file.open(fname, ios::in|ios::binary);
        if(in_file.fail())
            throw fname;
    }catch(string e){
        cout << "fail to open the file: " << e << endl;
        return false;
    }

    int len;
    in_file.read((char*)&len, sizeof(len));

    Student* st = new Student[len]();
    for(int i=0; i<len; i++){
        in_file.read((char *) &st[i], sizeof(st[i]));
        student_vector.push_back(st[i]);
    };
    in_file.close();
    return true;
}

