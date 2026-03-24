//
// Created by Nicole Greenberg on 3/23/26.
//
#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include "DataLoader.h"
using namespace std;

void mergeSort(vector<realEstate>& listings, int leftIndex, int rightIndex, int sortType);
void merge(vector<realEstate>& listings, int leftIndex, int midIndex, int rightIndex, int sortType);

#endif //MERGESORT_H
