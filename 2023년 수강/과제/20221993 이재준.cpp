#include <iostream>
using namespace std;
class Parent 
{
    public:
        int data1;
        int data2;


        Parent(int data1, int data2) {
            this->data1 = data1;
            this->data2 = data2;
            /* fill the blank*/
        }
        void print_data() {
            cout << "first data : " << this->data1 << "\nsecond data : " << this->data2 << "\n";
        }
};

class Child : public Parent 
{
    public:
        Child(int data1, int data2) : Parent(data1, data2) /*fill the blank*/ 
        {}
        
        void swap() 
        {
          int a, b;
          a = data1;
          b = data2;
          this->data1 = b;
          this->data2 = a;
          
          
          /*fill the blank*/
        }
};

int main() {
  Child c1(1, 2);
  c1.print_data();
  c1.swap();
  c1.print_data();
}