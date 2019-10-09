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
 */
#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void observe()
{
    std::cout << "use_count == " << gw.use_count() << ": ";
    if (auto spt = gw.lock()) { // Has to be copied into a shared_ptr before usage
    std::cout << *spt << "\n";
    }
    else {
        std::cout << "gw is expired\n";
    }
}

int main()
{
    {
        auto sp = std::make_shared<int>(42);
    gw = sp;

    observe();
    }

    observe();
}
