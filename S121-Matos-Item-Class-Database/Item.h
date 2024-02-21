#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class Item
{
private:
    //Data Members
    string id;
    string name;
    double price;
    string titleCaps(string nameValue)
    {
        if (nameValue.size() == 0) return "";

        char previous = ' ';
        for (int i = 0; i < nameValue.size(); i++) {
            char c = tolower(nameValue[i]);
            if (previous == ' ') c = toupper(c);
            nameValue[i] = c;
            previous = c;
        }

        return nameValue;
    }

public:
    //Mutators
    void setId(string idValue) {
        //TODO Validate-First char must be a letter
        id = idValue;
    }

    void setName(string nameValue) {
        name = titleCaps(nameValue);
    }

    void setPrice(double priceValue) {
        price = abs(priceValue);
    }


    //Accessors
    string getId()    { return id; }
    string getName()  { return name; }
    double getPrice() { return price; }

    ////Constructors
    //Zero-Arguments
    Item() {
        setId("NA");
        setName("NA");
        setPrice(0);
    }
     
    //All-Arguments constructor
    Item(string idValue, string nameValue, double priceValue)
    {
        setId(idValue);
        setName(nameValue);
        setPrice(priceValue);
    }

    //User-Defined Methods
    string toString() {
        stringstream sout;
        sout << this << " Item [ ID: " << getId()
            << ", Name: " << getName()
            << ", Price: " << getPrice() << "]";
        return sout.str();
    }

};

