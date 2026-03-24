//
// Created by Sydney Vargo on 3/23/26.
//

#include "QuickSort.h"
#include <algorithm>

void quickSort(std::vector<int> listings, int low, int high) {
    if (low < high) {
        int pivot = partition(listings, low, high);
        quickSort(listings, low, pivot-1);
        quickSort(listings, pivot+1, high);
    }
}

int partition(std::vector<int> listings, int low, int high) {
    int pivot = listings[low];
    int up = low;
    int down = high;

    while (up < down) {
        for (int i = up; i < high; i++) {
            if (listings[up] > pivot) {
                break;
            }
            up += 1;
        }

        for (int i = high; i > low; i--) {
            if (listings[down] < pivot) {
                break;
            }
            down -= 1;
        }

        if (up < down) {
            realEstate temp = listings[up];
            listings[up] = listings[down];
            listings[down] = temp;
        }
    }

    realEstate temp = listings[low];
    listings[low] = listings[down];
    listings[down] = temp;

    return down;
}
