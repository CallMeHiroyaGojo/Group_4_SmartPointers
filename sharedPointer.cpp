#include <iostream>
#include <string>

// <memory> is part of the dynamic memory management library
// include this header file when using smart pointers
#include <memory>

class Cow {
    
    private:
        // private string variable name
        std::string name;
    
    public:
        // default constructor
        Cow() {
            name = "Nameless";
            std::cout << "Nameless cow has been created" << std::endl;
        }
        // user-defined constructor
        Cow(std::string inputName) {
            name = inputName;
            std::cout << "A new cow has been created! " << inputName << " says Moooooooo...\n";
        }
        // destructor
        ~Cow() {
            std::cout << name << " has been destroyed, bye bye!\n";
        }
        
        // method eats grass
        void eatGrass() {
            std::cout << name << " is grazing, munch munch...\n";
        }
};

void smartExample1() {
    
    std::cout << "Shared pointer example 1: \n";
    std::cout << "...1st pointer created, \n";
    std::shared_ptr<Cow> p(new Cow("Johnson")); // Shared pointer created
        // count = 1
    std::cout << "Count of p = " << p.use_count() << std::endl;
    std::cout << "Adress of shared_ptr p : " << p << std::endl;
    
    {
        std::cout << "...2nd pointer points to 1st, \n";
        std::shared_ptr<Cow> p2 = p; // Another shared pointer created pointing to Cow "Johnson
            // count = 2
        std::cout << "Adress of shared_ptr p2 : " << p2 << std::endl;
        p2 -> eatGrass();
        std::cout << "Count of p2 = " << p2.use_count() << std::endl;
        std::cout << "Count of p = " << p.use_count() << std::endl;
    } // out of scope, p2 is destroyed
    
    p -> eatGrass();
    // p2 -> eatGrass();
    // this would not work as p2 has already been autimatically destroyed
    std::cout << "Count of p = " << p.use_count() << std::endl;

} // out of scope, p is destoyed

void smartExample2() {
    
    std::cout << "Shared pointer example 2: \n" << "Here we will display a more effecient" <<
        " method of creating shared pointers.\n";
    // the method we first used for creating a shared pointer:
    std::shared_ptr<Cow> p3(new Cow());
        //  1. Nameless cow is created 2. p is created pointing to Nameless cow
    p3 -> eatGrass();
    // better method for creating a shared pointer:
    std::shared_ptr<Cow> p4 = std::make_shared<Cow>("Jack");
        // faster and avoids memory leaks as p2 is a new pointer being created
    p4 -> eatGrass();
    
} // out of scope, p3 and p4 destroyed

int main() {
    
    std::cout << "-----------------------------\n";
    smartExample1();
    std::cout << "-----------------------------\n";
    smartExample2();
    std::cout << "-----------------------------\n";
}
