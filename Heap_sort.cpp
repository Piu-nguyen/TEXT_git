#include <iostream>
using namespace std;

// Struct mô phỏng nút cây (tùy chọn, không dùng trực tiếp trong heap dạng mảng)
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val);
};
Node::Node(int val):value(val),left(nullptr),right(nullptr){};


// Class Heap dùng mảng động
class Heap {
private:
    int* arr;     // Mảng động
    int capacity; // Sức chứa tối đa
    int size;     // Số lượng phần tử hiện có
   
public:
    Heap(int cap);            // Constructor
    ~Heap();                  // Destructor
    void insert(int val);     // Thêm phần tử
    void heapSort();          // Sắp xếp heap
    void printHeap() const;   // In heap
    void printSorted() const; // In mảng đã sắp xếp
};
// Constructor
Heap::Heap(int cap) {
    capacity = cap;
    size = 0;
    arr = new int[capacity];
}

// Destructor
Heap::~Heap() {
    delete[] arr;
}

// Hàm thêm phần tử vào heap
void Heap::insert(int val) {
    if (size == capacity) {
        cout << "Heap đầy, không thể thêm phần tử.\n";
        return;
    }

    arr[size] = val;
    int i = size;
    size++;

    // Sắp xếp lại heap từ dưới lên
    while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Hàm heapify tại vị trí i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm sắp xếp heap
void Heap::heapSort() {
    // Xây dựng max heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // Trích xuất từng phần tử
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// In heap dạng mảng
void Heap::printHeap() const {
    cout << "Heap dang mang: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// In mảng đã sắp xếp
void Heap::printSorted() const {
    cout << "Mang sau khi Heap Sort: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Hàm main
int main() {
    Heap h(20); // Khởi tạo heap với sức chứa tối đa 20 phần tử

    h.insert(40);
    h.insert(10);
    h.insert(30);
    h.insert(50);
    h.insert(20);
    h.insert(60);

    h.printHeap();

    h.heapSort();
    h.printSorted();

    return 0;
}