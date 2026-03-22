//
// Created by Caitriona Schork on 3/22/26.
//

#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <vector>
#include "DataLoader.h"

/*
brokered_by (broker/agency encoded- decimal)
status (property sale status- for_sale, sold, other)
price (house price- decimal)
bed (number of bedrooms- integer)
bath (number of bathrooms- integer)
acre_lot (total land size- decimal)
street (street address encoded- decimal)
city (city- string)
state (state- string)
zip_code (zip code- integer)
house_size (house size/living space sqft- decimal)
prev_sold_date
*/

void heapify(std::vector<realEstate>& arr, int n, int i, int sortType);
void buildHeap(std::vector<realEstate>& arr, int sortType);
void heapSort(std::vector<realEstate>& arr, int sortType);

#endif //HEAPSORT_H
