//
//  main.cpp
//  Weak_ptr
//
//  Created by Thomas Stagnaro on 10/9/19.
//  Copyright © 2019 Thomas Stagnaro. All rights reserved.
//

/*
 To understand weak_ptr, one must understand shared_ptr and unique_ptr.

 A "strong" reference refers to
 The weak_ptr provides a reference to an object that is already pointed to by a shared_ptr.
 A weak_ptr does not increase the reference count for the object being pointed to.
 A weak_ptr does not own the memory responsible for the object. Therefore, a weak_ptr cannot
 affect the lifetime of the object
 The purpose of a weak_ptr is to give the programmer the ability to have two objects reference eachother
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
    {}
};

int main()
{
    // Create an instance of a class
    Box b1;

    // Create shared pointers all pointing to the same obect.
    // Right now, the Manager object for the object b1 has a reference count of 3.
    auto sharedPointer1 = std::make_shared<Box>(b1);
    auto sharedPointer2 = sharedPointer1;
    auto sharedPointer3 = sharedPointer1;

    // This statment creates a weak_ptr
    std::weak_ptr<Box> wkptr1 = sharedPointer1;
    auto wkptr2 = wkptr1;


    return 0;
}

//std::weak_ptr<int> gw;
//
//void observe()
//{
//    std::cout << "use_count == " << gw.use_count() << ": ";
//    if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
//    std::cout << *spt << "\n";
//    }
//    else {
//        std::cout << "gw is expired\n";
//    }
//}
//
//int main()
//{
//    {
//        auto sp = std::make_shared<int>(42);
//    gw = sp;
//
//    observe();
//    }
//
//    observe();
//}
