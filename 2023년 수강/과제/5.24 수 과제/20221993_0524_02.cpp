#include <iostream>
#include <utility>

int main() {
  std::pair<int, double> myPair(10, 3.14);

  std::cout << "First valueL:  " << myPair.first << std::endl;
  std::cout << "Second valueL:  " << myPair.second << std::endl;

  myPair.first = 20;
  myPair.second = 2.71;

  std::cout << "Modified First valueL  " << myPair.first << std::endl;
  std::cout << "Modified Second valueL  " << myPair.second << std::endl;

  return 0;
}