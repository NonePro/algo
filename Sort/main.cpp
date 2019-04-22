#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void selectionSort1(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

template<typename T>
void insertionSortV1(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

template<typename T>
void bubbleSortDoubleCircle(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T>
void bubbleSortOuterDoWhileSwapped(T arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        // 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
        // 所以下一次排序, 最后的元素可以不再考虑
        n--;
    } while (swapped);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T>
void bubbleSortOuterDoWhileNewN(T arr[], int n) {
    int newN;
    do {
        newN = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                newN = i;
            }
        }
        // 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
        // 所以下一次排序, 最后的元素可以不再考虑
        n--;
    } while (newN > 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {

    // int a[10] = {10, 5, 8, 7, 6, 9, 4, 3, 2, 1};
    // bubbleSortOuterDoWhileNewN(a, 10);
    // SortTestHelper::printArray(a, 10);
    // return 0;

    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    // int *arr = SortTestHelper::generateNearlyOrderedArray(n, 30);

    int *insertionArr = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, insertionArr, n);
    delete[] insertionArr;

    int *bubbleArr1 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Bubble Sort Double Circle", bubbleSortDoubleCircle, bubbleArr1, n);
    delete[] bubbleArr1;

    int *bubbleArr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Bubble Sort Outer While Swapped", bubbleSortOuterDoWhileSwapped, bubbleArr2, n);
    delete[] bubbleArr2;

    int *bubbleArr3 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Bubble Sort Outer While NewN", bubbleSortOuterDoWhileNewN, bubbleArr3, n);
    delete[] bubbleArr3;

    int *selectionArr = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, selectionArr, n);
    delete[] selectionArr;

    delete[] arr;

    float b[4] = {10.98, 9.456, 0.357, 7.8};
    selectionSort(b, 4);
    for (float i : b) {
        cout << i << " ";
    }
    cout << endl;

    string c[4] = {"E", "A", "G", "K"};
    selectionSort(c, 4);
    for (const auto &i : c) {
        cout << i << " ";
    }
    cout << endl;

    Student studentC = Student("C", 80);
    Student studentD = Student("D", 90);
    Student studentF = Student("F", 30);
    Student studentK = Student("K", 100);
    Student d[4] = {studentC, studentD, studentF, studentK};
    selectionSort(d, 4);
    for (const auto &i : d) {
        cout << i;
    }
    cout << endl;
    return 0;
}