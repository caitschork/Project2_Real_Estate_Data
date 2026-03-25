#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>
using namespace std;

struct realEstate {
    double price;
    string city;
    string state;
    string zipCode;
    double acreLot;
    double houseSize;
    int beds;
    int baths;
};

vector<realEstate> loadData(const string& filename);
#endif //DATALOADER_H
