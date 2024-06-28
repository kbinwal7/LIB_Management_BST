#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "student.h"
using namespace std;

class book {
private:
    int bookID;
    string bookName;

public:
    int quantity;
    bool present;
    bst_student* issuedSt;

    book(int id, string name, int q);
    int getID();
    string getBookName();
    bool isPresent();
    void updateAvailablity();
    void issueBook(student s);
    void returnBook(student s);
};

class nodeB {
public:
    book bk;
    nodeB* right;
    nodeB* left;
    nodeB(book b);
};

class bst_book {
public:
    nodeB* root;
    bst_book();
    nodeB* insertBook(nodeB* root, book s);
    nodeB* searchID(nodeB* root, int id);
    nodeB* deleteID(nodeB* root, int targetID);
};

#endif
