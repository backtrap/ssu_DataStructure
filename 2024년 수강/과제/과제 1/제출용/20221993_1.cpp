#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// swap() 함수
template <class T> void swap(T &a, T &b) {
  T temp;

  temp = a;
  a = b;
  b = temp;
}

// 정렬 함수
template <class T> void SelectionSort(T *a, const int n) {
  for (int i = 0; i < n; i++) {
    int j = i;

    for (int k = i + 1; k < n; k++)
      if (*a[k] < *a[j])
        j = k;

    swap(a[i], a[j]);
  }
}

// Rectangle 객체
class Rectangle {
private:
  int x_leftUpper;
  int y_leftUpper;
  int x_rightLower;
  int y_rightLower;

public:
// 생성자
Rectangle(int x1, int y1, int x2, int y2) {
  x_leftUpper = x1;
  y_leftUpper = y1;
  x_rightLower = x2;
  y_rightLower = y2;
}

// 좌표 출력 함수
void getter_x_leftUpper() {
  cout << x_leftUpper << endl;
}

void getter_y_leftUpper() {
  cout << y_leftUpper << endl;
}

void getter_x_rightLower() {
  cout << x_rightLower << endl;
}

void getter_y_rightLower() {
  cout << y_rightLower << endl;
}

// 좌표 설정 함수
void setter_x_leftUpper(int num) {
  x_leftUpper = num;
}

void setter_y_leftUpper(int num) {
  y_leftUpper = num;
}

void setter_x_rightLower(int num) {
  x_rightLower = num;
}

void setter_y_rightLower(int num) {
  y_rightLower = num;
}

// 넓이 계산 함수
int area() {
  int width = x_rightLower - x_leftUpper;
  int height = y_leftUpper - y_rightLower;

  return width * height;
}

// 연산자 오버로딩 <
bool operator<(Rectangle &ref) {
  return area() < ref.area();  
}

// 연산자 오버로딩 =
bool operator=(Rectangle &ref) {
  return area()==ref.area();
}
};

int main(void) {
  Rectangle * rectangle[10];

  rectangle[0] = new Rectangle(1, 7, 8, 3);
  rectangle[1] = new Rectangle(2, 6, 7, 4);
  rectangle[2] = new Rectangle(3, 10, 9, 5);
  rectangle[3] = new Rectangle(4, 7, 9, 6);
  rectangle[4] = new Rectangle(5, 8, 7, 7);
  rectangle[5] = new Rectangle(6, 9, 12, 8);
  rectangle[6] = new Rectangle(7, 10, 9, 9);
  rectangle[7] = new Rectangle(8, 11, 18, 10);
  rectangle[8] = new Rectangle(9, 7, 21, 3);
  rectangle[9] = new Rectangle(10, 6, 21, 4);

  for (int i = 0; i < 10; i++) {
    cout << rectangle[i]->area() << endl;
  }

  cout<<"\n\n";

  SelectionSort(rectangle, 10);

  for (int i = 0; i < 10; i++) {
    cout << (*rectangle[i]).area() << endl;
  }

  return 0;
}
