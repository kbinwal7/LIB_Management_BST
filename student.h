#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class student {
private:
    int id;
    string name;

public:
    int issued;
    student();
    student(int num, string m);
    string getName();
    int getID();
};

class nodeS {
public:
    student stu;
    nodeS* right;
    nodeS* left;
    nodeS(student s);
};

class bst_student {
public:
    nodeS* root;
    bst_student();
    nodeS* insertID(nodeS* root, student s);
    nodeS* searchID(nodeS* root, int id);
    nodeS* deleteID(nodeS* root, int targetID);
};

#endif
