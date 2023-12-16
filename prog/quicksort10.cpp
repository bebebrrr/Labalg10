#include <iostream>
#include <ctime>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция разбиения массива и перестановки на правильные позиции
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Основна функция Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high);
    }
}

// Функция вывода массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
        cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int arr[] = { 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t now = clock();
    cout << "Массив перед сортировкой:"<<endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Массив после сортировки:"<<endl;
    printArray(arr, n);
    clock_t end = clock();
    double sec = (double)(end - now) / CLOCKS_PER_SEC;
    cout << sec;
}
