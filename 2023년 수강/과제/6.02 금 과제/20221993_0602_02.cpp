#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& A) {
  int n = A.size();

  for (int i=0; i<n; i++) {
    int key = A[i];
    int j = i - 1;

    while (j>=0&&A[j]>key) {
      A[j+1] = A[j];
      j=j-1;
    }

    A[j+1] = key;
  }
}

int main() {
  vector<int> A = {64, 34, 25, 12, 22, 11, 90};

  insertionSort(A);

  cout << "Sorted array using Insertion Sort: \n";

  for (int i=0; i<A.size(); i++)
    cout << A[i] << " ";

  cout << endl;

  return 0;
}