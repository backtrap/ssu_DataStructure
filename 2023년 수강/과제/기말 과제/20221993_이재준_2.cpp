/* 
총 5문제이며 6점 만점입니다. 

제출시 파일 명을 "학번_이름_2"으로 변경하여 결과 화면 캡쳐와 함께 압축하지 말고 제출하세요. 

파일명 미 변경 혹은 명세에 따라 작성하여 실행한 결과 화면을 첨부 하지 않을 시 0점 처리 됩니다.

또한 제출한 코드가 컴파일 혹은 실행이 되지 않을 경우 역시 0점 처리 됩니다.

주어진 테스트 코드는 예시이며 채점 시 사용하는 코드와 다소 상이할 수 있습니다.

** 주석 처리 된 부분 이외에 코드 영역 변경시 점수에 불이익이 있을 수 있습니다. **
*/

#include <iostream>
#include <utility>
using namespace std;

template <class K, class E>
class BinaryTree;

template <class K, class E>
class TreeNode
{
	friend class BinaryTree<K, E>;

private:
	TreeNode<K, E> *left;
	TreeNode<K, E> *right;
	pair<K, E> data;

public:
	TreeNode(pair<K, E> a)
	{
		left = 0;
		right = 0;
		data = a;
	}
};

template <class K, class E>
class BinaryTree
{
private:
	TreeNode<K, E> *root;

public:
	void Visit(TreeNode<K, E> *currentNode) { 	cout << currentNode->data.second << " "; }
	
    void Insert(const pair<K, E> &thePair);         //1)

    void Preorder();                                //2)
	void Preorder(TreeNode<K, E> *currentNode);     //2)
	
	void Inorder();                                 //3)
	void Inorder(TreeNode<K, E> *currentNode);      //3)
	
	void Postorder();                               //4)
	void Postorder(TreeNode<K, E> *currentNode);    //4)
	
	pair<K, E> *Get(const K &k);                    //5)
	pair<K, E> *Get(TreeNode<K, E> *p, const K &k); //5)
};

//1) (2점)
template <class K, class E>
void BinaryTree<K, E>::Insert(const pair<K, E> &thePair)
{
	/*ptr
	- 삽입할 노드를 가리킬 포인터 초기화	
	- 트리를 탐색하여 삽입할 위치 찾기
	while ( 트리 순회 조건 )
	{
		- 키 비교하여 왼쪽 또는 오른쪽 자식으로 이동
		else
	    - 동일한 키를 가진 노드가 이미 존재하는 경우 데이터 업데이트
	}   
    - 새로운 노드 생성

	if ( 트리가 비어 있지 않은 경우 )
	{
		- 삽입할 위치에 맞게 부모 노드의 왼쪽 또는 오른쪽 자식으로 연결
	}
	else
		- 새 노드를 루트에 지정 
    */

	TreeNode<K, E> *ptr = new TreeNode<K, E>(thePair);

	TreeNode<K, E> *current = root;
	TreeNode<K, E> *parent = nullptr;

	while (current!=nullptr)
	{
		if (thePair.first<current->data.first)
		{
			parent = current;
			current = current->left;
		}
		else if (thePair.first>current->data.first)
		{
			parent = current;
			current = current->right;
		}
		else
		{
			current->data.second = thePair.second;
			return ;
		}
	}

	ptr->left = nullptr;
	ptr->right = nullptr;
	ptr->data = thePair;

	if (parent!=nullptr)
	{
		if (thePair.first<parent->data.first)
		{
			parent->left = ptr;
		}
		else
		{
			parent->right = ptr;
		}
	}
	else
	{
		root = ptr;
	}
}
//--------------------------------------------------------------------------------------

//2) (1점)
template <class K, class E>
void BinaryTree<K, E>::Preorder() 
{
    // Preorder Driver
    // workhorse(rootnode) 호출
  Preorder(root);
}

