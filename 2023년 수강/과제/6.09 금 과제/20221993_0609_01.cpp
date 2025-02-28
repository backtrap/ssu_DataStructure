#include <iostream>

using namespace std;

int binarySearchIter(int list[], int key, int low, int high) {
  int middle;

  while (low<=high) {
    middle = (low+high)/2;

    if (key==list[middle])
      return middle;
    else if (key>list[middle])
      return low = middle + 1;
    else
      return high = middle - 1;
  }

  return -1;
}

int main() {
  int list[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int size = sizeof(list)/sizeof(list[0]);
  int key = 7;

  int result = binarySearchIter(list, key, 0, size-1);

  if (result!=-1)
    cout << "Element found at index :  " << result << endl;
  else
    cout << "Element not found in the array." << endl;

  return 0;
}