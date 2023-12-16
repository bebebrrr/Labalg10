#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> mergeSortedArrays(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    vector<int> C(n * n);

    int i = 0, j = 0, k = 0;
    while (k < n * n) {
        int sum = A[i] + B[j];
        C[k] = sum;
        k++;

        if (i < n - 1) {
            i++;
        }
        else if (j < n - 1) {
            j++;
        }
        else {
            break;
        }
    }

    return C;
}

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите размер массивов: ";
    cin >> n;

    vector<int> A(n), B(n);
    cout << "Введите элементы массива A: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B: ";
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    // Сортируем массивы A и B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Получаем отсортированный массив сумм
    vector<int> sortedSums = mergeSortedArrays(A, B);

    cout << "Отсортированные суммы A[i] + B[j]: ";
    for (int i = 0; i < sortedSums.size(); i++) {
        cout << sortedSums[i] << " ";
    }
    cout << endl;

    return 0;
}