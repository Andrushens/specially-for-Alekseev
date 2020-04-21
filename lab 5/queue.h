//---------------------------------------------------------------------------
#pragma once
#ifndef queueH
#define queueH
//---------------------------------------------------------------------------
#endif

template<typename T>
class Node {
public:
	Node* pNext;
	T data;

	Node(T data = T(), Node *pNext = nullptr) {
		this->data = data;
		this->pNext = pNext;
	}
};

template<typename T>
class Queue {
public:
	Queue();
	~Queue();

	void push(T data);//добавить элемент в конец
	void clear();//очистить очередь
	int GetSize() { return Size; }
	void pop();//удалить элемент из начала
	T& front();//показать первый элемент
	T& back();//показать последний
	bool isEmpty();

protected:
	int Size;
	Node<T>* head;//указатель на начало
};


template<typename T>
Queue<T>::Queue() {
	Size = 0;
	head = nullptr;
}

template<typename T>
Queue<T>::~Queue() {
	clear();
}

template<typename T>
void Queue<T>::push(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void Queue<T>::clear()
{
	while (Size) {
		pop();
	}
}

template<typename T>
void Queue<T>::pop()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
T& Queue<T>::front()
{
	if (head != nullptr)
		return head->data;
}

template<typename T>
T& Queue<T>::back()
{
	if(head != nullptr) {
		Node<T>* current = head;

		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		return current->data;
	}
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return Size? false : true;
}
