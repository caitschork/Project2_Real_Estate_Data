//
// Created by Caitriona Schork on 3/22/26.
//

#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <vector>
#include "DataLoader.h"

void heapify(std::vector<realEstate>& arr, int n, int i, int sortType);
void buildHeap(std::vector<realEstate>& arr, int sortType);
void heapSort(std::vector<realEstate>& arr, int sortType);

#endif //HEAPSORT_H
