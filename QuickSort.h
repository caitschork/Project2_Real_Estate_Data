//
// Created by Sydney Vargo on 3/23/26.
//
#include <vector>
#include "DataLoader.h"
using namespace std;

#ifndef QUICKSORT_H
#define QUICKSORT_H

// define quick sort functions
void quickSort(vector<realEstate>& listings, int low, int high, int sortType);
int partition(vector<realEstate>& listings, int low, int high, int sortType);

#endif //QUICKSORT_H
