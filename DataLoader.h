#ifndef DATALOADER_H
#define DATALOADER_H

#include <string>
#include <vector>
using namespace std;

struct realEstate {
    double price;
    string city;
    string state;
    string zip_code;
    double acre_lot;
    double house_size;
    int beds;
    int baths;
};

vector<realEstate> loadData(const string& filename);
#endif //DATALOADER_H
