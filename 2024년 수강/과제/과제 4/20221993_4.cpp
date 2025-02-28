#include <iostream>

using namespace std;

template <typename T1, typename T2> class Node {
public:
  pair<T1, T2> data; // pair 구현
  Node<T1, T2> *left = nullptr;
  Node<T1, T2> *right = nullptr;

  int leftSize; // leftSize(ranking) 구현

  Node(pair<T1, T2> data02) : data(data02), leftSize(0) {}
};

template <typename T1, typename T2> class Tree {
public:
  Node<T1, T2> *root;

  Tree() : root(nullptr) {}

  bool isEmpty() { return root == nullptr; }

  bool isLeaf(Node<T1, T2> *node) {
    return node->left == nullptr && node->right == nullptr;
  }

  // insert 함수
  void insert(pair<T1, T2> p) {
    Node<T1, T2> *node = new Node<T1, T2>(p);

    if (isEmpty())
      root = node;

    else
      insert(root, node);

    updateLeftSize(root); // 매 노드 추가 시 leftSize 값 갱신
  }

  void insert(Node<T1, T2> *root02, Node<T1, T2> *node02) {
    if (node02->data.first == root02->data.first)
      return;
    else if (node02->data.first < root02->data.first) {
      if (root02->left == nullptr)
        root02->left = node02;
      else
        insert(root02->left, node02);
    } else {
      if (root02->right == nullptr)
        root02->right = node02;
      else
        insert(root02->right, node02);
    }
  }

  // leftSize를 변경하는 함수
  int updateLeftSize(Node<T1, T2> *node) {
    if (node == nullptr)
      return 0;

    if (node->left == nullptr) {
      node->leftSize = 0;
    } else {
      node->leftSize = updateLeftSize(node->left) + 1;
    }

    updateLeftSize(node->right);

    return node->leftSize;
  }

  // inorder 함수
  void inorder() { inorder(root); }

  void inorder(Node<T1, T2> *node) {
    if (node != nullptr) {
      inorder(node->left);
      cout << "번호는 : " << node->data.first << endl;
      cout << "점수는 : " << node->data.second << endl << endl;
      inorder(node->right);
    }
  }

  // delete 함수
  // delete가 키워드라서 함수명으로 사용을 못해 deletee로 사용했습니다.
  void deletee(int num) {
    deletee(root, num);

    updateLeftSize(root);
  }

  void deletee(Node<T1, T2> *&node, int num) {
    if (node == nullptr)
      return;

    if (num < node->data.first)
      deletee(node->left, num);
    else if (num > node->data.first)
      deletee(node->right, num);
    else {
      if (node->left == nullptr) {
        Node<T1, T2> *temp = node->right;
        delete node;
        node = temp;
      } else if (node->right == nullptr) {
        Node<T1, T2> *temp = node->left;
        delete node;
        node = temp;
      } else {
        Node<T1, T2> *newright = node->right;
        while (newright->left != nullptr) {
          newright = newright->left;
        }
        node->data = newright->data;
        deletee(node->right, newright->data.first);
      }
    }
  }

  // get 함수
  void get(T1 key) { get(key, root); }

  void get(T1 key, Node<T1, T2> *node) {
    if (node == nullptr) {
      cout << "해당 번호는 없습니다." << endl;
     
      return;
    }  
    else {
      if (key < node->data.first)
        get(key, node->left);
      else if (node->data.first == key) {
        cout << "번호가 " << key << "인 노드를 찾았습니다." << endl;
        cout << "번호는 : " << node->data.first << endl;
        cout << "점수는 : " << node->data.second << endl << endl;

        return;
      }
      else if (key > node->data.first) {
        get(key, node->right);
      }
    }

    return ;
  }

  // rank 함수
  void rank(int num) { rank(num, root); }

  void rank(int num, Node<T1, T2> *node) {
    static int count = 0;

    if (node != nullptr) {
      rank(num, node->left);
      if (num == ++count) {
        cout << num << "번째로 작은 노드의" << endl;
        cout << "번호는 : " << node->data.first << endl;
        cout << "점수는 : " << node->data.second << endl << endl;

        count = 0;
      }
      rank(num, node->right);
    }
  }
};

int main() {
  Tree<int, int> tree;

  // 테스트 1
  tree.insert(make_pair(33, 90));
  tree.insert(make_pair(50, 73));
  tree.insert(make_pair(43, 99));
  tree.insert(make_pair(11, 82));
  tree.insert(make_pair(24, 78));
  tree.insert(make_pair(46, 96));
  tree.insert(make_pair(1, 72));
  tree.insert(make_pair(8, 88));
  tree.insert(make_pair(36, 77));
  tree.insert(make_pair(56, 93));
  tree.insert(make_pair(53, 82));
  tree.insert(make_pair(59, 100));

  // 테스트 2
  tree.inorder();

  // 테스트 3
  tree.deletee(50);

  // 테스트 4
  tree.inorder();

  // 테스트 5
  tree.deletee(8);

  // 테스트 6
  tree.inorder();

  // 테스트 7
  tree.deletee(56);

  // 테스트 8
  tree.inorder();

  // 테스트 9
  tree.get(43);

  // 테스트 10
  tree.rank(5);

  return 0;
}

