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
	Node* pNext;									//��������� �� ����.�������
	T data;											//������ ��������

	Node(T data = T(), Node *pNext = nullptr) {		//�� ��������� ��������� �� ����. ������� = nullptr
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
	void Clear();						//�������� �����
	int GetSize() { return Size; }
	void Pop();							//�������� �������� �������� �����
	void Push(T data);					//���������� �������� �� ������� �����
	T& Top();							//�������� ������� ������� �����
	bool IsEmpty();						//�������� �� ������� ��������� �����
	void Show(TMemo *Memo);

private:
	int Size;							//������ �����
	Node<T>* head;						//��������� �� ������ �����
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
