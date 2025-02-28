#include <iostream>

class Node {
  Node* link;
  int data;
public :
  Node(int val = 0) : data(val), link(NULL) {}
  Node* getLink() { return link; }
  void setLink(Node* next) { link = next; }
  void display() { std::cout << " <" << data << ">"; }
};

class LinkedQueue {
  Node* front;
  Node* rear;
public :
  LinkedQueue() : front(NULL), rear(NULL) {}
  ~LinkedQueue() { while (isEmpty()) delete dequeue(); }
  bool isEmpty() { return front == NULL; }

  void enqueue(Node* n) {
    if (isEmpty()) front = rear = n;
    else {
      rear->setLink(n);
      rear = n;
    }
  }

  Node* dequeue() {
    if (isEmpty()) return NULL;
    Node* temp = front;
    front = front->getLink();
    if (front==NULL) rear = NULL;
    return temp;
  }

  Node* peek() {return front; }
  void display() {
    std::cout << "[큐 내용] :";
    for (Node* p = front; p!= NULL; p = p->getLink())
      p->display();
    std::cout << std::endl;
  }
};

int main() {
  LinkedQueue que;
  for (int i=1; i<10; i++)
    que.enqueue(new Node(i));
  que.display();
  delete que.dequeue();
  delete que.dequeue();
  delete que.dequeue();
  que.display();
  return 0;
}