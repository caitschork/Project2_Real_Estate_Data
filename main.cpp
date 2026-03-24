#include <iostream>
#include <chrono>
#include <fstream>
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

string toLowercase(const string &s) {
    string result = s;
    for (char& c: result) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return result;
}

vector<realEstate> filterHouses(const vector<realEstate>& houses, double maxPrice,
    string city, string state, string zip_code, double acre_lot, double house_size, int beds, int baths) {
    vector<realEstate> filteredHouses;
    for (const auto& house : houses) {
        if ((maxPrice == 0 || house.price <= maxPrice) &&
            (toLowercase(city)== "none" || toLowercase(house.city) == toLowercase(city)) &&
            (toLowercase(state) == "none" || toLowercase(house.state) == toLowercase(state)) &&
            (toLowercase(zip_code) == "none" || toLowercase(house.zip_code) == toLowercase(zip_code)) &&
            (acre_lot == 0 || house.acre_lot >= acre_lot) &&
            (house_size == 0 || house.house_size >= house_size) &&
            (beds == 0 || house.beds == beds) &&
            (baths == 0 || house.baths == baths) &&
            house.price > 1 && house.house_size > 1) {
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

    cout << "Enter max price (or 0 to skip): ";
    cin >> maxPrice;

    cout << "Enter city (or None to skip): ";
    cin >> city;

    cout << "Enter state (or None to skip): ";
    cin >> state;

    cout << "Enter zip code (or None to skip): ";
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

    // auto start3 = std::chrono::high_resolution_clock::now();
    // quickSort(quickData, 0, quickData.size() - 1, sortChoice);
    // auto end3 = std::chrono::high_resolution_clock::now();
    // auto quickTime = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count();

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

    ofstream outFile("sort_results.csv");
    if (outFile.is_open()) {
        outFile << "Algorithm,Time\n";
        outFile << "Heap Sort," << heapTime << "\n";
        outFile << "Merge Sort," << mergeTime << "\n";
        // outFile << "Quick Sort," << quickTime << "\n"; // Uncomment when ready
        outFile.close();
        cout << "\nResults exported to sort_results.csv!" << endl;
    } else {
        cout << "Error: Could not create CSV file." << endl;
    }

    return 0;
}

