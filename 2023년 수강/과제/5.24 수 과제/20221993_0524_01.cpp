#include <iostream>

template <typename T>

class DynamicArray {
private :
  T* arr;
  int size;

public :
  DynamicArray(int size) : size(size) {
    arr = new T[size];
  }
  
  ~DynamicArray() {
    delete[] arr;
  }
  
  void setValue(int index, T value) {
    arr[index] = value;
  }
  
  T getValue(int index) {
    return arr[index];
  }
};

int main() {
  DynamicArray<int> intArray(5);
  intArray.setValue(0, 10);
  intArray.setValue(1, 20);
  std::cout << "Value at index 0: " << intArray.getValue(0) << std::endl;
  std::cout << "Value at index 1: " << intArray.getValue(1) << std::endl;

  DynamicArray<double> doubleArray(3);
  doubleArray.setValue(0, 3.14);
  doubleArray.setValue(1, 2.71);
  std::cout << "Value at index 0: " << doubleArray.getValue(0) << std::endl;
  std::cout << "Value at index 1: " << doubleArray.getValue(1) << std::endl;

  return 0;
}