//
// Created by Caitriona Schork on 3/22/26.
//
#include "HeapSort.h"
#include <algorithm>

double sortGetter(const realEstate& h, int sortType) {
  if (sortType == 1)
    return h.price;

  else if (sortType == 2)
    return h.house_size;

  else if (sortType == 3)
    return h.beds;

  else if (sortType == 4)
    return h.baths;

  else if (sortType == 5)
    return h.acre_lot;

  else //sorts by price as default
    return h.price;
}

void heapify(std::vector<realEstate>& arr, int n, int i, int sortType) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && sortGetter(arr[left], sortType) > sortGetter(arr[largest], sortType)) {
        largest = left;
    }

    if (right < n && sortGetter(arr[right], sortType) > sortGetter(arr[largest], sortType)) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest, sortType);
    }
}

void buildHeap(std::vector<realEstate>& arr, int n, int sortType) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, sortType);
    }
}

void heapSort(std::vector<realEstate>& arr, int sortType) {
    int n = arr.size();
    buildHeap(arr, n, sortType);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0, sortType);
    }
}