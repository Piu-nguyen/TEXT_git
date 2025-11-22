//Chuong trinh C/C++ cho danh sach lien ket don quan li sanh sach so nguyen
//			+Them (dau, cuoi, bat ki)
//			+Xoa (dau, cuoi, bat ki)
//			+Tim kiem 
//			+Sap xep 
//			+Dung menu quan li 

#include<iostream>
using namespace std;

typedef struct SoNguyen{
	int data;
	SoNguyen *prev;
	SoNguyen *next;
}SoNguyen;

class List{
private:
	int size;
	SoNguyen *head;
	SoNguyen *tail;
public:
	List();
	~List();
	SoNguyen *createSN(int data);
	int getSize();
	bool isEmpty();
	void xuat();
	void addF(int data);
	void addL(int data);
	void addA(int data,int pos);
	void removeF();
	void removeL();
	void removeA(int pos);
	void sapXep();
	void search(int data);
};

List::List(){
	size=0;
	head=tail=NULL;
}

SoNguyen *List::createSN(int data){
	SoNguyen *node=new SoNguyen;
	node->data=data;
	node->prev=node->next=NULL;
	return node;
}

bool List::isEmpty(){
	return head==NULL;
}

int List::getSize(){
	return size;
}

void List::addF(int data){
	SoNguyen *node=createSN(data);
	if(!head){
		head=tail=node;
	}else{
		node->next=head;
		head->prev=node;
		head=node;
	}
	size++;
}

void List::addL(int data){
	SoNguyen *node=createSN(data);
	if(!head){
		head=tail=node;
	}else{
		tail->next=node;
		node->prev=tail;
		tail=node;
	}
	size++;
}

void List::addA(int data,int pos){
	if(pos<=0){
		addF(data);
	}else if(pos>=size){
		addL(data);
	}else{
		SoNguyen *node=createSN(data);
		SoNguyen *temp=head;
		for(int i=0;i<pos;i++){
			temp=temp->next;
		}
		node->next=temp;
		node->prev=temp->prev;
		if(temp->prev) temp->prev->next=node;
		temp->prev=node;
		if(pos==1) head=node;
		size++;
	}
}

void List::removeF(){
	if(!head) return;
	SoNguyen *temp=head;
	if(head==tail){
		head=tail=NULL;
	}else{
		head=head->next;
		head->prev=NULL;
	}
	delete temp;
	size--;
}

void List::removeL(){
	if(!tail) return;
	SoNguyen *temp=tail;
	if(head==tail){
		head=tail=NULL;
	}else{
		tail=tail->prev;
		tail->next=NULL;
	}
	delete temp;
	size--;
}

void List::removeA(int pos){
	if(pos<=0){
		removeF();
	}else if(pos>=size-1){
		removeL();
	}else{
		SoNguyen *temp=head;
		for(int i=0;i<pos;i++){
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
		size--;
	}
}

void List::xuat(){
	SoNguyen *temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void List::search(int data){
	SoNguyen *temp=head;
	int pos=0;
	bool found=false;
	cout<<"Vi tri xuat hien cua "<<data<<": ";
	while(temp){
		if(temp->data==data){
			cout<<pos<<" ";
			found=true;
		}
		temp=temp->next;
		pos++;
	}
	if(!found) cout<<"Khong tim thay!";
	cout<<endl;
}

void List::sapXep(){
	for(SoNguyen *i=head;i!=NULL;i=i->next){
		for(SoNguyen *j=i->next;j!=NULL;j=j->next){
			if(i->data>j->data){
				int temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
}

List::~List(){
	while(head){
		SoNguyen *temp=head;
		head=head->next;
		delete temp;
	}
	tail=NULL;
	size=0;
}

int main(){
	List list;
	int choice,data,pos;
	do{
		cout<<"---------------MENU------------------\n";
		cout<<"1. Them so nguyen vao dau danh sach.\n";
		cout<<"2. Them so nguyen vao cuoi danh sach.\n";
		cout<<"3. Them so nguyen vao giua danh sach.\n";
		cout<<"4. Xoa so nguyen dau danh sach.\n";
		cout<<"5. Xoa so nguyen cuoi danh sach.\n";
		cout<<"6. Xoa so nguyen giua danh sach.\n";
		cout<<"7. Xuat danh sach.\n";
		cout<<"8. Tim so nguyen trong danh sach.\n";
		cout<<"9. Sap xep so nguyen trong danh sach.\n";
		cout<<"0. Thoat.\n";
		cout<<"Nhap lua chon: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Nhap so nguyen: ";
				cin>>data;
				list.addF(data);
				break;
			case 2:
				cout<<"Nhap so nguyen: ";
				cin>>data;
				list.addL(data);
				break;
			case 3:
				cout<<"Nhap so nguyen: ";
				cin>>data;
				do{
					cout<<"Nhap vi tri chen (0 den "<<list.getSize()<<"): ";
					cin>>pos;
				}while(pos<0||pos>list.getSize());
				list.addA(data,pos);
				break;
			case 4:
				if(list.isEmpty()){
					cout<<"Danh sach rong. Khong the xoa!\n";
				}else{
					list.removeF();
					cout<<"Da xoa phan tu dau.\n";
				}
				break;
			case 5:
				if(list.isEmpty()){
					cout<<"Danh sach rong. Khong the xoa!\n";
				}else{
					list.removeL();
					cout<<"Da xoa phan tu cuoi.\n";
				}
				break;
			case 6:
				if(list.isEmpty()){
					cout<<"Danh sach rong. Khong the xoa!\n";
					break;
				}
				do{
					cout<<"Nhap vi tri can xoa (0 den "<<list.getSize()-1<<"): ";
					cin>>pos;
				}while(pos<0||pos>=list.getSize());
				list.removeA(pos);
				cout<<"Da xoa phan tu tai vi tri "<<pos<<".\n";
				break;
			case 7:
				if(list.isEmpty()){
					cout<<"Danh sach rong.\n";
				}else{
					list.xuat();
				}
				break;
			case 8:
				if(list.isEmpty()){
					cout<<"Danh sach rong. Khong the tim kiem!\n";
				}else{
					cout<<"Nhap so nguyen can tim: ";
					cin>>data;
					list.search(data);
				}
				break;
			case 9:
				if(list.isEmpty()){
					cout<<"Danh sach rong. Khong the sap xep!\n";
				}else{
					list.sapXep();
					cout<<"Da sap xep danh sach.\n";
				}
				break;
			case 0:
				cout<<"Tam biet.......T_T...\n";
				break;
			default:
				cout<<"Lua chon khong hop le. Vui long nhap lai!\n";
				break;
		}
	}while(choice!=0);
	return 0;
}
