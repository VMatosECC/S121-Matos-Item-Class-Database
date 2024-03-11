#pragma once
#include "Item.h"

//Declaration section
class Toy : public Item
{
private:
    //Data members
    string ageRange;

public:
    void   setAgeRange(string ageRangeValue);
    string getAgeRange() const;

    Toy(string id, string name, double price, string supplier,
        string ageRange = "All ages");

    string toString() const;

    friend ostream& operator<< (ostream& sout, const Toy& t) {
        sout << t.toString();
        return sout;
    }

};
//Implementation section -----------------------------
void Toy::setAgeRange(string ageRangeValue)
{
    ageRange = ageRangeValue;
}

string Toy::getAgeRange() const { return ageRange; }

Toy::Toy(string id, string name, double price, string supplier,
    string ageRange) 
    : Item(id, name, price, supplier)
{
    setAgeRange(ageRange);
    if (price > 15)
        throw runtime_error("TOY - Price exceeds $15 limit");
}


string Toy::toString() const {
    stringstream sout;
    sout << this << " Toy [ "
        << Item::toString()
        << ", AgeRange: " << getAgeRange() << "]";
    return sout.str();
}

