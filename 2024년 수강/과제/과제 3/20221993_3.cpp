#include <iostream>

using namespace std;

template <typename T>
class Node;

template <typename T>
class list;

template <typename T>
class itr;

template <typename T>
class Node {
  friend class itr<T>;
  friend class list<T>;

private:
  T data;
  Node * left;
  Node * right;

public:
  Node(T rkqt) : data(rkqt), left(NULL), right(NULL) {}
};

template <typename T>
class list {
private:
  Node<T> * first;
 
public:
   // 1번 구현 
  list() : first(NULL) {}

  // 2번 구현 
  ~list() { 
    while (first) {
      Node<T> * temp = first;
      first = first->right;
      delete temp;
    }
  }

  // 3번 구현 
  itr<T> begin() {
    return itr<T>(first);
  }

  // 4번 구현 
  itr<T> end() {
    return itr<T>(NULL);
  }

  // 5번 구현 
  void insert(const T& rkqt, int i) {
    Node<T> * newNode = new Node<T>(rkqt);

    if (!first) {
      first = newNode;
      return;
    }

    Node<T> * current = first;

    for (int j = 0; j < i && current->right; ++j) {
      current = current->right;
    }

    newNode->right = current->right;
    newNode->left = current;

    if (current->right) {
      current->right->left = newNode;
    }

    current->right = newNode;
  }

  // 6번 구현  
  void deletee(int i) {
    if (!first)
      return ;

    Node<T> * current = first;

    for (int j = 0; j < i && current; ++j) {
      current = current->right;
    }

    if (!current)
      return ;

    if (current->left) {
      current->left->right = current->right;
    }

    if (current->right) {
      current->right->left = current->left;
    }

    if (current == first) {
      first = first->right;
    }

    delete current;
  }
};

template <typename T>
class itr {
private:
  Node<T> * current;

public:
  itr(Node<T> * ptr) : current(ptr) {}

  // 7번 구현  
  itr & operator++() {
    if (current)
      current = current->right;

    return * this;
  }
  
  // 7번 구현 
  itr operator++(int) {
    itr temp = * this;

    if (current)
      current = current->right;

    return temp;
  }

  // 7번 구현 
  itr & operator--() {
    if (current)
      current = current->left;

    return * this;
  }

  // 7번 구현 
  itr operator--(int) {
    itr temp = * this;
   
    if (current)
      current = current->left;
   
    return temp;
  }

  T & operator*() {
    return current->data;
  }

  T * operator->() {
    return & (current->data);
  }

  bool operator==(const itr & other) const {
    return current == other.current;
  }

  bool operator!=(const itr & other) const {
    return current != other.current;
  }
};

class Number {
private:
  int num;

public:
  Number(int n) : num(n) {}

  void ShowData() {
    cout << num << endl;
  }

  Number * operator->() {
    return this;
  }

  Number & operator*() {
    return * this;
  }
};

int main() {
  list<Number> list00;

  // �뀒�뒪�듃 1
  for (int i = 1; i <= 9; ++i) {
    list00.insert(Number(i), i - 1);
  }

  // �뀒�뒪�듃 2
  for (itr<Number> it00 = list00.begin(); it00 != list00.end(); ++it00) {
    it00->ShowData();
  }
  cout << endl;

  // �뀒�뒪�듃 3
  list00.insert(Number(100), 2);

  // �뀒�뒪�듃 4
  for (itr<Number> it00 = list00.begin(); it00 != list00.end(); ++it00) {
    it00->ShowData();
  }
  cout << endl;

  // �뀒�뒪�듃 5
  list00.deletee(5);

  // �뀒�뒪�듃 6
  for (itr<Number> it00 = list00.begin(); it00 != list00.end(); ++it00) {
    it00->ShowData();
  }
  cout << endl;

  // �뀒�뒪�듃 7
 
  // �뀒�뒪�듃 8
  for (itr<Number> it00 = --list00.end(); it00 != --list00.begin(); --it00) {
    it00->ShowData();
  }
  cout << endl;

  return 0;
  }
