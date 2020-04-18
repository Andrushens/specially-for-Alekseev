//---------------------------------------------------------------------------

#pragma once
#ifndef StackH
#define StackH
//---------------------------------------------------------------------------
#endif

template<typename T>
class Node {
public:
	Node* pNext;//указатель на след.элемент
	T data;//данные элемента

	Node(T data = T(), Node *pNext = nullptr) {//по умолчанию указатель на след. элемент = nullptr
		this->data = data;
		this->pNext = pNext;
	}
};

template<typename T>
class Stack {
public:
	Stack();
	~Stack();
	void clear();//удаление стека
	int GetSize() { return Size; }
	void pop();//удаление верхнего элемента стека
	void push(T data);//добавление элемента на вершину стека
	T& top();//показать верхний элемент стека
	bool isEmpty();//проверка на наличие элементов стека

private:
	int Size;//размер стека
	Node<T>* head;//указатель на начало стека
};


template<typename T>
Stack<T>::Stack() {
	Size = 0;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
	clear();
}

template<typename T>
void Stack<T>::clear()
{
	while (Size) {
		pop();
	}
}

template<typename T>
void Stack<T>::pop()
{
	Node<T>* temp = head;

	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void Stack<T>::push(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
T& Stack<T>::top()
{
	return head->data;
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return Size ? false : true;
}
