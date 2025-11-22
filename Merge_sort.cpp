#include <iostream>
#include <vector>
using namespace std;

// Ham gop hai mang da duoc sap xep
void merge(vector<int>& arr, int left, int mid, int right) {
    // Tinh kich thuoc hai nua mang
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Cap phat dong hai mang tam
    int* L = new int[n1];
    int* R = new int[n2];

    // Sao chep du lieu tu mang chinh sang mang tam
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Khoi tao chi so de duyet
    int i = 0, j = 0, k = left;

    // So sanh va gop hai mang tam vao mang chinh
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Sao chep phan con lai cua mang L neu co
    while (i < n1)
        arr[k++] = L[i++];

    // Sao chep phan con lai cua mang R neu co
    while (j < n2)
        arr[k++] = R[j++];

    // Giai phong bo nho da cap phat
    delete[] L;
    delete[] R;
}

// Ham sap xep bang merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    // Dieu kien dung khi mang chi con 1 phan tu
    if (left < right) {
        // Tinh chi so giua de chia mang
        int mid = left + (right - left) / 2;

        // Goi de quy sap xep tung nua
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gop hai nua da sap xep
        merge(arr, left, mid, right);
    }
}

// Ham chinh de kiem tra chuong trinh
int main() {
    int temp[] = {38, 42, 3, 8, 92, 10};
    int n = sizeof(temp) / sizeof(temp[0]);
    
    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) cout << temp[i] << " ";
    cout << endl;

    // Tao vector tu mang temp
    vector<int> arr(temp, temp + n);

    // Goi ham sap xep
    mergeSort(arr, 0, arr.size() - 1);

    // In ket qua ra man hinh
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
