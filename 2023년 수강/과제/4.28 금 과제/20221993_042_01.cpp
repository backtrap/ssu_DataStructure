#include <iostream>

inline void error(char* str) {
  std::cerr << str << std::endl;
  exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue {
  int front;
  int rear;
  int data[MAX_QUEUE_SIZE];
public :
  CircularQueue() {
    front = rear = 0;
  }
  ~CircularQueue() {
  }
  bool isEmpty() {
    return front == rear;
  }

  bool isFull() {
    return (rear + 1) % MAX_QUEUE_SIZE == front;    
  }

  void enqueue(int val) {
    if (isFull())
      error("  error: 큐가 포화상태입니다\n");
    else {
      rear = (rear + 1) % MAX_QUEUE_SIZE;
      data[rear] = val;
    }
  }

  int dequeue() {
    if (isEmpty())
      error("  Error: 큐가 공백상태입니다\n");
    else {
      front = (front + 1) % MAX_QUEUE_SIZE;
      return data[front];
    }
  }

  int peek() {
    if (isEmpty())
      error("  ERROR: 큐가 공백상태입니다\n");
    else
      return data[(front + 1) % MAX_QUEUE_SIZE];
  }

  void display() {
    std::cout << "큐 내용 : ";
    int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
    for (int i = front + 1; i <= maxi; i++)
      std::cout << "[" << data[i%MAX_QUEUE_SIZE] << "] ";
    std::cout << std::endl;
  }
};

int main() {
  CircularQueue que;
  for (int i = 1; i < 10; i++)
    que.enqueue(i);
  que.display();
  que.dequeue();
  que.dequeue();
  que.dequeue();
  que.display();
  return 0;
}