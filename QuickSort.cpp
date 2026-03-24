//
// Created by Sydney Vargo on 3/23/26.
//
#include "QuickSort.h"
#include <algorithm>
// referenced quick sort logic & code from in person lecture notes
double sortGetter(const realEstate& h, int sortType);

// partition for quick sort
int partition(vector<realEstate>& listings, int low, int high, int sortType) {
    int pivot = sortGetter(listings[low], sortType); 
    int up = low;
    int down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (sortGetter(listings[up], sortType) > pivot) {
                break;
            }
            up += 1;
        }

        for (int i = high; i > low; i--) {
            if (sortGetter(listings[down], sortType) <= pivot) {
                break;
            }
            down -= 1;
        }

        if (up < down) {
            swap(listings[up], listings[down]);
        }
    }
    //swap pivot into correct position
    swap(listings[low], listings[down]);

    return down;
}


// quick sort function
void quickSort(vector<realEstate>& listings, int low, int high, int sortType) {
    if (low < high) {
        int pivot = partition(listings, low, high, sortType);
        quickSort(listings, low, pivot - 1, sortType);
        quickSort(listings, pivot + 1, high, sortType);
    }
}