#include <iostream>
#include <ctime> // dung cho ham rand()
using namespace std;

// hoare
// lomuto
// pivot

int partition(int a[], int left, int right){
	int pivot = a[right]; // la phan tu o ngoai cung goi la chot 
	int i = left -1;
	for(int j = left; j < right; j++){
		if(a[j] <= pivot){
			++i;
			swap(a[i], a[j]); 
		} 
	}
	// dua chot ve giua
	++i;
	swap(a[i], a[right]);
	return i; // vi tri cua chot 
}

void quickSort(int a[], int left, int right){
	if(left >= right) return; // khi chi con lai 1 phan tu hoac rong. 
	int p = partition(a, left, right);
	quickSort(a, left, p-1);
	quickSort(a, p+1, right); 
} 

int main(){
	int x[1000];
	int n;
	cin>>n;
	//srand(time(NULL)); 
	for(int i = 0; i < n; i++){
		//x[i] = rand() % 1000;
		cin>>x[i]; 
	} 
	quickSort(x, 0, n-1);
	
	for(int i = 0; i < n; i++){
		cout<< x[i] << " "; 
	} 
	
	return 0; 
} 
