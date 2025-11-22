#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class Stack{
	private:
		node *top;
		long size;
	public:
		node *getTop();
		node *getSize();
		node *createNode(int v);
		Stack();
		void push(int v);
		int pop();
		void print();
};
void Stack::print(){
	for(node *i=top;i!=NULL;i=i->next){
		cout<<i->data<<" ";
	}
}
node* Stack::getTop(){
	return top;
}
Stack::Stack(){
	top=NULL;
}

node *Stack::createNode(int v){
	node *p=new node();
	p->next=NULL;
	p->data=v;
	return p;
}
void Stack::push(int v){
	node *p=createNode(v);
	if(p==NULL)
	return;
	else if(top==NULL)top=p;
	else{
		p->next=top;
		top=p;
	}
	size++;
}

int Stack::pop(){

	node*temp=top;
	int data=temp->data;
	top=top->next;
	size--;
	delete temp;
	return data;
}

void chuyenHeDem(int v){
	int r=0;//Phan du
	Stack s;
	do{
		r=v%2;
		s.push(r);
		v=v/2;
		
	}while(v!=0);
	s.print();
}

int main(){
	chuyenHeDem(11);
}

