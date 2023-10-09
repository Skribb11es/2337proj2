#include "Customer.h"
#include "Gold.h"
#include "Platinum.h"


#include <string>
#include <iostream>
#include <sstream>
#include <array>
#include <fstream>


using namespace std;

// drink prices
const double sodaPrice = 0.20;
const double teaPrice = 0.12;
const double fruitPunchPrice = 0.15;


// drink size vars

// small drink
const int sSize = 12;
const double SSA = 56.565;

// medium drink
const int mSize = 20;
const double MSA = 81.305;

// large drink
const int lSize = 32;
const double LSA = 120.96;

void processPurchase(string purchase[], Customer* cusArr[], int index) {
    double price;
    if(cusArr[index]->getGuestID() == purchase[0]) {
        if(purchase[1]=="S") {
            price = stod(purchase[3]) * SSA;
            if(purchase[2]=="soda") {
                price += sodaPrice*sSize;
            }
            if(purchase[2]=="tea") {
                price += teaPrice*sSize;
            }
            if(purchase[2]=="punch") {
                price += fruitPunchPrice*sSize;
            }
        } 

        if(purchase[1]=="M") {
            price = stod(purchase[3]) * MSA;
            if(purchase[2]=="soda") {
                price += sodaPrice*mSize;
            }
            if(purchase[2]=="tea") {
                price += teaPrice*mSize;
            }
            if(purchase[2]=="punch") {
                price += fruitPunchPrice*mSize;
            }
        }

        if(purchase[1]=="L") {
            price = stod(purchase[3]) * LSA;
            if(purchase[2]=="soda") {
                price += sodaPrice*lSize;
            }
            if(purchase[2]=="tea") {
                price += teaPrice*lSize;
            }
            if(purchase[2]=="punch") {
                price += fruitPunchPrice*lSize;
            }
        }

        price *= stoi(purchase[4]);

        cusArr[index]->setAmtSpent(cusArr[index]->getAmtSpent() + price);

    } 
}

int main() {
    string fileName;
    string line;
    string lineArr[5];
    int arrPos;
    int lineCT;
    int iter;
    bool preferred;
    Customer** preferredArr;
    ifstream file;

    // regular customer processing

    cout << "Please input the name of the regular customer file: " << endl;
    cin >> fileName;

    int regularLen;

    file.open(fileName);

    lineCT=0;
    while(getline(file, line)){
        lineCT++;
    }
    
    file.clear();
    file.seekg (0);

    Customer** regularArr = new Customer*[lineCT];
    arrPos=0;

    while(getline(file, line)){
        stringstream ss(line);
        iter = 0;
        while(ss.good()){
            ss >> lineArr[iter];
            iter++;
        }
        regularArr[arrPos] = new Customer(lineArr[1], lineArr[2], lineArr[0], stod(lineArr[3]));
        arrPos++;
    }

    regularLen = arrPos;

    file.close();


    // preferred customer processing

    cout << "Please input the name of the preferred customer file: " << endl;
    cin >> fileName;

    int preferredLen;

    file.open(fileName);

    if(file) {
        preferred = true;
        lineCT=0;
        while(getline(file, line)){
            lineCT++;
        }
        
        file.clear();
        file.seekg(0);

        preferredArr = new Customer*[lineCT];
        arrPos=0;

        while(getline(file, line)){
            stringstream ss(line);
            iter = 0;
            while(ss.good()){
                ss >> lineArr[iter];
                iter++;
            }
            if(static_cast<int>(lineArr[4].find("%")) != -1) { // means gold
                preferredArr[arrPos] = new Gold(lineArr[1], lineArr[2], lineArr[0], stod(lineArr[3]), stod(lineArr[4].erase(1)));
            } else { // means plat
                preferredArr[arrPos] = new Platinum(lineArr[1], lineArr[2], lineArr[0], stod(lineArr[3]), stoi(lineArr[4]));
            }
            arrPos++;
        }

        preferredLen = arrPos;

        file.close();
    }

    // order processing

    cout << "Please input the name of the orders file: " << endl;
    cin >> fileName;

    file.open(fileName);

    lineCT=0;
    while(getline(file, line)){
        lineCT++;
    }

    file.clear();
    file.seekg(0);

    while(getline(file, line)){ 
        stringstream ss(line);
        iter = 0;
        while(ss.good()){
            ss >> lineArr[iter];
            iter++;
        }

        for (int i = 0; i<regularLen; i++) {
            processPurchase(lineArr, regularArr, i);
        }
        if(preferred) {
            for (int i = 0; i<preferredLen; i++) {
                processPurchase(lineArr, preferredArr, i);
            }
        }
    }

    cout << preferredLen << regularLen << endl;

    Customer test();
    Gold test2("first", "last", "id", 100.00, 100.00);
    cout << preferredArr[0]->getFirstName() << " " << preferredArr[0]->getLastName() << " " << preferredArr[0]->getDiscountPercent() << endl;
   
    return 0;
}