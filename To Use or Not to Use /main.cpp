// "When should I use a smart pointer?"

// Smart pointers provides Automatic Memory Management, 
// when a smart pointer is no longer in use, 
// the memory it points to is deallocated.
// In code which involves tracking the ownership of a piece of memory,
// allocating or de-allocating; the smart pointer often saves
// you the need to do these things explicitly.


// "When should I use a regular pointer?"

// When there is no transfer of or shared ownership 
// references or plain pointers are good enough.



// We will use an uniquePtr as an example here because two different 
// pointers independently refering to our object.
#include <memory>  // includes std::unique_ptr
#include <cassert> // include assert
#include <iostream>


struct A
{
    virtual void bar() { std::cout << "A::bar\n"; }
    
    virtual ~A() = default; // prints nothing upon detruct 
};

struct B : A 
{ 
    B() { std::cout << "B::B\n";  }    // construct A message
    ~B() { std::cout << "B::~B\n";  }  // destruct A message
    
    void bar() override { std::cout << "B::bar\n";  } //overrides A::bar()
};


// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<B> pass_through(std::unique_ptr<B> x)
{
    x->bar(); // calls bar()
    return x;
}
 

int main()
{
    /* Unique_ptr demonstration. */
    std::cout << "unique ownership semantics demo\n";
    {
        auto x = std::make_unique<B>(); // x is a unique_ptr that owns a B
        
        auto y = pass_through(std::move(x)); // this line passes rvalue to 
        // left value, then calls rvalue->bar() ; rvalue is assigned to lvalue
        // in the process. std::move catches x before it points to null and 
        // assign it to y inside pass_through()
        
        assert(!x); // debug to check if x points to null
        // C assert passes, now x owns nothing and holds a null pointer
        
        assert(y); // debug to check if y owns a B object
        // C assert passes, y still points to a B object
        
        y->bar();   // y invokes B::bar(), confirms y owns the B object
        
    } // Scope exited. ~B called here
    // we see how unique_ptr is useful when we want one pointer to point at
    // one source at a time, and it also inherits smart pointers ability to 
    // destruct object when it is out of scope.
    
    /* regular pointer demonstration */
    std::cout << std::endl << "regular pointer semantics demo\n";
    auto *zPtr = new B; // zPtr is a reg Pointer that owns a B  
    zPtr->bar();
    bool flag;
    
    do{ 
        std::cout << "want to delete zPtr yet?(1 for yes, 0 for no)\n";
        std::cout << "loop exit upon input 1.\n";
        std::cin >> flag;
    }while(!flag);
    
    zPtr->~B(); // zPtr calls ~B MANUALLY 
    // a regular pointer is helpful when we want a pointer to delete itself
    // when we needed it to.
}

/* Output


unique ownership semantics demo
B::B
B::bar
B::bar
B::~B

regular pointer semantics demo
B::B
B::bar
want to delete zPtr yet?(1 for yes, 0 for no)
loop exit upon input 1.
0
want to delete zPtr yet?(1 for yes, 0 for no)
loop exit upon input 1.
1
B::~B


*/