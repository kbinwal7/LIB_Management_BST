#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"

extern bst_book* bookCollection;
extern bst_student* studentData;

void createLIB();

class studentRequest {
public:
    student st;
    studentRequest(int id);
    void checkAvailaiblity(int id);
    void requestIssue(int id);
    void requestReturn(int id);
};

#endif
