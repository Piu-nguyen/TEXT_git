#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    Node *next;
}Node;
class List{
    public:
        Node *head;
        int size;
        Node *tail;
        List();//khoi tao mac dinh
        void addFirst(int n);
        Node *createNode(int n);
        void removeFirst();
        void print();
        void addLast(int n);
		void removeLast();
		void addAt(int pos, int n);
		void removeAt(int pos);

};
void List::print(){
    for(Node *i=head;i!=NULL;i=i->next)
        cout<<i->data<<" ";
}
List::List(){
    head=tail=NULL;
    size=0;
}
Node* List::createNode(int n){
    Node *p = new Node();
    p->data=n;
    p->next=NULL;
    return p;
}
void List::addFirst(int n){
    Node *p = createNode(n);
    if(p==NULL)
        return;
    else if(head==NULL){
        head=tail=p;
    }
    else{
        p->next=head;
        head=p;
    }
    size++;
}
//xoa dau
void List::removeFirst(){
    if(head==NULL)
        return;
    else if(head->next==NULL){
        Node *p=head;
        head=tail=NULL;
        delete p;
        size--;
    }
    else{
        Node *p=head;
        head=head->next;
        delete(p);
        size--;
    }
}
void List::addLast(int n) {
    Node *p=createNode(n);
    if (head==NULL) {
        head=tail=p;
    } else {
        tail->next=p;
        tail=p;
    }
    size++;
}

void List::removeLast() {
    if (head==NULL) return;
    if (head->next==NULL) {
        delete head;
        head=tail=NULL;
    } else {
        Node *prev=NULL;
        Node *curr=head;
        while (curr->next!=NULL) {
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        tail=prev;
        delete curr;
    }
    size--;
}

void List::addAt(int pos, int n) {
    if (pos < 0 || pos > size) return;
    if (pos==0) {
        addFirst(n);
    } else if (pos==size) {
        addLast(n);
    } else {
        Node *p=createNode(n);
        Node *curr=head;
        for (int i=0; i<pos-1; i++) {
            curr=curr->next;
        }
        p->next=curr->next;
        curr->next=p;
        size++;
    }
}

void List::removeAt(int pos) {
    if (pos<0 || pos >= size) return;
    if (pos==0) {
        removeFirst();
    } else if (pos==size - 1) {
        removeLast();
    } else {
        Node *prev=head;
        for (int i=0; i < pos - 1; i++) {
            prev = prev->next;
        }
        Node *del=prev->next;
        prev->next=del->next;
        delete del;
        size--;
    }
}
int main(){
	List list;
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	list.addFirst(n);
	list.addFirst(10);
	list.addFirst(15);
	list.print();
	cout<<endl; 
	list.addLast(20); 
	list.print();
	cout<<endl; 
	list.addAt(2, 99);   
	list.print();  
	cout<<endl;  
	list.removeAt(2);   
	list.print(); 
	cout<<endl;    
	list.removeLast();  
	list.print();    
	return 0; 
}

