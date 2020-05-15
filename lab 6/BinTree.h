//---------------------------------------------------------------------------

#ifndef BinTreeH
#include <math.h>
#include <vcl.h>
#define BinTreeH
//---------------------------------------------------------------------------
#endif

template<typename T>
class Node {
public:
	int key;
	T data;
	Node *left;
	Node *right;

	Node(int key, T data)
	{
		this->key = key;
		this->data = data;
		left = right = nullptr;
	}

	~Node() {
		delete key;
		delete data;
		delete left;
		delete right;
	}
};


template<typename T>
class BinTree {
public:
	void insert(int key, T data, Node<T> **root);
	void deleteKey(int key, Node<T> **root);
	Node<T>* find(int key, Node<T>* root);
	void inOrder(Node<T> *root, TMemo *Memo);
	void preOrder(Node<T> *root, TMemo *Memo);
	void postOrder(Node<T> *root, TMemo *Memo);
	void balance(Node<T> **root);
	void makeVine(Node<T> **root);
	void balanceVine(Node<T> **root);

protected:
	void _rotateLeft(Node<T> *&parent, Node<T> *&current, Node<T> **root);
	void _rotateRight(Node<T> *&parent, Node<T> *&current, Node<T> **root);

	int _size = 0;
};

template<typename T>
void BinTree<T>::insert(int key, T data, Node<T> **node)
{
	if (*node == nullptr) {
		*node = new Node<T>(key, data);
		(*node)->left = (*node)->right = nullptr;
		_size++;
	}
	else {
		if ((*node)->key > key) {
			insert(key, data, &(*node)->left);
		}
		else if((*node)->key < key){
			insert(key, data, &(*node)->right);
		}
	}
}

template<typename T>
void BinTree<T>::deleteKey(int key, Node<T> **root)
{
	Node<T> *current = *root;
	Node<T> *parent = nullptr;

	while (current != nullptr) {
		if (current->key == key) {
			_size--;
			break;
		}
		else {
			parent = current;

			if (current->key > key) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
	}
	if (current == nullptr) return;

	if (current->right == nullptr) {
		if (parent == nullptr) {
			*root = current->left;
		}
		else {
			if (current == parent->left) {
				parent->left = current->left;
			}
			else {
				parent->right = current->left;
			}
		}
	}
	else {
		Node<T> *leftMost = current->right;
		parent = nullptr;

		while (leftMost->left != nullptr) {
			parent = leftMost;
			leftMost = leftMost->left;
		}
		if (parent != nullptr) {
			parent->left = leftMost->right;
		}
		else {
			current->right = leftMost->right;
		}
		current->key = leftMost->key;
		current->data = leftMost->data;
	}
}

template<typename T>
Node<T>* BinTree<T>::find(int key, Node<T> *root)
{
	Node<T> *current = root;
	while (current != nullptr) {
		if (current->key == key)
			return current;
		if (current->key < key)
			current = current->right;
		else
			current = current->left;
	}
	return nullptr;
}

template<typename T>
void BinTree<T>::inOrder(Node<T>* root, TMemo *Memo)
{
	if (root) {
		inOrder(root->left, Memo);
		Memo->Lines->Add(IntToStr(root->key) + " - " + IntToStr(root->data));
		inOrder(root->right, Memo);
	}
}

template<typename T>
void BinTree<T>::preOrder(Node<T>* root, TMemo *Memo)
{
	if (root) {
		Memo->Lines->Add(IntToStr(root->key) + " - " + IntToStr(root->data));
		preOrder(root->left, Memo);
		preOrder(root->right, Memo);
	}
}

template<typename T>
void BinTree<T>::postOrder(Node<T>* root, TMemo *Memo)
{
	if (root) {
		postOrder(root->left, Memo);
		postOrder(root->right, Memo);
		Memo->Lines->Add(IntToStr(root->key) + " - " + IntToStr(root->data));
	}
}

template<typename T>
void BinTree<T>::balance(Node<T>** root)
{
	makeVine(root);
	balanceVine(root);
}

template<typename T>
void BinTree<T>::makeVine(Node<T> **root)
{
	Node<T> *current = *root;
	Node<T> *parrent = nullptr;

	while (current != nullptr) {
		if (current->right == nullptr) {
			parrent = current;
			current = current->left;
		}
		else {
			_rotateLeft(parrent, current, root);
		}
	}
}

template<typename T>
void BinTree<T>::balanceVine(Node<T>** root)
{
	Node<T> *black = nullptr;
	Node<T> *red = *root;

	for (int n = 1; n < log(_size) / log(2) - 0.5; n++) {
		for (int i = 0; i < _size / pow(2, n) - 1; i++) {
			_rotateRight(black, red, root);
			black = red;
			red = red->left;
		}
		black = nullptr;
		red = *root;
	}
}

template<typename T>
void BinTree<T>::_rotateLeft(Node<T> *&parrent, Node<T> *&current, Node<T> **root)
{
	Node<T> *subR = current->right;
	Node<T> *subRL = subR->left;

	current->right = subRL;
	subR->left = current;
	if (parrent != nullptr) {
		parrent->left = subR;
	}
	else {
		*root = subR;
	}
	current = subR;
}

template<typename T>
void BinTree<T>::_rotateRight(Node<T> *&parrent, Node<T> *&current, Node<T> **root)
{
	Node<T> *subL = current->left;
	Node<T> *subLR = subL->right;

	current->left = subLR;
	subL->right = current;
	if (parrent != nullptr) {
		parrent->left = subL;
	}
	else {
		*root = subL;
	}
	current = subL;
}
