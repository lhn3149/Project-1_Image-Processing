//
// Created by nguye on 3/10/2021.
//

//
#include "SelectionSort.h"


bool descending(const int a, const int b){
    return a < b;
}



bool ascending(const int a, const int b){
    return a >= b;
}

void swapValues( int* a, int* b){
    int temp = *b ;
    *b = *a ;
    *a = temp;
}

void selectionSort(int* const numbers, const int n, bool (*order)(const int, const int) ){
    for (int i = 0; i < n-1; i++) {
        /* find the min element in the unsorted a[i .. aLength-1] */

        /* assume the min is the first element */
        int jMin = i;
        /* test against elements after i to find the smallest */
        for (int j = i + 1; j < n; j++) {
            /* if this element is less, then it is the new minimum */
            if ((*order)(numbers[jMin],numbers[j]) == 1) {
                jMin = j;
            }
        }

        if (jMin != i) {
            swapValues(&(numbers[jMin]), &numbers[i]);
        }
    }
}