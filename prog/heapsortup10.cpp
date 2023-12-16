#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция для построения кучи (heapify)
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

// Основная функция, которая выполняет сортировку кучей
void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
        cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<int> arr = { 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 12, 11, 13, 5, 6, 7, 9, 4, 2, 0, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t now = clock();
    cout << "Массив до сортировки: "<<endl;
    printArray(arr);

    heapSort(arr);

    cout << "Массив после сортировки: " << endl;
    printArray(arr);
    clock_t end = clock();
    double sec = (double)(end - now) / CLOCKS_PER_SEC;
    cout << sec;
}