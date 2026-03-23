#include <iostream>
#include <chrono>
#include "DataLoader.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include <matplot/matplot.h>
using namespace matplot;

// double price;
// string city;
// string state;
// string zip_code;
// double acre_lot;
// double house_size;
// int beds;
// int baths;


vector<realEstate> filterHouses(const vector<realEstate>& houses, double maxPrice,
    string city, string state, string zip_code, double acre_lot, double house_size, int beds, int baths) {
    vector<realEstate> filteredHouses;
    for (const auto& house : houses) {
        if ((maxPrice == 0 || house.price <= maxPrice) &&
            (city == "NONE" || house.city == city) &&
            (state == "NONE" || house.state == state) &&
            (zip_code == "NONE" || house.zip_code == zip_code) &&
            (acre_lot == 0 || house.acre_lot >= acre_lot) &&
            (house_size == 0 || house.house_size >= house_size) &&
            (beds == 0 || house.beds == beds) &&
            (baths == 0 || house.baths == baths) &&
            house.price > 0 && house.house_size > 0) {
            filteredHouses.push_back(house);
        }
    }
    return filteredHouses;
}

int main() {
    vector<realEstate> data = loadData("../realtor-data-new.csv");

    if (data.empty()) {
        cout << "No data loaded" << endl;
        return 1;
    }
    double maxPrice;
    string city;
    string state;
    string zip_code;
    double acre_lot;
    double house_size;
    int beds;
    int baths;

    // for (int i = 10000; i < 10004; i++) {
    //     cout << "Loaded Price: " << data[i].price << endl;
    // }

    cout << "Enter max price (or 0 to skip): ";
    cin >> maxPrice;

    cout << "Enter city (or NONE to skip): ";
    cin >> city;

    cout << "Enter state (or NONE to skip): ";
    cin >> state;

    cout << "Enter zip code (or NONE to skip): ";
    cin >> zip_code;

    cout << "Enter minimum acre lot size (or 0 to skip): ";
    cin >> acre_lot;

    cout << "Enter minimum house size in square feet (or 0 to skip): ";
    cin >> house_size;

    cout << "Enter the number of bedrooms (or 0 to skip): ";
    cin >> beds;

    cout << "Enter number of bathrooms (or 0 to skip): ";
    cin >> baths;

    vector <realEstate> filtered = filterHouses(data, maxPrice, city, state, zip_code, acre_lot, house_size, beds, baths);

    cout << "\nFiltered houses dataset size: " << filtered.size() << endl;

    int sortChoice;
    cout << "\nSort by: "
            "\n1. House Price"
            "\n2. House Size"
            "\n3. Number of Beds"
            "\n4. Number of Baths"
            "\n5. Acre Lot Size"
            "\nChoice: ";
    cin >> sortChoice;

    vector<realEstate> heapData = filtered;

    auto start1 = std::chrono::high_resolution_clock::now();
    heapSort(heapData, sortChoice);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto heapTime = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();

    cout << "\nHeap Sort Time: " << heapTime << " ms" << endl;

    //other sorts to be implemented
    vector<realEstate> mergeData = filtered;

    auto start2 = std::chrono::high_resolution_clock::now();
    mergeSort(mergeData, 0, mergeData.size() - 1, sortChoice);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto mergeTime = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();

    cout << "\nMerge Sort Time: " << mergeTime << " ms" << endl;
    //
    // vector<realEstate> quickData = filtered;
    //
    // auto start3 = std::chrono::high_resolution_clock::now();
    // quickSort(quickData, 0, quickData.size() - 1, sortChoice);
    // auto end3 = std::chrono::high_resolution_clock::now();
    // auto quickTime = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count();
    //
    // cout << "\nQuick Sort Time: " << quickTime << " ms" << endl;


    cout << "\nTop 5 Results:\n";
    // for (int i = heapData.size() - 1; i >= 0 && i >= heapData.size() - 5; i--) {
    for (int i = 0; i < 5 && i < heapData.size(); i++) {
        cout << "Price: " << heapData[i].price << "\n";
        cout << "Beds: " << heapData[i].beds << "\n";
        cout << "Baths: " << heapData[i].baths << "\n";
        cout << "Acre Lot: " << heapData[i].acre_lot << "\n";
        cout << "City: " << heapData[i].city << "\n";
        cout << "State: " << heapData[i].state << "\n";
        cout << "Zip: " << heapData[i].zip_code << "\n";
        cout << "House Size: " << heapData[i].house_size << "\n";
        cout << "\n";
    }

    //graphics
    // vector<string> labels = {"Heap", "Merge", "Quick"};
    // vector<double> times = {(double)heapTime, (double)mergeTime, (double)quickTime};
    //
    // figure();
    // bar(times);
    // xticks({0, 1, 2});
    // xticklabels(labels);
    // tite("Sorting Algorithms Runtime");
    // ylabel("Time (ms)");
    // show();
    return 0;
}

//Print first 5 rows
// for (int i = 0; i < 5 && i < data.size(); i++) {
//     cout << "House " << i + 1 << ":\n";
//     cout << "Price: " << data[i].price << "\n";
//     cout << "Beds: " << data[i].beds << "\n";
//     cout << "Baths: " << data[i].baths << "\n";
//     cout << "Acre Lot: " << data[i].acre_lot << "\n";
//     cout << "City: " << data[i].city << "\n";
//     cout << "State: " << data[i].state << "\n";
//     cout << "Zip: " << data[i].zip_code << "\n";
//     cout << "House Size: " << data[i].house_size << "\n";
//     cout << "\n\n";
// }