template <class K, class E>
void BinaryTree<K, E>::Preorder(TreeNode<K, E> *currentNode) 
{
    /* Preorder Workhorse
    if (현재 노드가 존재하는 경우)
	{
		- 현재 노드 방문
		- 왼쪽 서브트리를 전위 순회
		- 오른쪽 서브트리를 전위 순회
	}
    */
/* Preorder Workhorse */
  if (currentNode!=nullptr) {
      Visit(currentNode);
      
      Preorder(currentNode->left);
      
      Preorder(currentNode->right);
  }  
}
//--------------------------------------------------------------------------------------

//3) (1점)
template <class K, class E>
void BinaryTree<K, E>::Inorder() 
{
    // Inorder Driver
    // workhorse(rootnode) 호출
  Inorder(root);
}

template <class K, class E>
void BinaryTree<K, E>::Inorder(TreeNode<K, E> *currentNode)
{
	/* Inorder Workhorse
    if (현재 노드가 존재하는 경우)
	{
		- 왼쪽 서브트리를 중위 순회
		- 현재 노드 방문
		- 오른쪽 서브트리를 중위 순회
	}
    */
  if (currentNode!=nullptr) {
    Inorder(currentNode->left);    
    Visit(currentNode);            
    Inorder(currentNode->right);   
  }
}
//--------------------------------------------------------------------------------------

//4) (1점)
template <class K, class E>
void BinaryTree<K, E>::Postorder()
{
    // Postorder Driver
    // workhorse(rootnode) 호출
  Postorder(root);
}

template <class K, class E>
void BinaryTree<K, E>::Postorder(TreeNode<K, E> *currentNode)
{
	/* Postorder Workhorse
    if (현재 노드가 존재하는 경우)
	{
        // 왼쪽 서브트리를 후위 순회
		// 오른쪽 서브트리를 후위 순회
		// 현재 노드 방문
	}
    */
    if (currentNode!=nullptr) {
      Postorder(currentNode->left);   
      Postorder(currentNode->right);  
      Visit(currentNode);             
  }
}
//--------------------------------------------------------------------------------------

//5) (1점)
template <class K, class E>
pair<K, E> *BinaryTree<K, E>::Get(const K &k)
{
    // Get Driver
    // workhorse(키값 k) 호출
  return Get(root, k);
}

template <class K, class E>
pair<K, E> *BinaryTree<K, E>::Get(TreeNode<K, E> *p, const K &k)
{
    /*
    - 현재 노드가 존재하지 않는 경우 예외 처리	
	- 키 비교하여 왼쪽 또는 오른쪽 서브트리로 이동
	- 노드를 찾은 경우 데이터 반환
	*/
  if (p==nullptr) {
    throw "Node not found.";
  }
 
  if (k<p->data.first) {
    return Get(p->left, k);
  }
  else if (k>p->data.first) {
    return Get(p->right, k);
  }
  else {
    return &(p->data);
  }
}
//--------------------------------------------------------------------------------------

int main()
{
	BinaryTree<int, int> tree = BinaryTree<int, int>();
	cout << "Insert TreeNode 8,4,9,2,1,6,3,5,7" << endl;
	tree.Insert(pair<int, int>(8, 88));
	tree.Insert(pair<int, int>(4, 44));
	tree.Insert(pair<int, int>(9, 99));
	tree.Insert(pair<int, int>(2, 22));
	tree.Insert(pair<int, int>(1, 11));
	tree.Insert(pair<int, int>(6, 66));
	tree.Insert(pair<int, int>(3, 33));
	tree.Insert(pair<int, int>(5, 55));
	tree.Insert(pair<int, int>(7, 77));
	
	cout << endl;
	cout << "Inorder : " ;
	tree.Inorder();
	cout << endl;
	cout << "Preorder : " ;
	tree.Preorder();
	cout << endl;
	cout << "Postorder : " ;
	tree.Postorder();
	cout << endl;
	cout << endl;
	
	try
	{
		cout << "Check if Node 10 exists" << endl;
		cout << tree.Get(10)->second << endl
			 << endl;
	}
	catch (const char *err)
	{
		cout << err << endl;
	}
	cout << endl;
	try
	{
		cout << "Check if Node 9 exists" << endl;
		cout << tree.Get(9)->second << endl;
	}
	catch (const char *err)
	{
		cout << err << endl;
	}

	return 0;
}
