//
// Created by Sydney Vargo on 3/23/26.
//

#include "QuickSort.h"
#include <algorithm>

double sortGetter(const realEstate& h, int sortType);

// referenced quick sort logic & code from in person lecture notes

// quick sort function 
void quickSort(std::vector<int> listings, int low, int high, int sortType) {
    if (low < high) {
        int pivot = partition(listings, low, high);
        quickSort(listings, low, pivot-1, sortType);
        quickSort(listings, pivot+1, high, sortType);
    }
}

// partition for quick sort
int partition(std::vector<int> listings, int low, int high, int sortType) {
    int pivot = sortGetter(listings[low], sortType); 
    int up = low;
    int down = high;
    int upValue = sortGetter(listings[low], sortType);
    int downValue = sortGetter(listings[high], sortType);

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (upValue > pivot) {
                break;
            }
            up += 1;
        }

        for (int i = high; i > low; i--) {
            if (downValue < pivot) {
                break;
            }
            down -= 1;
        }

        if (up < down) {
            auto temp = upValue;
            upValue = downValue;
            downValue = temp;
        }
    }

    auto temp = upValue;
    upValue = downValue;
    downValue = temp;

    return down;
}
