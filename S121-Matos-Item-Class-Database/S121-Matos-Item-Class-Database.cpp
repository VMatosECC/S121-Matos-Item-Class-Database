// S121-Matos-Item-Class-Database.cpp 
#include <iostream>
#include "Item.h"
#include <vector>

int main()
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

    cout << "All done!\n";
}

