#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class Tree {
protected:
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

class BST : public Tree {
public:
    void insert(int x);                         
    Node* searchNode(Node* root, int x);                
    Node* deleteNode(Node* root, int x);              
    Node* findMin(Node* root);                   
    Node* findMax(Node* root);                   
    bool isBST(Node* root, int minVal, int maxVal); 
    Node* successor(Node* root, int x);              
    Node* predecessor(Node* root, int x);             
    Node* LCA(Node* root, int a, int b);         
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

void BST::insert(int x) {
    if (this->root == NULL) {
        this->root = createNode(x);
        return;
    }
    Node* curr = this->root;
    Node* parent = NULL;
    while (curr != NULL) {
        parent = curr;
        if (x < curr->data) curr = curr->left;
        else if (x > curr->data) curr = curr->right;
        else return; 
    }
    Node* newNode = createNode(x);
    if (x < parent->data) parent->left = newNode;
    else parent->right = newNode;
}

Node* BST::searchNode(Node* root, int x) {
    Node* curr = root;
    while (curr != NULL) {
        if (x < curr->data) curr = curr->left;
        else if (x > curr->data) curr = curr->right;
        else return curr;
    }
    return NULL;
}

Node* BST::findMin(Node* root) {
    if (root == NULL) return NULL;
    Node* curr = root;
    while (curr->left != NULL) curr = curr->left;
    return curr;
}

Node* BST::findMax(Node* root) {
    if (root == NULL) return NULL;
    Node* curr = root;
    while (curr->right != NULL) curr = curr->right;
    return curr;
}

Node* BST::deleteNode(Node* root, int x) {
    if (root == NULL) return NULL;
    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == NULL) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        } else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

bool BST::isBST(Node* root, int minVal, int maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

Node* BST::successor(Node* root, int x) {
    Node* curr = searchNode(root, x);
    if (curr == NULL) return NULL;
    if (curr->right != NULL) return findMin(curr->right);
    Node* succ = NULL;
    Node* ancestor = this->root;
    while (ancestor != NULL) {
        if (x < ancestor->data) {
            succ = ancestor;
            ancestor = ancestor->left;
        } else if (x > ancestor->data) {
            ancestor = ancestor->right;
        } else break;
    }
    return succ;
}

Node* BST::predecessor(Node* root, int x) {
    Node* curr = searchNode(root, x);
    if (curr == NULL) return NULL;
    if (curr->left != NULL) return findMax(curr->left);
    Node* pred = NULL;
    Node* ancestor = this->root;
    while (ancestor != NULL) {
        if (x < ancestor->data) {
            ancestor = ancestor->left;
        } else if (x > ancestor->data) {
            pred = ancestor;
            ancestor = ancestor->right;
        } else break;
    }
    return pred;
}

Node* BST::LCA(Node* root, int a, int b) {
    Node* curr = root;
    while (curr != NULL) {
        if (a < curr->data && b < curr->data) curr = curr->left;
        else if (a > curr->data && b > curr->data) curr = curr->right;
        else return curr; 
    }
    return NULL;
}

int main() {
    BST tree;
    int choice, x, a, b;
    Node* tmp;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Chen phan tu vao cay\n";
        cout << "2. Duyet NLR (PreOrder)\n";
        cout << "3. Duyet LNR (InOrder)\n";
        cout << "4. Duyet LRN (PostOrder)\n";
        cout << "5. Duyet theo muc (Level Order)\n";
        cout << "6. Tim kiem phan tu\n";
        cout << "7. Xoa phan tu\n";
        cout << "8. Dem so nut\n";
        cout << "9. Dem so la\n";
        cout << "10. Chieu cao cay\n";
        cout << "11. Tong gia tri cac nut\n";
        cout << "12. Tim min / max\n";
        cout << "13. Tim successor / predecessor\n";
        cout << "14. Tim LCA (Lowest Common Ancestor)\n";
        cout << "0. Thoat\n";
        cout << "==========================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can chen: ";
                cin >> x;
                tree.insert(x);
                break;
            case 2:
                cout << "Duyet NLR: ";
                tree.preOder(tree.getRoot());
                cout << endl;
                break;
            case 3:
                cout << "Duyet LNR: ";
                tree.inOder(tree.getRoot());
                cout << endl;
                break;
            case 4:
                cout << "Duyet LRN: ";
                tree.postOder(tree.getRoot());
                cout << endl;
                break;
            case 5:
                cout << "Duyet theo muc: ";
                tree.levelOrder(tree.getRoot());
                cout << endl;
                break;
            case 6:
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                tmp = tree.searchNode(tree.getRoot(), x);
                if (tmp) cout << "Tim thay " << x << endl;
                else cout << "Khong tim thay!\n";
                break;
            case 7:
                cout << "Nhap gia tri can xoa: ";
                cin >> x;
                tree.deleteNode(tree.getRoot(), x);
                cout << "Da xoa!\n";
                break;
            case 8:
                cout << "So nut trong cay: " << tree.countNode(tree.getRoot()) << endl;
                break;
            case 9:
                cout << "So nut la: " << tree.countNodeLeaf(tree.getRoot()) << endl;
                break;
            case 10:
                cout << "Chieu cao cay: " << tree.heightNode(tree.getRoot()) << endl;
                break;
            case 11:
                cout << "Tong gia tri cac nut: " << tree.tong(tree.getRoot()) << endl;
                break;
            case 12:
                cout << "Min: ";
                tmp = tree.findMin(tree.getRoot());
                if (tmp) cout << tmp->data << endl;
                else cout << "Cay rong!\n";
                cout << "Max: ";
                tmp = tree.findMax(tree.getRoot());
                if (tmp) cout << tmp->data << endl;
                else cout << "Cay rong!\n";
                break;
            case 13:
                cout << "Nhap gia tri can tim successor va predecessor: ";
                cin >> x;
                tmp = tree.successor(tree.getRoot(), x);
                if (tmp) cout << "Successor cua " << x << " la: " << tmp->data << endl;
                else cout << "Khong co successor!\n";
                tmp = tree.predecessor(tree.getRoot(), x);
                if (tmp) cout << "Predecessor cua " << x << " la: " << tmp->data << endl;
                else cout << "Khong co predecessor!\n";
                break;
            case 14:
                cout << "Nhap 2 gia tri a, b: ";
                cin >> a >> b;
                tmp = tree.LCA(tree.getRoot(), a, b);
                if (tmp) cout << "LCA cua " << a << " va " << b << " la: " << tmp->data << endl;
                else cout << "Khong tim thay LCA!\n";
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                tree.clearTree(tree.getRoot());
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    tree.clearTree(tree.getRoot());
    return 0;
}
