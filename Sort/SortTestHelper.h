//
// Created by none on 19-4-21.
//

#ifndef SORT_SORT_TEST_HELPER_H
#define SORT_SORT_TEST_HELPER_H

#include <ctime>
#include <assert.h>
#include <stdlib.h>

using namespace std;

namespace SortTestHelper {

    // 随机生成[rangeL, rangeR]
    int *generateRandomArray(int num, int rangeL, int rangeR) {
        assert(rangeR > rangeL);
        int *array = new int[num];
        srand(time(nullptr));
        for (int i = 0; i < num; ++i) {
            array[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return array;
    }

    int *generateNearlyOrderedArray(int num, int swapTimes) {
        int *arr = new int[num];
        for (int i = 0; i < num; ++i) {
            arr[i] = i;
        }
        for (int j = 0; j < swapTimes; ++j) {
            int posX = rand() % num;
            int posY = rand() % num;
            swap(arr[posX], arr[posY]);
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            return !(arr[i] > arr[i + 1]);
        }
    }

    template<typename T>
    void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << ":" << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
    }

    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }
}
#endif //SORT_SORT_TEST_HELPER_H
