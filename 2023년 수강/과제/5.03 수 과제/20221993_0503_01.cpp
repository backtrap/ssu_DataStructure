#include <iostream>
#define MAX_QUEUE_SIZE 100

inline void error(char* str) {
  std::cerr << str << std::endl;
  exit(1);
};

class CircularQueue {
protected :
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

class CircularDeque : public CircularQueue {
public :
  CircularDeque () { }
  void addRear( int val ) { enqueue(val); }
  int deleteFront( ) { return dequeue(); }
  int getFront( ) { return peek() ;}
  void addFront( int val ) {
    if ( isFull() )
      error("  error: 덱이 포화상태입니다\n");
    else {
      data[front] = val;
      front = (front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    }
  }
  int deleteRear( ) {
    if ( isEmpty() )
      error("  Error: 덱이 공백상태입니다\n");
    else {
      int ret = data[rear];
      rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
      return ret;
    }
  }
  int getRear() {
    if (isEmpty())
      error("  Error: 덱이 공백상태입니다\n");
    else return data[rear];
  }
    void display() {
      std::cout << "덱의 내용: ";
      int maxi = (front<rear) ? rear : rear+MAX_QUEUE_SIZE;
      for (int i=front+1; i<=maxi; i++)
        std::cout << "[" << data[i%MAX_QUEUE_SIZE] << "] ";
        std::cout << std::endl;
    }
};

int main()
{
  CircularDeque deq;
  for (int i=1; i<10; i++) {
    if (i%2) deq.addFront(i);
    else deq.addRear(i);
  }
  deq.display();

  deq.deleteFront();
  deq.deleteRear();
  deq.deleteFront();
  deq.display();
}