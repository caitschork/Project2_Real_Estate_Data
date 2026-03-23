//
// Created by Nicole Greenberg on 3/23/26.
//
#include "MergeSort.h"

double sortGetter(const realEstate& h, int sortType);

//logic and code for merge sort from lecture notes
void merge(vector<realEstate>& listings, int leftIndex, int midIndex, int rightIndex, int sortType) {
    int leftSize = midIndex - leftIndex + 1;
    int rightSize = rightIndex - midIndex;

    //temporary vectors for left and right halves
    vector<realEstate> leftHalf(leftSize);
    vector<realEstate> rightHalf(rightSize);

    //copy data into leftHalf
    for (int i = 0; i < leftSize; i++) {
        leftHalf[i] = listings[leftIndex + i];
    }

    //copy data into rightHalf
    for (int j = 0; j < rightSize; j++) {
        rightHalf[j] = listings[midIndex + 1 + j];
    }

    int leftPointer = 0;
    int rightPointer = 0;
    int mergedIndex = leftIndex;

    //merge halves
    while (leftPointer < leftSize && rightPointer < rightSize) {
        double leftValue = sortGetter(leftHalf[leftPointer], sortType);
        double rightValue = sortGetter(rightHalf[rightPointer], sortType);
        if (leftValue <= rightValue) {
            listings[mergedIndex] = leftHalf[leftPointer];
            leftPointer++;
        }else {
            listings[mergedIndex] = rightHalf[rightPointer];
            rightPointer++;
        }
        mergedIndex++;
    }

    //copy remaining elements from leftHalf
    while (leftPointer < leftSize)
    {
        listings[mergedIndex] = leftHalf[leftPointer];
        leftPointer++;
        mergedIndex++;
    }

    //copy remaining elements from rightHalf
    while (rightPointer < rightSize)
    {
        listings[mergedIndex] = rightHalf[rightPointer];
        rightPointer++;
        mergedIndex++;
    }
}


void mergeSort(vector<realEstate> &listings, int leftIndex, int rightIndex, int sortType) {
    // Base case: one element
    if (leftIndex < rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        // Sort left half
        mergeSort(listings, leftIndex, middleIndex, sortType);

        // Sort right half
        mergeSort(listings, middleIndex + 1, rightIndex, sortType);

        // Merge both halves
        merge(listings, leftIndex, middleIndex, rightIndex, sortType);
    }
}
