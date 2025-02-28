#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template <typename T>
void ChangeSize1D(T * & a, const int oldSize, const int newSize) {
  if (newSize < 0) throw "New length must be >= 0";

  T * temp = new T[newSize];

  int number = min(oldSize, newSize);

  copy(a, a + number, temp);

  delete [] a;

  a = temp;
}

template <class T>
class Stack {
private:
  T* stack;
  int top;
  int capacity;

public:
  Stack(int stackCapacity = 3) : capacity(stackCapacity) {
      if (capacity < 1) throw "Stack capacity must be > 0";

      stack = new T[capacity]();
      top = -1;
    }

  bool IsEmpty() const { return top == -1; }

  T& Top() const {
      if (IsEmpty()) throw "Stack is empty";
      return stack[top];
  }

  void Push(const T& item) {
    if (top == capacity - 1) {
      ChangeSize1D(stack, capacity, 2 * capacity);
        capacity *= 2;
    }

     stack[++top] = item;
  }

  void Pop() {
    if (IsEmpty()) throw "Stack is empty. Cannot delete.";

     --top;
  }

  ~Stack() {
    delete[] stack;
  }
};

class Token {
public:
  char* value;
  int type; // 연산자면 1, 소괄호 (이면 2, 소괄호 )이면 3
  int isp;  // #은 0, */%는 1, +-는 2
  // 둘 다 초기값은 -1

  Token() : value(nullptr), type(-1), isp(-1) {}

  Token(const Token& other) {
    value = new char[strlen(other.value) + 1];
      strcpy(value, other.value);
      type = other.type;
      isp = other.isp;
  }

  Token(const char data) : type(-1), isp(-1) {
    value = new char[2];
    value[0] = data;
    value[1] = '\0';

    if (data == '(')
      type = 2;
    else if (data == ')')
      type = 3;
    else
      type = 1;

    if (data == '#')
      isp = 0;
    else if (data == '*' || data == '/' || data == '%')
      isp = 1;
    else if (data == '+' || data == '-')
      isp = 2;
    }

  Token & operator=(const Token & other) {
    if (this != & other) {
      delete[] value;
      value = new char[strlen(other.value) + 1];
      strcpy(value, other.value);
      type = other.type;
      isp = other.isp;
    }
   
    return * this;
  }

  ~Token() {
    delete[] value;
  }
};



void Postfix(const char * str) {
  Stack<Token> stack;

  Token first('#');
  stack.Push(first);

  int length = strlen(str);

  for (int i = 0; i < length; i++) {
    int isp = 0;
    if (str[i] == '+' || str[i] == '-')
      isp = 2;
    else if (str[i] == '*' || str[i] == '/' || str[i] == '%')
      isp = 1;
     
    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
      Token temp(str[i]);
      stack.Push(temp);
    }
    else if (str[i] == '(') {
      Token temp(str[i]);
      stack.Push(temp);
    }
    else if (str[i] == ')') {
      while (!stack.IsEmpty()) {
        if (stack.Top().type != 2) {
        cout << stack.Top().value;
        stack.Pop();
        }
        else {
          stack.Pop(); // ( 제거
          break;
        }
      }
    }
    else if (stack.Top().isp < isp) {
      cout << stack.Top().value;
      cout << str[i];
    }
    else {
      cout << str[i];
    }
  }

  while (!stack.IsEmpty() && stack.Top().value[0] != '#') {
    cout << stack.Top().value;
    stack.Pop();
  }
}


int main(void) {
  cout << "중위 표기식을 입력하세요 : ";
  char * str = new char[100];
  cin >> str;
  Postfix(str);
  cout << endl;

  return 0;
}


