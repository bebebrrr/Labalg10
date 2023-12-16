#include <iostream>
#include <ctime>
using namespace std;

// Вспомогательная функция для обмена элементами
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция построения на heap
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2; 

    // Если левый элемент больше
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый элемент больше
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если самый большой элемент не является корнем
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }
}

// Главнаz функция для hepsort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
        cout << "\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    int arr[] = { 1, 8, 3, 1, 2, 7, 7, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t now = clock();
    cout << "Масcив перед сортировкой: \n";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Массив после сортировки: \n";
    printArray(arr, n);
    clock_t end = clock();
    double sec = (double)(end - now) / CLOCKS_PER_SEC;
    cout << sec;
}