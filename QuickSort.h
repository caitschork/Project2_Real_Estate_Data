//
// Created by Sydney Vargo on 3/23/26.
//
#include <vector>
#include "DataLoader.h"

#ifndef QUICKSORT_H
#define QUICKSORT_H

// define quick sort functions
void quickSort(std::vector<realEstate> listings, int low, int high, int sortType);
int partition(std::vector<realEstate> listings, int low, int high, int sortType);

#endif //QUICKSORT_H
