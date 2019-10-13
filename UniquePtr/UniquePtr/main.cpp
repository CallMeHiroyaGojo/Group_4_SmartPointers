

#include <iostream>
#include<memory>
using namespace std;

class Sample {
public:
    void show()
    {
        cout << "Testing success!" << endl;
    }
    };

int main()

{
    int size; //Maximum array size
    unique_ptr<Sample> t1(new Sample);
          t1->show();
        
          // returns the memory address of t1
          cout << t1.get() << endl;
        
          // transfers ownership to t2
          unique_ptr<Sample> t2 = move(t1);
          t2->show();
    //After transfers to t2, t1 memory is deleted and t2 holds the data.
          cout << t1.get() << endl;
          cout << t2.get() << endl;
    
    cout <<"How many numbers do you want the computer to save? ";  //Get  the numbers from users.
    cin>>size;
    unique_ptr<int[]> ptr(new int [size]); //Pointing to a dynamically allocated array of ints
    // Saving the value for each of the pointer that user enter
    for (int index =0; index < size ; index++)
    {
        cout<< "Enter an number for " << (index +1) ;
        cout<<endl;
        cin>> ptr[index];
    }
    cout << "The computer is saving your numbers in the memory... The followings are the numbers that you type in : \n" ;
    // Showing what users enter in each of the array.
    for (int index =0 ; index<size ;index++)
    {
        cout << ptr[index] <<endl;
    }
   


}
  
