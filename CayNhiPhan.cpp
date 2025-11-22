#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Tree {
private:
    long size;
    Node *root;
public:
    Tree();
    Node *getRoot();
    Node *createNode(int n);
    void insertLeft(Node *p, int n);
    void insertRight(Node *p, int n);
    void preOder(Node *root);
    void inOder(Node *root);
    void postOder(Node *root);
    int heightNode(Node *root);
    void printLevel(Node *root, int level);
    void levelOrder(Node *root);
    int countNode(Node *root);
    bool isEmpty();
    int countNodeLeaf(Node *root);
    int findLevel(Node *root, int x, int level);
    int tong(Node *root);
    void clearTree(Node *root);
    
};
Tree::Tree() {
    root = NULL;
    size = 0;
}

Node* Tree::getRoot() {
    return root;
}

Node* Tree::createNode(int n) {
    Node *p = new Node;
    p->data = n;
    p->left = NULL;
    p->right = NULL;
    if (root == NULL) root = p; 
    size++;
    return p;
}

void Tree::insertLeft(Node *p, int n) {
    if (isEmpty()) {
        cout << "Cay rong, khong the chen trai!\n";
        return;
    }
    if (p != NULL && p->left == NULL) p->left = createNode(n);
}

void Tree::insertRight(Node *p, int n) {
    if (isEmpty()) {
        cout << "Cay rong, khong the chen phai!\n";
        return;
    }
    if (p != NULL && p->right == NULL) p->right = createNode(n);
}

void Tree::preOder(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOder(root->left);
    preOder(root->right);
}

void Tree::inOder(Node *root) {
    if (root == NULL) return;
    inOder(root->left);
    cout << root->data << " ";
    inOder(root->right);
}

void Tree::postOder(Node *root) {
    if (root == NULL) return;
    postOder(root->left);
    postOder(root->right);
    cout << root->data << " ";
}

int Tree::heightNode(Node *root) {
    if (root == NULL) return 0;
    int hl = heightNode(root->left);
    int hr = heightNode(root->right);
    return (hl > hr ? hl : hr) + 1;
}

void Tree::printLevel(Node *root, int level) {
    if (root == NULL) return;
    if (level == 1) cout << root->data << " ";
    else {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

void Tree::levelOrder(Node *root) {
    if (isEmpty()) {
        cout << "Cay rong!\n";
        return;
    }
    int h = heightNode(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
}

int Tree::countNode(Node *root) {
    if (root == NULL) return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}

bool Tree::isEmpty() {
    return root == NULL;
}

int Tree::countNodeLeaf(Node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countNodeLeaf(root->left) + countNodeLeaf(root->right);
}

int Tree::findLevel(Node *root, int x, int level) {
    if (root == NULL) return -1;
    if (root->data == x) return level;
    int l = findLevel(root->left, x, level+1);
    if (l != -1) return l;
    return findLevel(root->right, x, level+1);
}

int Tree::tong(Node *root) {
    if (root == NULL) return 0;
    return root->data + tong(root->left) + tong(root->right);
}

void Tree::clearTree(Node *root) {
    if (root == NULL) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

int main() {
    Tree t;
    Node *r = t.createNode(10);
    r->left = t.createNode(5);
    r->right = t.createNode(20);
    r->left->left = t.createNode(3);
    r->left->right = t.createNode(7);
    r->right->left = t.createNode(15);
    r->right->right = t.createNode(30);

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Duyet NLR (PreOrder)\n";
        cout << "2. Duyet LNR (InOrder)\n";
        cout << "3. Duyet LRN (PostOrder)\n";
        cout << "4. Duyet theo muc (LevelOrder)\n";
        cout << "5. Dem so nut\n";
        cout << "6. Dem so nut la\n";
        cout << "7. Chieu cao cay\n";
        cout << "8. Tong gia tri cac nut\n";
        cout << "0. Thoat\n";
        cout << "================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "PreOrder: ";
                t.preOder(t.getRoot()); cout << endl;
                break;
            case 2:
                cout << "InOrder: ";
                t.inOder(t.getRoot()); cout << endl;
                break;
            case 3:
                cout << "PostOrder: ";
                t.postOder(t.getRoot()); cout << endl;
                break;
            case 4:
                cout << "LevelOrder: ";
                t.levelOrder(t.getRoot()); cout << endl;
                break;
            case 5:
                cout << "So nut: " << t.countNode(t.getRoot()) << endl;
                break;
            case 6:
                cout << "So nut la: " << t.countNodeLeaf(t.getRoot()) << endl;
                break;
            case 7:
                cout << "Chieu cao cay: " << t.heightNode(t.getRoot()) << endl;
                break;
            case 8:
                cout << "Tong gia tri cac nut: " << t.tong(t.getRoot()) << endl;
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while(choice != 0);

    return 0;
}
