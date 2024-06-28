#include "student.h"

student::student() : id(0), name(""), issued(-1) {}

student::student(int num, string m) : id(num), name(m), issued(0) {}

string student::getName() {
    return name;
}

int student::getID() {
    return id;
}

nodeS::nodeS(student s) : stu(s), right(nullptr), left(nullptr) {}

bst_student::bst_student() : root(nullptr) {}

nodeS* bst_student::insertID(nodeS* root, student s) {
    if (root == nullptr) {
        return new nodeS(s);
    }
    if (root->stu.getID() < s.getID()) {
        root->right = insertID(root->right, s);
    } else {
        root->left = insertID(root->left, s);
    }
    return root;
}

nodeS* bst_student::searchID(nodeS* root, int id) {
    if (root == nullptr || root->stu.getID() == id) {
        return root;
    }
    if (root->stu.getID() > id) {
        return searchID(root->left, id);
    } else {
        return searchID(root->right, id);
    }
}

nodeS* bst_student::deleteID(nodeS* root, int targetID) {
    if (root == nullptr) {
        return root;
    }

    if (targetID < root->stu.getID()) {
        root->left = deleteID(root->left, targetID);
    } else if (targetID > root->stu.getID()) {
        root->right = deleteID(root->right, targetID);
    } else {
        if (root->left == nullptr) {
            nodeS* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            nodeS* temp = root->left;
            delete root;
            return temp;
        }
        nodeS* succParent = root;
        nodeS* succ = root->right;
        while (succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }
        root->stu = succ->stu;
        root->right = deleteID(root->right, succ->stu.getID());
    }
    return root;
}
