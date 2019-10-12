//
//  main.cpp
//  Weak_ptr
//
//  Created by Thomas Stagnaro on 10/9/19.
//  Copyright © 2019 Thomas Stagnaro. All rights reserved.
//

/*
 This program demonstrates how weak pointers can be used.
 1. First we set up a simple class called Box.
 2. In main() we create an instance of box called b1.
 3. Then we create a few shared pointers to the b1 object.
 4. We create a weak pointer.
 5. We use the weak pointer to demonstrate that the b1 object is not "alive".
 6. We demonstrate what happens if we don't use a weak pointer.
 */
#include <iostream>
#include <memory>

class Box
{
private:
    int height;
    int width;
    int length;

public:

    Box()
    {
        std::cout << "Enter height: ";
        std::cin >> height;
        std::cout << "Enter width: ";
        std::cin >> width;
        std::cout << "Enter length: ";
        std::cin >> length;
    }
    void printInfo()
    {
        std::cout << "Box Info \n";
        std::cout << "Box height: " << height <<
        " Box width: " << width << " Box length: " << length <<
        "\nBox volume: " << length * width * length <<std::endl;
    }
};

int main()
{
    // Create an instance of a class
    Box b1;

    // Create shared pointers all pointing to the same obect (b1).
    // Right now, the Manager object for the object b1 has a reference count of 3.
    auto sharedPointer1 = std::make_shared<Box>(b1);
    auto sharedPointer2 = sharedPointer1;
    auto sharedPointer3 = sharedPointer1;

    // Access the b1 object with a shared pointer;
    sharedPointer1->printInfo();


    // Access the b1 object with a different shared pointer;
    sharedPointer2->printInfo();

    // Access the b1 object with a different shared pointer;
    sharedPointer3->printInfo();


    // At this point, there are multiple shared pointers pointing to the same object.
    // There could come a time in a large program that we lose track of
    // the shared pointer. We may access an object even if the object is no longer in memory.
    // To demonstrate how this works we set the shared pointers to null.

      sharedPointer1 = nullptr;
      sharedPointer2 = nullptr;
      sharedPointer3 = nullptr;

    // This statment creates a weak_ptr and points it to the b1 object.
    // Using the "expired" method of the weak pointer wkptr1, we check to see if
    // the object b1 still exists. The b1 object does not exist so the statement
    // "The b1 object is no longer "alive" is printed to the console.

    std::weak_ptr<Box> wkptr1 = sharedPointer1;
    if (wkptr1.expired()) {
        std::cout<< "The b1 object is no longer \"alive\"\n";
    } else
        sharedPointer1->printInfo();

    // The Below code is commented out.
    // If you were to run this code, you would receive an error because
    // this code attempt to have a shared pointer acces an object that is no longer
    // "alive".

    //    sharedPointer2->printInfo();

    return 0;
}
