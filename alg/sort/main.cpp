//
// Created by colin on 2018/11/13.
//


#include <iostream>
#include "clock_time.h"
#include "sort_test_helper.h"
#include "sort_imp.h"

using namespace sort_test_helper;


int main() {
    size_t N = 10000;

    int *array = GetRandomNumArray(N, 10, N + 99999);

    PrintArrary(array, 10);

    //SortTestRun<int>(InsertionSort<int>, array, N, "插入排序");

    TestSort(InsertionSort, CopyArray(array, N), N, "插入排序");
    TestSort(InsertionSort2, CopyArray(array, N), N, "插入排序2");
    TestSort(QuickSort, CopyArray(array, N), N, "快速排序");

    //PrintArrary(array, 10);
}
