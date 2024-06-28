#include "book.h"
#include<iostream>
using namespace std;

book::book(int id, string name, int q) : bookID(id), bookName(name), quantity(q), issuedSt(new bst_student()) {
    present = (q > 0);
}

int book::getID() {
    return bookID;
}

string book::getBookName() {
    return bookName;
}

bool book::isPresent() {
    return present;
}

void book::updateAvailablity() {
    present = (quantity > 0);
}

void book::issueBook(student s) {
    if (quantity > 0) {
        issuedSt->root = issuedSt->insertID(issuedSt->root, s);
        --quantity;
        updateAvailablity();
        cout << "Book Issued" << endl;
    } else {
        cout << "NOT AVAILABLE!!";
    }
}

void book::returnBook(student s) {
    ++quantity;
    issuedSt->root = issuedSt->deleteID(issuedSt->root, s.getID());
    updateAvailablity();
    cout << "Return Successful!" << endl;
}

nodeB::nodeB(book b) : bk(b), right(nullptr), left(nullptr) {}

bst_book::bst_book() : root(nullptr) {}

nodeB* bst_book::insertBook(nodeB* root, book s) {
    if (root == nullptr) {
        return new nodeB(s);
    }
    if (root->bk.getID() < s.getID()) {
        root->right = insertBook(root->right, s);
    } else {
        root->left = insertBook(root->left, s);
    }
    return root;
}

nodeB* bst_book::searchID(nodeB* root, int id) {
    if (root == nullptr || root->bk.getID() == id) {
        return root;
    }
    if (root->bk.getID() > id) {
        return searchID(root->left, id);
    } else {
        return searchID(root->right, id);
    }
}

nodeB* bst_book::deleteID(nodeB* root, int targetID) {
    if (root == nullptr) {
        return root;
    }

    if (targetID < root->bk.getID()) {
        root->left = deleteID(root->left, targetID);
    } else if (targetID > root->bk.getID()) {
        root->right = deleteID(root->right, targetID);
    } else {
        if (root->left == nullptr) {
            nodeB* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            nodeB* temp = root->left;
            delete root;
            return temp;
        }
        nodeB* succParent = root;
        nodeB* succ = root->right;
        while (succ->left != nullptr) {
            succParent = succ;
            succ = succ->left;
        }
        root->bk = succ->bk;
        root->right = deleteID(root->right, succ->bk.getID());
    }
    return root;
}
