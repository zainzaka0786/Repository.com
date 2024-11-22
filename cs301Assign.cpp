#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    int label; 
    BinarySearchTree* left;  
    BinarySearchTree* right; 

public:
    BinarySearchTree() : label(0), left(nullptr), right(nullptr) {}

    BinarySearchTree(int lbl) : label(lbl), left(nullptr), right(nullptr) {}

    void setLabel(int lbl) { label = lbl; }
    void setLeft(BinarySearchTree* l) { left = l; }
    void setRight(BinarySearchTree* r) { right = r; }

    int getLabel() { return label; }
    BinarySearchTree* getLeft() { return left; }
    BinarySearchTree* getRight() { return right; }

    bool isLeaf() {
        return left == nullptr && right == nullptr;
    }

    void insert(BinarySearchTree*& root, int lbl) {
        if (lbl == 0) {
            cout << "Zero is not allowed, skipping insertion." << endl;
            return; // Zero is not allowed
        }

        if (root == nullptr) {
            root = new BinarySearchTree(lbl);
            cout << "Inserted " << lbl << " successfully." << endl;
        } else if (lbl < root->label) {
            insert(root->left, lbl);
        } else if (lbl > root->label) {
            insert(root->right, lbl);
        } else {
            cout << lbl << " is a duplicate in this binary search tree (BST) , so ,cannot be inserted" << endl;
        }
    }

    void display(BinarySearchTree* root) {
        if (root != nullptr) {
            display(root->left);
            cout << root->label << " ";
            display(root->right);
        }
    }
};

int main() {
    BinarySearchTree* root = nullptr;
    int numId = 2344; // Derived from VU Student ID: BC230407844
    cout << "VU Student ID digits merged (numId): " << numId << endl;
    while (numId > 0) {
        int digit = numId % 10;
        numId /= 10;            
        if (root == nullptr) {
            root = new BinarySearchTree(digit);
            cout << "Inserted " << digit << " successfully." << endl;
        } else {
            root->insert(root, digit);
        }
    }

    cout << "Tree elements in in-order traversal: ";
    root->display(root);
    cout << endl;

    return 0;
}
