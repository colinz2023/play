//
// Created by colin on 2018/11/13.
//

#ifndef PROJECT_SORT_IMP_H
#define PROJECT_SORT_IMP_H

#include <cctype>
#include <algorithm>


template<typename T>
void InsertionSort2(T arr[], size_t n) {

    for (size_t i = 1; i < n; i++) {
        for (size_t j = i; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                std::swap(arr[j], arr[j-1]);
            } else {
                break;
            }
        }
    }
}

template<typename T>
void InsertionSort(T arr[], size_t n) {

    for (size_t i = 1; i < n; i++) {
        T e = arr[i];
        size_t j;
        for (j = i; j > 0 && arr[j - 1] > e; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}



#endif //PROJECT_SORT_IMP_H
