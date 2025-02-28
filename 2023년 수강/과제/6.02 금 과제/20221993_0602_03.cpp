#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(vector<int>& A) {
  int n = A.size();

  for (int i=0; i<n-1; i++) {
    for (int j=0; j<n-1-i; j++) {
      if (A[j]>A[j+1]) {
        swap(A[j], A[j+1]);
      }
    }
  }
}

int main() {
  vector<int> A = {64, 34, 25, 12, 22, 11, 90};

  bubbleSort(A);

  cout << "Sorted array using Bubble Sort: \n";

  for (int i=0; i<A.size(); i++) {
    cout << A[i] << " ";
  }

  cout << endl;

  return 0;
}