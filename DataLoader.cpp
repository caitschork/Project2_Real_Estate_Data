#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

//function to load real estate data from csv file
vector<realEstate> loadData(const string& filename) {
    vector<realEstate> data;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return data;
    }

    string line;
    //skip header
    getline(file, line);

    //read each remaining line
    while (getline(file, line)) {
        stringstream ss(line);
        string field; //each column
        realEstate house;

        //parse each column in order
        //brokered_by(not using,ignore)
        getline(ss, field, ',');

        //status(not using, ignore)
        getline(ss, field, ',');

        //price
        getline(ss, field, ',');
        if (field == "") {
            house.price = 0;
        }else {
            house.price = stod(field);
        }

        //beds
        getline(ss, field, ',');
        if (field == "") {
            house.beds = 0;
        }else {
            house.beds = stoi(field);
        }

        //baths
        getline(ss, field, ',');
        if (field == "") {
            house.baths = 0;
        }else {
            house.baths = stoi(field);
        }

        //acre lot
        getline(ss,field, ',');
        if (field == "") {
            house.acreLot = 0;
        }else {
            house.acreLot = stod(field);
        }

        //street (not using, ignore)
        getline(ss, field, ',');

        //city
        getline(ss, house.city, ',');

        //state
        getline(ss, house.state, ',');

        //zip_code
        getline(ss, house.zipCode, ',');

        //house_size
        getline(ss, field, ',');
        if (field == "") {
            house.houseSize = 0;
        }else {
            house.houseSize = stod(field);
        }

        //prev sold date (ignore)
        getline(ss, field, ',');

        //add house to vector
        data.push_back(house);
    }
    return data;
}