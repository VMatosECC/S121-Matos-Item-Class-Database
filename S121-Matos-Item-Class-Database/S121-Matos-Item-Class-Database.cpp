// S121-Matos-Item-Class-Database.cpp 
#pragma once
#include "Item.h"
#include "Toy.h"
#include "Edible.h"
#include <vector>

//Prototypes---------------------------------------
void experiment01();
void experiment02();
void experiment03();
void experiment04();
void experiment05();
void experiment06();

int main()
{
    //experiment01();
    //experiment02();
    //experiment03();
    //experiment04();
    //experiment05();
    experiment06();

    cout << "All done!\n";
}
//------------------------------------------------
void experiment06() {

    try
    {
        Edible e1("E1234", "Cobb Salad", 4.00, "Green Garden",
            6000, "Lettuce, cabagge, carrots, eggs, ham, ranch dressing");

        cout << "e1 " << e1 << endl;
    }
    catch (const std::exception& e)
    {
        cout << "ERROR - Edible object not created - " << e.what() << endl;
    }

    cout << "\nAll done!\n";
}


//-------------------------------------------------
void experiment05() {
    try
    {
        Toy t1("T0123", "Lego", 20.00, "Amazon", "10+");
        cout << "t1 " << t1.toString() << endl;
        cout << "t1 " << t1 << endl;
    }
    catch (const std::exception& e)
    {
        cout << "ERROR - Object not created. " << e.what() << endl;
    }
    cout << "I'm alive!!!" << endl;
}




//-------------------------------------------------
void experiment04() {

    cout << "Total Items " << Item::getCounter() << endl;
    Item i1;
    cout << endl;

    cout << "Total Items " << Item::getCounter() << endl;
    cout << "Total Items " << i1.getCounter() << endl;

    cout << endl;

    cout << "i1 " << i1.toString() << endl;  //using qualification
    talk(i1);                                //using a friend
    cout << "i1 " << i1 << endl;

    //Data acquisition
    Item i2;
    cin >> i2;
    cout << "\ni2 " << i2.toString() << endl;
    cout << "\ni2 " << i2 << endl;
}



//-------------------------------------------------
void experiment03()
{
    Item i1("F0001", "Red Apple", 0.50, "Chiquita Corp");
    Item i2("F0002", "Green Apple", 0.75, "Orchard Hills");
    Item i3("F0003", "Coconut", 1.50, "Tropical Farm");

    //vector<Item> db{ i1, i2, i3 };
    //db.push_back(*(new Item("F004", "Plantain", .25, "Tico Farm")));
    vector<Item> db;
    db.emplace_back(i1);
    db.emplace_back(i2);
    db.emplace_back(i3);

    for (Item& i : db) {
        cout << i.toString() << endl;
    }
}
//-------------------------------------------------
void experiment02()
{
    cout << "\nCount of Items so far is " << Item::getCounter() << endl;

    Item i0("X0001", "Pineapple");
    cout << "i0 " << i0.toString() << endl;
    cout << "\nCount of Items so far is " << Item::getCounter() << endl;

    Item i1("X1111", "Red Apple", .50);
    cout << "i1 " << i1.toString() << endl;
    cout << "\nCount of Items so far is " << Item::getCounter() << endl;

    Item i2("X2222", "Green Apple", .75, "Chiquita Corp.");
    cout << "i2 " << i2.toString() << endl;
    cout << "\nCount of Items so far is " << Item::getCounter() << endl;
    cout << "\nCount of Items so far is " << i2.getCounter() << endl;

    ////clone i2
    //Item i3(i2);

    Item i3;
    i3 = i2;

    //Item i3 = i2;
    cout << "i2 (the source) " << i2.toString() << endl;
    cout << "i3 (the clone)  " << i3.toString() << endl;

    i3.setSupplier("ACME Corp.");

    cout << "After " << endl;
    cout << "i2 (the source) " << i2.toString() << endl;
    cout << "i3 (the clone)  " << i3.toString() << endl;
}



void experiment01()
{
    Item i1;
    cout << "i1 " << i1.toString() << endl;
    i1.setId("X0001");
    i1.setName("BlUe DEsK");
    i1.setPrice(-120.55);
    cout << "i1 " << i1.toString() << endl;



    Item i2("X7781", "Red Brush", 10.99);
    cout << "i2 " << i2.toString() << endl;
    cout << i2.getId() << endl;
    cout << i2.getName() << endl;
    cout << i2.getPrice() << endl;

    cout << "\n\nItem Database\n";
    vector<Item> db{ i1, i2 };
    for (Item i : db) {
        cout << i.toString() << endl;
    }

}

