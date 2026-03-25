#include <iostream>
#include <chrono>
#include <fstream>
#include <filesystem>
#include <limits>
#include "DataLoader.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
using namespace std;

//Helper Functions
string toLowercase(const string &s) {
    string result = s;
    for (char& c: result) {
        c = tolower(static_cast<unsigned char>(c));
    }
    return result;
}

vector<realEstate> filterHouses(const vector<realEstate>& houses,
    double maxPrice,
    string city,
    string state,
    string zipCode,
    double acreLot,
    double houseSize,
    int beds,
    int baths) {
    vector<realEstate> filteredHouses;
    for (const auto& house : houses) {
        if ((maxPrice == 0 || house.price <= maxPrice) &&
            (toLowercase(city)== "none" || toLowercase(house.city) == toLowercase(city)) &&
            (toLowercase(state) == "none" || toLowercase(house.state) == toLowercase(state)) &&
            (toLowercase(zipCode) == "none" || toLowercase(house.zipCode) == toLowercase(zipCode)) &&
            (acreLot == 0 || house.acreLot >= acreLot) &&
            (houseSize == 0 || house.houseSize >= houseSize) &&
            (beds == 0 || house.beds == beds) &&
            (baths == 0 || house.baths == baths) &&
            house.price > 1 && house.houseSize > 1) {
            filteredHouses.push_back(house);
        }
    }
    return filteredHouses;
}

//MAIN

int main() {
    vector<realEstate> data = loadData("../realtor-data-new.csv");

    if (data.empty()) {
        cout << "No data loaded" << endl;
        return 1;
    }

    bool running = true;

    while (running) {
        cout << "Welcome to the Real Estate Search!\n";
        cout << "1. New Search\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice\n";
            continue;
        }

        if (choice == 2) {
            cout << "Exiting...goodbye!\n";
            break;
        }

        //User Input
        double maxPrice;
        string city;
        string state;
        string zipCode;
        double acreLot;
        double houseSize;
        int beds;
        int baths;

        cout << "Enter max price (or 0 to skip): ";
        cin >> maxPrice;
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        cout << "Enter city (or None to skip): ";
        getline(cin, city);

        cout << "Enter state (or None to skip): ";
        getline(cin, state);

        cout << "Enter zip code (or None to skip): ";
        getline(cin, zipCode);

        cout << "Enter minimum acre lot size (or 0 to skip): ";
        cin >> acreLot;

        cout << "Enter minimum house size in square feet (or 0 to skip): ";
        cin >> houseSize;

        cout << "Enter the number of bedrooms (or 0 to skip): ";
        cin >> beds;

        cout << "Enter number of bathrooms (or 0 to skip): ";
        cin >> baths;

        //Filter Houses
        vector <realEstate> filtered = filterHouses(data, maxPrice, city,
            state, zipCode, acreLot, houseSize, beds, baths);

        if (filtered.empty()) {
            cout << "\nNo matching houses found:(\n";
            continue;
        }

        cout << "\nFiltered houses dataset size: " << filtered.size() << endl;

        //Sort Choice
        int sortChoice;
        cout << "\nSort by: "
                "\n1. House Price"
                "\n2. House Size"
                "\n3. Number of Beds"
                "\n4. Number of Baths"
                "\n5. Acre Lot Size"
                "\nChoice: ";
        cin >> sortChoice;

        if (sortChoice < 1 || sortChoice > 5) {
            cout << "Invalid sort choice\n";
            continue;
        }


        //Display Results
        vector<realEstate> heapData = filtered;
        vector<realEstate> mergeData = filtered;
        vector<realEstate> quickData = filtered;

        //Displaying results by heap sort (all algorithms produce the same output)
        cout << "\nTop 5 Results:\n";
        for (int i = 0; i < 5 && i < heapData.size(); i++) {
            cout << "Price: $" << heapData[i].price << "\n";
            cout << "Beds: " << heapData[i].beds << "\n";
            cout << "Baths: " << heapData[i].baths << "\n";
            cout << "Acre Lot Size: " << heapData[i].acreLot << "\n";
            cout << "City: " << heapData[i].city << "\n";
            cout << "State: " << heapData[i].state << "\n";
            cout << "Zip Code: " << heapData[i].zipCode << "\n";
            cout << "House Size (sqft): " << heapData[i].houseSize << "\n";
            cout << "\n";
        }

        //Sort and Clocked Time
        //Heap sort
        auto start1 = std::chrono::high_resolution_clock::now();
        heapSort(heapData, sortChoice);
        auto end1 = std::chrono::high_resolution_clock::now();
        auto heapTime = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count();

        //Merge sort
        auto start2 = std::chrono::high_resolution_clock::now();
        mergeSort(mergeData, 0, mergeData.size() - 1, sortChoice);
        auto end2 = std::chrono::high_resolution_clock::now();
        auto mergeTime = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count();

        //Quick sort
        auto start3 = std::chrono::high_resolution_clock::now();
        quickSort(quickData, 0, quickData.size() - 1, sortChoice);
        auto end3 = std::chrono::high_resolution_clock::now();
        auto quickTime = std::chrono::duration_cast<std::chrono::milliseconds>(end3 - start3).count();


        cout << "Heap Sort Time: " << heapTime << " ms" << endl;
        cout << "\nMerge Sort Time: " << mergeTime << " ms" << endl;
        cout << "\nQuick Sort Time: " << quickTime << " ms" << endl;

        //Save Results
        string fieldName;
        switch(sortChoice) {
            case 1: fieldName = "House Price"; break;
            case 2: fieldName = "House Size"; break;
            case 3: fieldName = "Number of Beds"; break;
            case 4: fieldName = "Number of Baths"; break;
            case 5: fieldName = "Acre Lot Size"; break;
            default: fieldName = "House Price"; break;
        }

        string filename = "../sort_results.csv";
        bool fileExists = std::filesystem::exists(filename);

        ofstream outFile(filename, ios::app);

        if (outFile.is_open()) {
            if (!fileExists) {
                outFile << "Run,Algorithm,Time\n";
            }

            outFile << fieldName << ",Heap Sort," << heapTime << "\n";
            outFile << fieldName << ",Merge Sort," << mergeTime << "\n";
            outFile << fieldName << ",Quick Sort," << quickTime << "\n";

            outFile.close();
        }

        //Repeat Search
        cout << "\nDo you want to search again? (y/n): ";
        string repeat;
        cin >> repeat;
        if (repeat != "y" && repeat != "Y") {
            running = false;
            cout << "Exiting... goodbye!\n";
        }
    }

    return 0;
}


