//---------------------------------------------------------------------------

#pragma once
#include <vcl.h>
#ifndef StackH
#define StackH
//---------------------------------------------------------------------------
#endif

template<typename T>
class Node {
public:
	Node* pNext;									//указатель на след.элемент
	T data;											//данные элемента

	Node(T data = T(), Node *pNext = nullptr) {		//по умолчанию указатель на след. элемент = nullptr
		this->data = data;
		this->pNext = pNext;
	}
};

template<typename T>
class Stack {
public:
	int key;
	bool isNull;

	Stack();
	~Stack();
	void Clear();						//удаление стека
	int GetSize() { return Size; }
	void Pop();							//удаление верхнего элемента стека
	void Push(T data);					//добавление элемента на вершину стека
	T& Top();							//показать верхний элемент стека
	bool IsEmpty();						//проверка на наличие элементов стека
	void Show(TMemo *Memo);

private:
	int Size;							//размер стека
	Node<T>* head;						//указатель на начало стека
};


template<typename T>
Stack<T>::Stack() {
	Size = 0;
	isNull = true;
	head = nullptr;
}

template<typename T>
Stack<T>::~Stack() {
	Clear();
}

template<typename T>
void Stack<T>::Clear()
{
	while (Size) {
		Pop();
	}
	isNull = true;
}

template<typename T>
void Stack<T>::Pop()
{
	Node<T>* temp = head;

	head = head->pNext;
	delete temp;
	Size--;

	if (!Size)
		isNull = true;
}

template<typename T>
void Stack<T>::Push(T data)
{
	head = new Node<T>(data, head);
	Size++;
	isNull = false;
}

template<typename T>
T& Stack<T>::Top()
{
	return head->data;
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return Size ? false : true;
}

template <typename T>
void Stack<T>::Show(TMemo *Memo)
{
    Memo->Clear();

	if(isNull) return;

	Node<T> *current = head;

	while (current)
	{
		Memo->Lines->Add(IntToStr(current->data) + " ");
		current = current->pNext;
	}
}
