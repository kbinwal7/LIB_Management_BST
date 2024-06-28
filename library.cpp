#include "library.h"
#include<iostream>
using namespace std;

bst_book* bookCollection = new bst_book();
bst_student* studentData = new bst_student();

void createLIB() {
    book b1(12345, "My First Course in Probability", 2);
    book b2(12344, "Perfect Us", 2);
    book b3(12342, "The Eternity of Love", 3);
    book b4(12343, "RollerCoaster Ride", 4);
    book b5(12346, "Love of My Life", 3);
    bookCollection->root = bookCollection->insertBook(bookCollection->root, b1);
    bookCollection->root = bookCollection->insertBook(bookCollection->root, b2);
    bookCollection->root = bookCollection->insertBook(bookCollection->root, b3);
    bookCollection->root = bookCollection->insertBook(bookCollection->root, b4);
    bookCollection->root = bookCollection->insertBook(bookCollection->root, b5);

    student s1(223708, "Khushee");
    student s2(112035, "Purvi");
    student s3(102346, "Muskaan");
    studentData->root = studentData->insertID(studentData->root, s1);
    studentData->root = studentData->insertID(studentData->root, s2);
    studentData->root = studentData->insertID(studentData->root, s3);
}

studentRequest::studentRequest(int id) {
    st = studentData->searchID(studentData->root, id)->stu;
}

void studentRequest::checkAvailaiblity(int id) {
    book b = bookCollection->searchID(bookCollection->root, id)->bk;
    if (b.isPresent()) {
        cout << "Available!" << endl;
    } else {
        cout << "Unavailable!" << endl;
    }
}

void studentRequest::requestIssue(int id) {
    book b = bookCollection->searchID(bookCollection->root, id)->bk;
    if (b.isPresent()) {
        if(st.issued<2){
            ++st.issued;
            b.issueBook(st);
        } else {
            cout << "Cannot Issue More than 2 books!\n";
        }
    } else {
        cout << "Book not Available\n";
    }
}

void studentRequest::requestReturn(int id) {
    book b = bookCollection->searchID(bookCollection->root, id)->bk;
    --st.issued;
    b.returnBook(st);
}
