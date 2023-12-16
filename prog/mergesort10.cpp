﻿#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Слияние двух отсортированных подмассивов
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Рекурсивная функция сортировки слиянием
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int main() {
    vector<int> arr = { 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 9, 5, 1, 3, 10, 4, 2, 8, 6, 7, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2, 10, 7, 8, 9, 1, 5, 8, 2, 4, 1, 6, 9, 2, 4, 8, 0, 1, 9, 5, 2 };
    clock_t now = clock();
    mergeSort(arr, 0, arr.size() - 1);

    for (int num : arr) {
        cout << num << " ";
    }

    clock_t end = clock();
    double sec = (double)(end - now) / CLOCKS_PER_SEC;
    cout << endl<< sec;
}
