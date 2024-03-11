#pragma once
#include "Item.h"
class Edible : public Item
{
private:
    //Data members
    int     calories;
    string* description;
    
    const int MAX_CALORIES = 3000;

    static int count;

public:
    //Mutators
    void setCalories(int calories) {
        if (calories > MAX_CALORIES) {
            throw runtime_error("Too many calories!!!");
        }

        this->calories = abs(calories);
    }

    void setDescription(string description) {
        *(this->description) = description;
    }

    //Accessors
    int    getCalories()    const { return calories; }
    string getDescription() const { return *description; }
    static int    getCout() { return count; }

    //Constructors (zero/all arguments)
    Edible(string id, string name, double price, string supplier,
        int calories = 0, string description = "None")
        : Item(id, name, price, supplier)
    {
        setCalories(calories);
        this->description = new string();
        setDescription(description);
    }

    //Copy-Constructor
    Edible(const Edible& other) {
        *this = other;
    }


    //Destructor
    ~Edible() {
        cout << "+++ Edible destructor " << this->getName() << endl;
        delete description;
    }
    //User-Defined Methods
    friend ostream& operator<< (ostream& sout, const Edible& e) {
        sout << " Edible [Id: " << e.getId()
            << ", Name: " << e.getName()
            << ", Price: " << e.getPrice()
            << ", Supplier: " << e.getSupplier()
            << ", Calories: " << e.getCalories()
            << ", Description: " << e.getDescription()
            << "]";
        return sout;
    }

    //Overloaded Operators
    void operator= (const Edible& other) {
        this->setCalories(other.getCalories());

        this->description = new string();
        *(this->description) = *other.description;

    }
};

//Initialize static data
int Edible::count = 0;

