// Investigate memory library (header) for available functionalities to demo 
// few functions like casting between types and make_shared etc.

// static_pointer_cast, and make_shared will be covered

#include <iostream>
#include <memory> // includes shared_ptr and make_shared
#include <type_traits> // includes std::is_same_v
 
struct A
{
    A(){}
    
    A(int num) : i(num) {
        std::cout << "A::A\n"; 
        dynamic_type = static_type;
    }  //constructor message and static_pointer_cast test initialize
  
    int i; // int member data 
    static const char* static_type; // static const cstring member data
    const char* dynamic_type; // non static version of above
  
    ~A() { std::cout << "A::~A\n";  } // destructor message
  
};

struct B : A // B inherits from A
{
    static const char* static_type; // static const cstring member data
    // B::static_type is unique from A::static_type
    
    
    B(int num) : i(num) { dynamic_type = static_type; }
    int i; // int member data 
    
};

const char* A::static_type = "class A";
const char* B::static_type = "class B";
 
 
int main()
{
    std::cout << "testing make_shared.\n";  
    {
         
        // Allocates and constructs an object of type T passing args to its 
        // constructor, and returns an object of type shared_ptr<T> that owns
        // and stores a pointer to it (with a use count of 1)
        auto sp = std::make_shared<A>(12);
     
        static_assert(std::is_same_v<decltype(sp), std::shared_ptr<A>>);
        // debugs if std::shared_ptr sp is the same data type as C
     
        std::cout << sp->i << '\n';
        // output the integer i value of C object refered to sp
    } // sp shared_ptr out of scope, invokes destructor
    
    
    
    std::cout << "\ntesting static_pointer_cast.\n";
    {
        std::shared_ptr<A> foo;
        std::shared_ptr<B> bar; 
        
        foo = std::make_shared<A>(); // foo is now completed with object A
        // bar left as incomplete object
        
        bar = std::static_pointer_cast<B>(foo);
        // cast of potentially incomplete object, but ok as a static cast:
        // Returns a copy of foo of the A type with its stored pointer
        // (casted statically from B* to A*)
            
        std::cout << "foo's static  type: " << foo->static_type << '\n';
        std::cout << "foo's dynamic type: " << foo->dynamic_type << '\n';
        std::cout << "bar's static  type: " << bar->static_type << '\n';
        std::cout << "bar's dynamic type: " << bar->dynamic_type << '\n';
        // output proves static pinter casting successful
        
    }
    
    return 0;
} 
/*
testing make_shared.
A::A
12
A::~A

testing static_pointer_cast.
foo's static  type: class A
foo's dynamic type: class A
bar's static  type: class B
bar's dynamic type: class A
A::~A
*/

